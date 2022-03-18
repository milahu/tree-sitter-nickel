// TODO rename tokens to match https://github.com/tweag/nickel/blob/master/src/parser/lexer.rs

// design goal: no hidden tokens -> all non-whitespace is parsed as some token
// this is useful for text-highlighting
// but may be too verbose for a syntax tree?
// -> use fields? field('fieldname', $._hidden_token)

// Precedence values are taken from lalrpop grammar
// https://github.com/tweag/nickel/blob/master/src/grammar.lalrpop
// In lalrpop the highest precedence is 0.
// Higher numbers imply a lower precedence. In tree-sitter however, a high
// number implies a high precedence. To solve this issue, while keeping
// the numbers the same, all precedence values are negated.
const PREC = {
  Negate: -1,       // -1
  StrConcat: -2,    // "a" ++ "b"
  ArrayConcat: -2,  // [1] @ [2]
  Mult: -3,         // 1 * 2
  Div: -3,          // 1 / 2
  Modulo: -3,       // 1 % 2
  Plus: -4,         // 1 + 2
  Sub: -4,          // 1 - 2
  BoolNot: -5,      // !true
  Merge: -6,        // { a = "a" } & { b = "b" }
  RightPipe: -6,    // "Hello World" |> string.split " "
  LessThan: -7,     // 1 < 2
  LessOrEq: -7,     // 1 <= 2
  GreaterThan: -7,  // 1 > 2
  GreaterOrEq: -7,  // 1 >= 2
  Eq: -8,           // 1 == 2
  Neq: -8,          // 1 != 2
  BoolAnd: -9,      // true && false
  BoolOr: -10,      // true || false
  Arrow: -11,       // Num -> Num
}

