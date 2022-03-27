// NOTE[builtin] Nickel lexes all builtin functions in lexer.rs. This is
// possible for use, but we can also choose to parse them in the parser
// instead. This prevents the grammar from having to be updated when a new
// builtin function is added. Additionally, it keeps the grammar smaller. You
// will not see rules in this grammar that match on all builtin function
// seperately.

// NOTE[typerule] In the lalrpop grammar there is a FixedType rule that is just
// a Types rule, but with post-processing. We don't do any post-processing in
// tree-sitter, so we just parse them as a `Types`.

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
    comment: _ => token(
      seq('#', /[^\n]*/),
    ),

    keyword: _ => token(/if|then|else|foreall|in|let|switch|null|true|false|fun|import|merge|default|doc/),

    num_literal: _ => /[0-9]*\.?[0-9]+/,

    ident: _ => /_?[a-zA-Z][_a-zA-Z0-9-]*/,

    ////////////////////////////
    // PARSER RULES (grammar.lalrpop)
    ////////////////////////////
    // In the lalrpop grammar this (and the annot)-rule(s) are parameterized.
    // See NOTE[typerule].
    annot_atom: $ => choice(
      seq("|", $.types),
      seq("|", "default"),
      seq("|", "doc", $.static_string),
      seq(":", $.types),
    ),

    // See NOTE[typerule].
    annot: $ => repeat1($.annot_atom),

    types: $ => choice(
      $.infix_expr,
      $.forall,
    ),

    uni_term: $ => choice(
      $.infix_expr,
      // NOTE: We seperate the rules out into their own, otherwise it would get
      // a little much for this single rule.
      //TODO
      //$.annotated_infix_expr,
      //$.forall,
      $.let_expr,
      $.fun_expr,
      //$.switch_expr,
      $.ite_expr, // if then else
    ),

    let_expr: $ => seq(
      "let",
      $.pattern,
      optional($.annot),
      "=",
      $.term,
      "in",
      $.term,
    ),

    fun_expr: $ => seq(
      "fun",
      repeat1($.pattern),
      "=>",
      $.term,
    ),

    ite_expr: $ => seq(
      "if",
      $.term,
      "then",
      $.term,
      "else",
      $.term,
    ),

    forall: $ => seq(
      "forall",
      repeat1($.ident),
      ".",
      $.types,
    ),

    applicative: $ => choice(
      seq("import", $.static_string),
      $.type_array,
      seq($.applicative, $.record_operand),
      // We don't explicitly have the UOp rule. Instead we match generically on
      // builtin functions.
      // This is different from the lalrpop grammar. See NOTE[builtin].
      //seq($.u_op, $.record_operand),
      // TODO
      // BOpPre?
      // NOpPre?
      $.record_operand,
    ),

    type_array: $ => seq("Array", $.record_operand),

    record_operand: $ => choice(
      $.atom,
      // TODO
      $.record_operation_chain,
    ),

    record_operation_chain: $ => choice(
      seq($.record_operand, ".", $.ident),
      //TODO
      //seq($.record_operand, ".", $.str_chunks),
    ),

    uni_record: $ => seq(
      "{",
      repeat(seq($.record_field, ",")),
      optional($.record_last_field),
      optional(";"),
      "}",
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
      // DIFERENT from lalrpop grammar. See NOTE[builtin].
      $.builtin,
      $.uni_record,
      seq("`", $.enum_tag),
      // NOTE: Arrays may have a trailing comma in Nickel
      square(seq(commaSep($.term), optional(","))),
      //$.type_atom,
    ),

    record_field: $ => seq(
      $.field_path,
      optional($.annot),
      optional(seq("=", $.term)),
    ),

    record_last_field: $ => choice(
      $.record_field,
      "..",
    ),

    field_path: $ => sep1($.field_path_elem, "."),

    field_path_elem: $ => choice(
      $.ident,
      //TODO
      //$.str_chunks,
    ),

    // The right hand side of an `=` inside a destructuring pattern.
    pattern: $ => choice(
      seq(optional(seq($.ident, "@")), $.destruct),
      $.ident,
    ),

    destruct: $ => seq(
      "{",
      seq(commaSep($.match), optional(",")),
      "}",
    ),

    match: $ => seq(
      $.ident,
      optional($.annot),
      //TODO
      //optional($.default_annot),
      "=",
      $.pattern,
    ),

    bool: _ => choice(
      "true",
      "false",
    ),

    // TODO: Replace with proper representation
    chunk_literal: _ => /[0-9a-zA-Z]*/,
			//repeat1($.chunk_literal_part),

    static_string: $ => choice(
      // Single line
      seq("\"", optional($.chunk_literal), "\""),
      // TODO: Multi line
      //seq("m%\"", optional($.chunk_literal), "\""),
    ),

    enum_tag: $ => choice(
      $.ident,
      $.static_string,
    ),

    builtin: $ => seq(
      "%",
      $.ident,
      "%",
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

    infix_expr: $ => choice(
      prec(0, $.applicative),
      $.infix_u_op,
      $.infix_b_op,
    ),

  },
});


function sep(rule, separator) {
  return optional(sep1(rule, separator));
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}

function commaSep1(rule) {
  return sep1(rule, ",");
}

function commaSep(rule) {
  return sep(rule, ",");
}

function parens(rule) {
  return seq("(", rule, ")");
}

function square(rule) {
  return seq("[", rule, "]");
}
