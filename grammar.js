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
  Applicative: -0,  // f x
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

  supertypes: _ => [
  ],

  inline: _ => [
  ],

  externals: $ => [
    $._string_fragment,
    $._multistring_start,
    $._multistring_part_fixed,
    $._multistring_ipol_start,
    $._multistring_end,
  ],

  word: $ => $.keyword,

  conflicts: _ => [
  ],

  rules: {
    term: $ => $.uni_term,

    ////////////////////////////
    // LEXER RELATED RULES (lexer.rs)
    ////////////////////////////
    // NOTE: Nickel only has single line comments
    comment: _ => token(choice(
      seq('#', /[^\n]*/),
    )),

    keyword: _ => /if|then|else|foreall|in|let|switch|null|true|false|fun|import|merge|default|doc/,

    num_literal: _ => /[0-9]*\.?[0-9]+/,

    ident: _ => /_?[a-zA-Z][_a-zA-Z0-9-]*/,

    ////////////////////////////
    // PARSER RULES (grammar.lalrpop)
    ////////////////////////////
    uni_term: $ => choice(
      $.infix_expr,
      //annotated_infix_expr,
      //forall,
      //let_expr,
    ),

    infix_expr: $ => choice(
      prec(0, $.applicative),
      $.infix_u_op,
      $.infix_b_op,
    ),

    // Combines all InfixUOps from the lalrpop grammar
    infix_u_op: $ => choice(
      ...[
        ['!', PREC.BoolNot],
        ['-', PREC.Negate],
      ].map(([operator, precedence]) =>
        prec(precedence, seq(
          field('operator', operator),
          field('argument', $.infix_expr)
        ))
      )
    ),

    infix_b_op: $ => choice(
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
        field('left', $.infix_expr),
        field('operator', operator),
        field('right', $.infix_expr)
      ))),
      // right assoc.
      ...[
        ['->', PREC.Arrow],
        ['&', PREC.Merge],
        ['++', PREC.StrConcat],
        ['@', PREC.ArrayConcat],
      ].map(([operator, precedence]) =>
      prec.right(precedence, seq(
        field('left', $.infix_expr),
        field('operator', operator),
        field('right', $.infix_expr)
      )))
    ),

    applicative: $ => choice(
      seq("import", $.static_string),
      $.type_array,
      seq($.applicative, $.record_operand),
      // TODO
      // BOpPre?
      // NOpPre?
      $.record_operand,
    ),

    static_string: $ => choice(
      // Single line
      seq("\"", optional($.chunk_literal), "\""),
      // TODO: Multi line
      //seq("m%\"", optional($.chunk_literal), "\""),
    ),

    type_array: $ => seq("Array", $.record_operand),

    record_operand: $ => choice(
      $.atom,
      // TODO
      //$.record_operation_chain,
    ),

    atom: $ => choice(
      // TODO
      //parens($.curried_op),
      parens($.uni_term),
      $.num_literal,
      "null",
      $.bool,
      //$.str_chunks,
      $.ident,
      //seq("`", $.num_tag),
      //square(repeat($.term)),
      //$.type_atom,
    ),

    bool: _ => choice(
      "true",
      "false",
    ),

    // TODO: Replace with proper representation
    chunk_literal: _ => /[0-9a-zA-Z]*/,
			//repeat1($.chunk_literal_part),

    ////////////////// OLD
    /////////////////
    ///////////////////
    /////////////////

    //// Keywords go before identifiers to let them take precedence when both are expected.
    //// Test `let missing value (last)` would fail without this.
    //// Workaround before https://github.com/tree-sitter/tree-sitter/pull/246
    ////keyword: $ => /if|then|else|let|inherit|in|rec|with|assert/,

    //Bool: $ => /true|false/,

    //// identifier, Ident
    //Id: $ => /_?[a-zA-Z][_a-zA-Z0-9-]*/,

    //// enum tags
    //// backtick + identifier
    //// note: we cannot use `seq('`', $.Id)` because that would allow whitespace after backtick
    //// https://nickel-lang.org/user-manual/syntax#enum-tags
    //IdEnumTag: $ => /`_?[a-zA-Z][_a-zA-Z0-9-]*/,

    //// builtin functions
    //// TODO are these always functions?
    //// examples: %is_num% %seq% %hash% %serialize%
    //// https://github.com/tweag/nickel/blob/master/stdlib/builtin.ncl
    //IdBuiltinFun: $ => /%_?[a-zA-Z][_a-zA-Z0-9-]*%/,

    //// `x -> Enum(Id(x))
    ////Enum: $ => TODO,

    //Num: $ => choice($._integer, $._float),
    //_integer: $ => /[0-9]+/,
    //_float: $ => /[0-9]*\.[0-9]+/,

    ////path: $ => /[a-zA-Z0-9\._\-\+]*(\/[a-zA-Z0-9\._\-\+]+)+\/?/,
    ////hpath: $ => /\~(\/[a-zA-Z0-9\._\-\+]+)+\/?/,
    ////spath: $ => /<[a-zA-Z0-9\._\-\+]+(\/[a-zA-Z0-9\._\-\+]+)*>/,
    ////uri: $ => /[a-zA-Z][a-zA-Z0-9\+\-\.]*:[a-zA-Z0-9%\/\?:@\&=\+\$,\-_\.\!\~\*\']+/,

    //_expr_function: $ => choice(
    //  $.function,
    //  //$.assert,
    //  //$.with,
    //  $.let,
    //  $._expr_if // TODO?
    //),

    //function: $ => seq(
    //  'fun',
    //  choice(
    //    seq(field('universal', $.Id), '=>', field('body', $._expr_function)),
    //    //seq(field('formals', $.formals), "=>", field('body', $._expr_function)),
    //    //seq(field('formals', $.formals), '@', field('universal', $.Id), '=>', field('body', $._expr_function)),
    //    //seq(field('universal', $.Id), '@', field('formals', $.formals), '=>', field('body', $._expr_function)),
    //  )
    //),

    ///*
    //formals: $ => choice(
    //  seq('{', '}'),
    //  seq('{', commaSep1(field('formal', $.formal)), '}'),
    //  seq('{', commaSep1(field('formal', $.formal)), ',', field('ellipses', $.ellipses), '}'),
    //  seq('{', field('ellipses', $.ellipses), '}'),
    //),
    //formal: $ => seq(field("name", $.Id), optional(seq('?', field('default', $._expression)))),
    //ellipses: $ => '...',
    //*/

    ////assert: $ => seq('assert', field('condition', $._expression), ';', field('body', $._expr_function)),
    ////with: $ => seq('with', field('environment', $._expression), ';', field('body', $._expr_function)),
    ////let: $ => seq('let', optional($._binds), 'in', field('body', $._expr_function)), // TODO only one bind? no ; after bind
    //// one or more binds, separated by comma
    ////let: $ => seq('let', $._binds, 'in', field('body', $._expr_function)),
    //// nickel <<< "let a=1, b=2 in a"
    //// error: unexpected token , after a=1
    //// only one bind
    //let: $ => seq('let', $.bind, 'in', field('body', $._expr_function)),

    //_expr_if: $ => choice(
    //  $.Ite,
    //  $._operator_or_recursionorfuncname
    //),

    //// if then else
    //Ite: $ => seq('if', field('condition', $._expression), 'then', field('consequence', $._expression), 'else', field('alternative', $._expression)),

    //_operator_or_recursionorfuncname: $ => choice(
    //  $.UnaryOp,
    //  $.BinaryOp,
    //  $._recursion_or_funcname
    //),

    //UnaryOp: $ => choice(
    //  ...[
    //    ['!', PREC.BoolNot],
    //    ['-', PREC.Negate],
    //  ].map(([operator, precedence]) =>
    //    prec(precedence, seq(
    //      field('operator', operator),
    //      field('argument', $._operator_or_recursionorfuncname)
    //    ))
    //  )
    //),

    //BinaryOp: $ => choice(
    //  // left assoc.
    //  ...[
    //    ['==', PREC.Eq],
    //    ['!=', PREC.Neq],
    //    ['<', PREC.LessThan],
    //    ['<=', PREC.LessOrEq],
    //    ['>', PREC.GreaterThan],
    //    ['>=', PREC.GreaterOrEq],
    //    ['&&', PREC.BoolAnd],
    //    ['||', PREC.BoolOr],
    //    ['+', PREC.Plus],
    //    ['-', PREC.Sub],
    //    ['*', PREC.Mult],
    //    ['/', PREC.Div],
    //  ].map(([operator, precedence]) =>
    //  prec.left(precedence, seq(
    //    field('left', $._operator_or_recursionorfuncname),
    //    field('operator', operator),
    //    field('right', $._operator_or_recursionorfuncname)
    //  ))),
    //  // right assoc.
    //  ...[
    //    ['->', PREC.Arrow],
    //    ['&', PREC.Merge],
    //    ['++', PREC.StrConcat],
    //    ['@', PREC.ArrayConcat],
    //  ].map(([operator, precedence]) =>
    //  prec.right(precedence, seq(
    //    field('left', $._operator_or_recursionorfuncname),
    //    field('operator', operator),
    //    field('right', $._operator_or_recursionorfuncname)
    //  )))
    //),

    //// TODO solve conflict between App and _expr_select
    //// or conflict between App and _operator_or_recursionorfuncname?
    //_recursion_or_funcname: $ => choice(
    //  $.App, // recurse
    //  $._expr_select // function name
    //),
    ///*

    //Unresolved conflict for symbol sequence:

    //  'let'  attrpath  '='  _recursion_or_funcname  •  Id  …

    //Possible interpretations:

    //  1:  'let'  attrpath  '='  (App  _recursion_or_funcname  •  _expr_select)
    //  2:  'let'  attrpath  '='  (_operator_or_recursionorfuncname  _recursion_or_funcname)  •  Id  …



    //_operator_or_recursionorfuncname: $ => choice(
    //  $.UnaryOp,
    //  $.BinaryOp,
    //  $._recursion_or_funcname
    //),

    //input
    //let
    //  y = f x
    //in y

    //1.
    //let
    //  y = (f x)
    //in y

    //2.
    //???
    //let
    //  y = (f x) i
    //in y

    //*/

    ///*
    //App: $ => prec(PREC.App,
    //  seq(field('function', $._recursion_or_funcname), field('argument', $._expr_select))
    //),
    //*/

    //_app_function: $ => $._recursion_or_funcname,
    //_app_argument: $ => $._expr_select,

    //_expr_select: $ => choice(
    //  $.select,
    //  $._expr_simple
    //),

    //// access
    //select: $ => choice(
    //  seq(field('expression', $._expr_simple), '.', field('attrpath', $.attrpath)),
    //  seq(field('expression', $._expr_simple), '.', field('attrpath', $.attrpath), 'or', field('default', $._expr_select)),
    //),

    //_expr_simple: $ => choice(
    //  $.Id,
    //  $.IdEnumTag,
    //  $.IdBuiltinFun,
    //  $.Bool,
    //  $.Num,
    //  $.Str, // string
    //  $.MultiStr,
    //  $.parenthesized,
    //  $.UniRecord,
    //  $.Arr,
    //  $.Type,
    //),

    //Type: $ => seq($._expr_simple, ':', $._type_expression),

    //// FIXME make this more restrictive?
    //// example: is this parse error or eval error?
    //// nickel <<< '1 : "x"'
    //// error: incompatible types
    //_type_expression: $ => prec.left($._expr_simple),

    //parenthesized: $ => seq('(', field('expression', $._expression), ')'),

    //UniRecord: $ => seq('{', optional(
    //  $._binds,
    //), '}'),

    //StrChunkLiteral: $ => $._string_fragment,

    //StrChunk: $ => choice(
    //  $.StrChunkLiteral,
    //  $.RichTerm, // interpolation
    //),

    //Str: $ => seq(
    //  '"',
    //  repeat($.StrChunk),
    //  /* nix:
    //  repeat(choice(
    //    $._string_fragment,
    //    $.interpolation,
    //    //$.escape_sequence // TODO
    //  )),
    //  */
    //  '"'
    //),

    //// TODO
    ////escape_sequence: $ => token.immediate(/\\(.|\s)/), // Can also escape newline.

    ////MultiStrStart: $ => 'm%"',
    //MultiStrStart: $ => seq('m%', $._multistring_start),
    //MultiStrEnd: $ => seq('"%', $._multistring_end),

    //MultiStrLiteral: $ => $._multistring_part_fixed,

    //// multi string interpolation
    //// aka RichTerm
    //MultiStrIpol: $ => seq(
    //  $._multistring_ipol_start,
    //  field('expression', $._expression),
    //  '}',
    //),

    //MultiStr: $ => choice(
    //  // level 1 multistring
    //  /*
    //  seq(
    //    $.MultiStrStart,
    //    repeat(choice(
    //      $.MultiStrLiteral,
    //      $.RichTerm, // TODO require multiple % = same number as in string delimiters
    //      //alias($.indented_escape_sequence, $.escape_sequence),
    //    )),
    //    '"%m'
    //  ),
    //  */
    //  // higher level multistring
    //  seq(
    //    $.MultiStrStart,
    //    repeat(choice(
    //      $.MultiStrLiteral,
    //      $.MultiStrIpol,
    //      /*
    //      seq(
    //        $.MultiStrIpol, // TODO this shoud be part of RichTerm
    //        $.RichTerm,
    //      ),
    //      */
    //    )),
    //    $.MultiStrEnd,
    //  ),
    //),

    ////indented_escape_sequence: $ => token.immediate(/'''|''\$|''\\(.|\s)/), // Can also escape newline.

    //_binds: $ => seq(
    //  commaSep1(field('bind', $.bind)),
    //  // allow dangling comma after last bind
    //  optional(','),
    //),

    //// NOTE: no ",". This is handled in the _binds rule
    //bind: $ => seq(field('attrpath', $.attrpath), optional(field('Annot', $.Annot)), '=', field('expression', $._expression)),

    //// NOTE: This rule is optional from the bind rule, repeat1 here to avoid matching
    //// the empty string
    //Annot: $ => repeat1($._AnnotAtom),

    //_AnnotAtom: $ =>
    //  choice(
    //    $.AnnotDefault
    //  ),
    //
    //AnnotDefault: $ => seq("|", "default"),

    //attrpath: $ => sep1(field('attr', choice(
    //  alias($.Id, $.attr_identifier),
    //  $.Str,
    //  $.RichTerm,
    //)), "."),

    ///*
    //attrs_inherited: $ => repeat1(field('attr', choice(
    //  $.Id,
    //  $.Str,
    //  $.RichTerm,
    //))),
    //*/

    ///*
    //attrs_inherited_from: $ => repeat1(field('attr', choice(
    //  alias($.Id, $.attr_identifier),
    //  $.Str,
    //  $.RichTerm,
    //))),
    //*/

    //// interpolation
    //RichTerm: $ => seq('%{', field('expression', $._expression), '}'),
    //// TODO require multiple %

    //// baed on json grammar https://github.com/tree-sitter/tree-sitter-json
    //Arr: $ => seq(
    //  "[",
    //  commaSep(field('element', $._expr_select)),
    //  optional(','), // allow dangling comma after last element
    //  "]"
    //),

    //// NOTE: Nickel only has single line comments
    //comment: $ => token(choice(
    //  seq('#', /[^\n]*/),
    //)),
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

function parens(rule) {
  return seq("(", rule, ")");
}

function square(rule) {
  return seq("[", rule, "]");
}