module.exports = grammar({
  name: 'nickel',

  extras: $ => [
    /\s/,
    $.comment,
  ],

  supertypes: $ => [
    $._expression
  ],

  inline: $ => [
  ],

  externals: $ => [
    $._string_fragment,
    $._multistring_start,
    $._multistring_part_fixed,
    $._multistring_ipol_start,
    $._multistring_end,
  ],

  word: $ => $.keyword,

  conflicts: $ => [
  ],

  rules: {
    source_expression: $ => field('expression', $._expression), // TODO rename?
    _expression: $ => $._expr_function,

    // Keywords go before identifiers to let them take precedence when both are expected.
    // Test `let missing value (last)` would fail without this.
    // Workaround before https://github.com/tree-sitter/tree-sitter/pull/246
    //keyword: $ => /if|then|else|let|inherit|in|rec|with|assert/,
    keyword: $ => /if|then|else|let|in|true|false|fun|import|switch/,

    Bool: $ => /true|false/,

    // identifier, Ident
    Id: $ => /_?[a-zA-Z][_a-zA-Z0-9-]*/,

    // enum tags
    // backtick + identifier
    // note: we cannot use `seq('`', $.Id)` because that would allow whitespace after backtick
    // https://nickel-lang.org/user-manual/syntax#enum-tags
    IdEnumTag: $ => /`_?[a-zA-Z][_a-zA-Z0-9-]*/,

    // builtin functions
    // TODO are these always functions?
    // examples: %is_num% %seq% %hash% %serialize%
    // https://github.com/tweag/nickel/blob/master/stdlib/builtin.ncl
    IdBuiltinFun: $ => /%_?[a-zA-Z][_a-zA-Z0-9-]*%/,

    // `x -> Enum(Id(x))
    //Enum: $ => TODO,

    Num: $ => choice($._integer, $._float),
    _integer: $ => /[0-9]+/,
    _float: $ => /[0-9]*\.[0-9]+/,

    //path: $ => /[a-zA-Z0-9\._\-\+]*(\/[a-zA-Z0-9\._\-\+]+)+\/?/,
    //hpath: $ => /\~(\/[a-zA-Z0-9\._\-\+]+)+\/?/,
    //spath: $ => /<[a-zA-Z0-9\._\-\+]+(\/[a-zA-Z0-9\._\-\+]+)*>/,
    //uri: $ => /[a-zA-Z][a-zA-Z0-9\+\-\.]*:[a-zA-Z0-9%\/\?:@\&=\+\$,\-_\.\!\~\*\']+/,

    _expr_function: $ => choice(
      $.function,
      //$.assert,
      //$.with,
      $.let,
      $._expr_if // TODO?
    ),

    function: $ => seq(
      'fun',
      choice(
        seq(field('universal', $.Id), '=>', field('body', $._expr_function)),
        //seq(field('formals', $.formals), "=>", field('body', $._expr_function)),
        //seq(field('formals', $.formals), '@', field('universal', $.Id), '=>', field('body', $._expr_function)),
        //seq(field('universal', $.Id), '@', field('formals', $.formals), '=>', field('body', $._expr_function)),
      )
    ),

    /*
    formals: $ => choice(
      seq('{', '}'),
      seq('{', commaSep1(field('formal', $.formal)), '}'),
      seq('{', commaSep1(field('formal', $.formal)), ',', field('ellipses', $.ellipses), '}'),
      seq('{', field('ellipses', $.ellipses), '}'),
    ),
    formal: $ => seq(field("name", $.Id), optional(seq('?', field('default', $._expression)))),
    ellipses: $ => '...',
    */

    //assert: $ => seq('assert', field('condition', $._expression), ';', field('body', $._expr_function)),
    //with: $ => seq('with', field('environment', $._expression), ';', field('body', $._expr_function)),
    //let: $ => seq('let', optional($._binds), 'in', field('body', $._expr_function)), // TODO only one bind? no ; after bind
    // one or more binds, separated by comma
    //let: $ => seq('let', $._binds, 'in', field('body', $._expr_function)),
    // nickel <<< "let a=1, b=2 in a"
    // error: unexpected token , after a=1
    // only one bind
    let: $ => seq('let', $.bind, 'in', field('body', $._expr_function)),

    _expr_if: $ => choice(
      $.Ite,
      $._operator_or_recursionorfuncname
    ),

    // if then else
    Ite: $ => seq('if', field('condition', $._expression), 'then', field('consequence', $._expression), 'else', field('alternative', $._expression)),

    _operator_or_recursionorfuncname: $ => choice(
      $.UnaryOp,
      $.BinaryOp,
      $._recursion_or_funcname
    ),

    UnaryOp: $ => choice(
      ...[
        ['!', PREC.BoolNot],
        ['-', PREC.Negate],
      ].map(([operator, precedence]) =>
        prec(precedence, seq(
          field('operator', operator),
          field('argument', $._operator_or_recursionorfuncname)
        ))
      )
    ),

    BinaryOp: $ => choice(
      // left assoc.
      ...[
        ['==', PREC.Eq],
        ['!=', PREC.Neq],
        ['<', PREC.LessThan],
        ['<=', PREC.LessOrEq],
        ['>', PREC.GreaterThan],
        ['>=', PREC.GreaterOrEq],
        ['&&', PREC.BoolAnd],
        ['||', PREC.BoolOr],
        ['+', PREC.Plus],
        ['-', PREC.Sub],
        ['*', PREC.Mult],
        ['/', PREC.Div],
      ].map(([operator, precedence]) =>
      prec.left(precedence, seq(
        field('left', $._operator_or_recursionorfuncname),
        field('operator', operator),
        field('right', $._operator_or_recursionorfuncname)
      ))),
      // right assoc.
      ...[
        ['->', PREC.Arrow],
        ['&', PREC.Merge],
        ['++', PREC.StrConcat],
        ['@', PREC.ArrayConcat],
      ].map(([operator, precedence]) =>
      prec.right(precedence, seq(
        field('left', $._operator_or_recursionorfuncname),
        field('operator', operator),
        field('right', $._operator_or_recursionorfuncname)
      )))
    ),

    // TODO solve conflict between App and _expr_select
    // or conflict between App and _operator_or_recursionorfuncname?
    _recursion_or_funcname: $ => choice(
      $.App, // recurse
      $._expr_select // function name
    ),
    /*

    Unresolved conflict for symbol sequence:

      'let'  attrpath  '='  _recursion_or_funcname  •  Id  …

    Possible interpretations:

      1:  'let'  attrpath  '='  (App  _recursion_or_funcname  •  _expr_select)
      2:  'let'  attrpath  '='  (_operator_or_recursionorfuncname  _recursion_or_funcname)  •  Id  …



    _operator_or_recursionorfuncname: $ => choice(
      $.UnaryOp,
      $.BinaryOp,
      $._recursion_or_funcname
    ),

    input
    let
      y = f x
    in y

    1.
    let
      y = (f x)
    in y

    2.
    ???
    let
      y = (f x) i
    in y

    */

    App: $ => seq(field('function', $._app_function), field('argument', $._app_argument)),
    /*
    App: $ => prec(PREC.App,
      seq(field('function', $._recursion_or_funcname), field('argument', $._expr_select))
    ),
    */

    _app_function: $ => $._recursion_or_funcname,
    _app_argument: $ => $._expr_select,

    _expr_select: $ => choice(
      $.select,
      $._expr_simple
    ),

    // access
    select: $ => choice(
      seq(field('expression', $._expr_simple), '.', field('attrpath', $.attrpath)),
      seq(field('expression', $._expr_simple), '.', field('attrpath', $.attrpath), 'or', field('default', $._expr_select)),
    ),

    _expr_simple: $ => choice(
      $.Id,
      $.IdEnumTag,
      $.IdBuiltinFun,
      $.Bool,
      $.Num,
      $.Str, // string
      $.MultiStr,
      //$.path,
      //$.hpath,
      //$.spath,
      //$.uri,
      $.parenthesized,
      $.RecRecord, // "recursive record"? are there nonrecursive records in nickel?
      //$.let_record,
      //$.rec_attrset,
      $.Arr,
      $.Type,
    ),

    Type: $ => seq($._expr_simple, ':', $._type_expression),

    // FIXME make this more restrictive?
    // example: is this parse error or eval error?
    // nickel <<< '1 : "x"'
    // error: incompatible types
    _type_expression: $ => prec.left($._expr_simple),

    parenthesized: $ => seq('(', field('expression', $._expression), ')'),

    RecRecord: $ => seq('{', optional(
      $._binds,
      //seq(
      //  $._binds,
      //  //optional(','), // allow dangling comma, but not in empty record: {,} -> syntax error
      //),
    ), '}'),
    //let_record: $ => seq('let', '{', optional($._binds), '}'), // what is this...?
    //rec_attrset: $ => seq('rec', '{', optional($._binds), '}'),

    StrChunkLiteral: $ => $._string_fragment,

    StrChunk: $ => choice(
      $.StrChunkLiteral,
      $.RichTerm, // interpolation
    ),

    Str: $ => seq(
      '"',
      repeat($.StrChunk),
      /* nix:
      repeat(choice(
        $._string_fragment,
        $.interpolation,
        //$.escape_sequence // TODO
      )),
      */
      '"'
    ),

    // TODO
    //escape_sequence: $ => token.immediate(/\\(.|\s)/), // Can also escape newline.

    //MultiStrStart: $ => 'm%"',
    MultiStrStart: $ => seq('m%', $._multistring_start),
    MultiStrEnd: $ => seq('"%', $._multistring_end),

    MultiStrLiteral: $ => $._multistring_part_fixed,

    // multi string interpolation
    // aka RichTerm
    MultiStrIpol: $ => seq(
      $._multistring_ipol_start,
      field('expression', $._expression),
      '}',
    ),

    MultiStr: $ => choice(
      // level 1 multistring
      /*
      seq(
        $.MultiStrStart,
        repeat(choice(
          $.MultiStrLiteral,
          $.RichTerm, // TODO require multiple % = same number as in string delimiters
          //alias($.indented_escape_sequence, $.escape_sequence),
        )),
        '"%m'
      ),
      */
      // higher level multistring
      seq(
        $.MultiStrStart,
        repeat(choice(
          $.MultiStrLiteral,
          $.MultiStrIpol,
          /*
          seq(
            $.MultiStrIpol, // TODO this shoud be part of RichTerm
            $.RichTerm,
          ),
          */
        )),
        $.MultiStrEnd,
      ),
    ),

    //indented_escape_sequence: $ => token.immediate(/'''|''\$|''\\(.|\s)/), // Can also escape newline.

    //_binds: $ => repeat1(field('bind', choice($.bind, $.inherit, $.inherit_from))),
    //_binds: $ => repeat1(field('bind', choice($.bind))),
    // same as $.Arr
    // one or more binds
    // zero binds would be empty string -> error in tree-sitter
    //_binds: $ => commaSep1(field('bind', $.bind)),
    _binds: $ => seq(
      commaSep1(field('bind', $.bind)),
      optional(','), // allow dangling comma after last bind
    ),

    bind: $ => seq(field('attrpath', $.attrpath), '=', field('expression', $._expression)), // note: no ;
    //inherit: $ => seq('inherit', field('attrs', $.attrs_inherited), ';'),
    //inherit_from: $ =>
    //  seq('inherit', '(', field('expression', $._expression), ')', field('attrs', $.attrs_inherited_from), ';'),

    attrpath: $ => sep1(field('attr', choice(
      alias($.Id, $.attr_identifier),
      $.Str,
      $.RichTerm,
    )), "."),

    /*
    attrs_inherited: $ => repeat1(field('attr', choice(
      $.Id,
      $.Str,
      $.RichTerm,
    ))),
    */

    /*
    attrs_inherited_from: $ => repeat1(field('attr', choice(
      alias($.Id, $.attr_identifier),
      $.Str,
      $.RichTerm,
    ))),
    */

    // interpolation
    RichTerm: $ => seq('%{', field('expression', $._expression), '}'),
    // TODO require multiple %

    // baed on json grammar https://github.com/tree-sitter/tree-sitter-json
    Arr: $ => seq(
      "[",
      commaSep(field('element', $._expr_select)),
      optional(','), // allow dangling comma after last element
      "]"
    ),

    // TODO?
    comment: $ => token(choice(
      seq('#', /.*/),
      /* no multi-line comments in nickel?
      seq(
        "/*",
        repeat(choice(
          /[^*]/,
          /\*[^/]/,
        )),
        "*xxxxxxxxxxxxx/"
      )
      */
    )),
  },
});


function sep(rule, separator) {
  return optional(sep1(rule, separator));
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}

function commaSep1(rule) {
  return sep1(rule, ',');
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}
