// TODO rename tokens to match https://github.com/tweag/nickel/blob/master/src/parser/lexer.rs


const PREC = {
  //impl: 1,
  or: 2,
  and: 3,
  eq: 4,
  neq: 4,
  '<': 5,
  '>': 5,
  leq: 5,
  geq: 5,
  RecConcat: 6, // TODO rename?
  not: 7,
  '+': 8, // Plus
  ' - ': 8, // minus must be spaced. TODO allow \t \n ?
  '*': 9,
  '/': 9,
  ArrConcat: 10, // TODO rename?
  StrConcat: 10, // TODO prec?
  //'?': 11,
  negate: 12,
  //App: 12, // solve conflict between _operator_or_recursionorfuncname and App. TODO verify
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
    $.StrChunkLiteral, // _string_fragment
    $._indented_string_fragment,
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

    //Bool: $ => /true|false/, // TODO

    // identifier, Ident
    Id: $ => /_?[a-zA-Z][_a-zA-Z0-9-]*/,

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
        ['!', PREC.not],
        ['-', PREC.negate],
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
        ['==', PREC.eq],
        ['!=', PREC.neq],
        ['<', PREC['<']],
        ['<=', PREC.leq],
        ['>', PREC['>']],
        ['>=', PREC.geq],
        ['&&', PREC.and],
        ['||', PREC.or],
        //['?', PREC['?']],
        ['+', PREC['+']],
        [' - ', PREC[' - ']],
        ['*', PREC['*']],
        ['/', PREC['/']],
      ].map(([operator, precedence]) =>
      prec.left(precedence, seq(
        field('left', $._operator_or_recursionorfuncname),
        field('operator', operator),
        field('right', $._operator_or_recursionorfuncname)
      ))),
      // right assoc.
      ...[
        //['->', PREC.impl],
        ['&', PREC.RecConcat],
        ['@', PREC.ArrConcat],
        ['++', PREC.StrConcat],
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
      $.Num,
      $.StrChunks, // string
      $.indented_string,
      //$.path,
      //$.hpath,
      //$.spath,
      //$.uri,
      $.parenthesized,
      $.RecRecord, // "recursive record"? are there nonrecursive records in nickel?
      //$.let_record,
      //$.rec_attrset,
      $.Arr
    ),

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

    StrChunk: $ => choice(
      $.StrChunkLiteral, // _string_fragment
      $.RichTerm, // interpolation
    ),

    StrChunks: $ => seq(
      '"',
      repeat($.StrChunk),
      /* nix:
      repeat(choice(
        $._string_fragment,
        $.interpolation,
        //$.escape_sequence
      )),
      */
      '"'
    ),
    //escape_sequence: $ => token.immediate(/\\(.|\s)/), // Can also escape newline.

    indented_string: $ => seq(
      '%m"', // TODO allow multiple %
      repeat(choice(
        $._indented_string_fragment,
        $.RichTerm, // TODO require multiple % = same number as in string delimiters
        //alias($.indented_escape_sequence, $.escape_sequence),
      )),
      '"%m'
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
      $.StrChunks,
      $.RichTerm,
    )), "."),

    /*
    attrs_inherited: $ => repeat1(field('attr', choice(
      $.Id,
      $.StrChunks,
      $.RichTerm,
    ))),
    */

    /*
    attrs_inherited_from: $ => repeat1(field('attr', choice(
      alias($.Id, $.attr_identifier),
      $.StrChunks,
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
