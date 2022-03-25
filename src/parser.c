#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 47
#define LARGE_STATE_COUNT 14
#define SYMBOL_COUNT 49
#define ALIAS_COUNT 0
#define TOKEN_COUNT 37
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 3

enum {
  sym_keyword = 1,
  sym_comment = 2,
  sym_num_literal = 3,
  sym_ident = 4,
  anon_sym_import = 5,
  anon_sym_Array = 6,
  anon_sym_LPAREN = 7,
  anon_sym_RPAREN = 8,
  anon_sym_null = 9,
  anon_sym_BQUOTE = 10,
  anon_sym_true = 11,
  anon_sym_false = 12,
  sym_chunk_literal = 13,
  anon_sym_DQUOTE = 14,
  anon_sym_EQ_EQ = 15,
  anon_sym_BANG_EQ = 16,
  anon_sym_LT = 17,
  anon_sym_LT_EQ = 18,
  anon_sym_GT = 19,
  anon_sym_GT_EQ = 20,
  anon_sym_AMP_AMP = 21,
  anon_sym_PIPE_PIPE = 22,
  anon_sym_PLUS = 23,
  anon_sym_DASH = 24,
  anon_sym_STAR = 25,
  anon_sym_SLASH = 26,
  anon_sym_DASH_GT = 27,
  anon_sym_AMP = 28,
  anon_sym_PLUS_PLUS = 29,
  anon_sym_AT = 30,
  anon_sym_BANG = 31,
  sym__string_fragment = 32,
  sym__multistring_start = 33,
  sym__multistring_part_fixed = 34,
  sym__multistring_ipol_start = 35,
  sym__multistring_end = 36,
  sym_term = 37,
  sym_uni_term = 38,
  sym_applicative = 39,
  sym_type_array = 40,
  sym_record_operand = 41,
  sym_atom = 42,
  sym_bool = 43,
  sym_static_string = 44,
  sym_enum_tag = 45,
  sym_infix_b_op = 46,
  sym_infix_u_op = 47,
  sym_infix_expr = 48,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_keyword] = "keyword",
  [sym_comment] = "comment",
  [sym_num_literal] = "num_literal",
  [sym_ident] = "ident",
  [anon_sym_import] = "import",
  [anon_sym_Array] = "Array",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_null] = "null",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_chunk_literal] = "chunk_literal",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_LT] = "<",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_AMP] = "&",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_AT] = "@",
  [anon_sym_BANG] = "!",
  [sym__string_fragment] = "_string_fragment",
  [sym__multistring_start] = "_multistring_start",
  [sym__multistring_part_fixed] = "_multistring_part_fixed",
  [sym__multistring_ipol_start] = "_multistring_ipol_start",
  [sym__multistring_end] = "_multistring_end",
  [sym_term] = "term",
  [sym_uni_term] = "uni_term",
  [sym_applicative] = "applicative",
  [sym_type_array] = "type_array",
  [sym_record_operand] = "record_operand",
  [sym_atom] = "atom",
  [sym_bool] = "bool",
  [sym_static_string] = "static_string",
  [sym_enum_tag] = "enum_tag",
  [sym_infix_b_op] = "infix_b_op",
  [sym_infix_u_op] = "infix_u_op",
  [sym_infix_expr] = "infix_expr",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_keyword] = sym_keyword,
  [sym_comment] = sym_comment,
  [sym_num_literal] = sym_num_literal,
  [sym_ident] = sym_ident,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_Array] = anon_sym_Array,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_null] = anon_sym_null,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_chunk_literal] = sym_chunk_literal,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_PLUS_PLUS] = anon_sym_PLUS_PLUS,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_BANG] = anon_sym_BANG,
  [sym__string_fragment] = sym__string_fragment,
  [sym__multistring_start] = sym__multistring_start,
  [sym__multistring_part_fixed] = sym__multistring_part_fixed,
  [sym__multistring_ipol_start] = sym__multistring_ipol_start,
  [sym__multistring_end] = sym__multistring_end,
  [sym_term] = sym_term,
  [sym_uni_term] = sym_uni_term,
  [sym_applicative] = sym_applicative,
  [sym_type_array] = sym_type_array,
  [sym_record_operand] = sym_record_operand,
  [sym_atom] = sym_atom,
  [sym_bool] = sym_bool,
  [sym_static_string] = sym_static_string,
  [sym_enum_tag] = sym_enum_tag,
  [sym_infix_b_op] = sym_infix_b_op,
  [sym_infix_u_op] = sym_infix_u_op,
  [sym_infix_expr] = sym_infix_expr,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_num_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_ident] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Array] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_null] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_chunk_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [sym__string_fragment] = {
    .visible = false,
    .named = true,
  },
  [sym__multistring_start] = {
    .visible = false,
    .named = true,
  },
  [sym__multistring_part_fixed] = {
    .visible = false,
    .named = true,
  },
  [sym__multistring_ipol_start] = {
    .visible = false,
    .named = true,
  },
  [sym__multistring_end] = {
    .visible = false,
    .named = true,
  },
  [sym_term] = {
    .visible = true,
    .named = true,
  },
  [sym_uni_term] = {
    .visible = true,
    .named = true,
  },
  [sym_applicative] = {
    .visible = true,
    .named = true,
  },
  [sym_type_array] = {
    .visible = true,
    .named = true,
  },
  [sym_record_operand] = {
    .visible = true,
    .named = true,
  },
  [sym_atom] = {
    .visible = true,
    .named = true,
  },
  [sym_bool] = {
    .visible = true,
    .named = true,
  },
  [sym_static_string] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_infix_b_op] = {
    .visible = true,
    .named = true,
  },
  [sym_infix_u_op] = {
    .visible = true,
    .named = true,
  },
  [sym_infix_expr] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_argument = 1,
  field_left = 2,
  field_operator = 3,
  field_right = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_argument] = "argument",
  [field_left] = "left",
  [field_operator] = "operator",
  [field_right] = "right",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_argument, 1},
    {field_operator, 0},
  [2] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(9);
      if (lookahead == '!') ADVANCE(77);
      if (lookahead == '"') ADVANCE(58);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '&') ADVANCE(73);
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == ')') ADVANCE(55);
      if (lookahead == '*') ADVANCE(70);
      if (lookahead == '+') ADVANCE(67);
      if (lookahead == '-') ADVANCE(69);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '/') ADVANCE(71);
      if (lookahead == '<') ADVANCE(61);
      if (lookahead == '=') ADVANCE(4);
      if (lookahead == '>') ADVANCE(63);
      if (lookahead == '@') ADVANCE(75);
      if (lookahead == 'A') ADVANCE(41);
      if (lookahead == '_') ADVANCE(7);
      if (lookahead == '`') ADVANCE(56);
      if (lookahead == 'd') ADVANCE(20);
      if (lookahead == 'e') ADVANCE(31);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(51);
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 'm') ADVANCE(25);
      if (lookahead == 'n') ADVANCE(46);
      if (lookahead == 's') ADVANCE(49);
      if (lookahead == 't') ADVANCE(29);
      if (lookahead == '|') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(76);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == '-') ADVANCE(68);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == 'A') ADVANCE(41);
      if (lookahead == '_') ADVANCE(7);
      if (lookahead == '`') ADVANCE(56);
      if (lookahead == 'd') ADVANCE(20);
      if (lookahead == 'e') ADVANCE(31);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(51);
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 'm') ADVANCE(25);
      if (lookahead == 'n') ADVANCE(46);
      if (lookahead == 's') ADVANCE(49);
      if (lookahead == 't') ADVANCE(29);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(58);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '_') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 3:
      if (lookahead == '=') ADVANCE(60);
      END_STATE();
    case 4:
      if (lookahead == '=') ADVANCE(59);
      END_STATE();
    case 5:
      if (lookahead == '|') ADVANCE(66);
      END_STATE();
    case 6:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 7:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 8:
      if (eof) ADVANCE(9);
      if (lookahead == '!') ADVANCE(3);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '&') ADVANCE(73);
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == ')') ADVANCE(55);
      if (lookahead == '*') ADVANCE(70);
      if (lookahead == '+') ADVANCE(67);
      if (lookahead == '-') ADVANCE(69);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '/') ADVANCE(71);
      if (lookahead == '<') ADVANCE(61);
      if (lookahead == '=') ADVANCE(4);
      if (lookahead == '>') ADVANCE(63);
      if (lookahead == '@') ADVANCE(75);
      if (lookahead == '_') ADVANCE(7);
      if (lookahead == '`') ADVANCE(56);
      if (lookahead == 'd') ADVANCE(20);
      if (lookahead == 'e') ADVANCE(31);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(51);
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 'm') ADVANCE(25);
      if (lookahead == 'n') ADVANCE(46);
      if (lookahead == 's') ADVANCE(49);
      if (lookahead == 't') ADVANCE(29);
      if (lookahead == '|') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_keyword);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_num_literal);
      if (lookahead == '.') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_num_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(31);
      if (lookahead == 'o') ADVANCE(42);
      if (lookahead == 'u') ADVANCE(35);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(34);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(47);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'c') ADVANCE(11);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'c') ADVANCE(28);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(18);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(35);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(11);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(44);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(16);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(40);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'f') ADVANCE(17);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'g') ADVANCE(22);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'h') ADVANCE(11);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'h') ADVANCE(21);
      if (lookahead == 'r') ADVANCE(48);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'i') ADVANCE(45);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(43);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(11);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(44);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(32);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'n') ADVANCE(11);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'o') ADVANCE(38);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'p') ADVANCE(36);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(44);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(15);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(27);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(39);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(24);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 's') ADVANCE(22);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 't') ADVANCE(11);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 't') ADVANCE(19);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'u') ADVANCE(34);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'u') ADVANCE(33);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'u') ADVANCE(22);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'w') ADVANCE(30);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'y') ADVANCE(53);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'f' ||
          lookahead == 'n') ADVANCE(11);
      if (lookahead == 'm') ADVANCE(37);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_Array);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_chunk_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(62);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(64);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(74);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(72);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '&') ADVANCE(65);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(60);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'f') ADVANCE(1);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'n') ADVANCE(3);
      if (lookahead == 't') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(5);
      END_STATE();
    case 2:
      if (lookahead == 'm') ADVANCE(6);
      END_STATE();
    case 3:
      if (lookahead == 'u') ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead == 'r') ADVANCE(8);
      END_STATE();
    case 5:
      if (lookahead == 'l') ADVANCE(9);
      END_STATE();
    case 6:
      if (lookahead == 'p') ADVANCE(10);
      END_STATE();
    case 7:
      if (lookahead == 'l') ADVANCE(11);
      END_STATE();
    case 8:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 9:
      if (lookahead == 's') ADVANCE(13);
      END_STATE();
    case 10:
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(15);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 14:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 1},
  [2] = {.lex_state = 8},
  [3] = {.lex_state = 8},
  [4] = {.lex_state = 8},
  [5] = {.lex_state = 8},
  [6] = {.lex_state = 8},
  [7] = {.lex_state = 8},
  [8] = {.lex_state = 8},
  [9] = {.lex_state = 8},
  [10] = {.lex_state = 8},
  [11] = {.lex_state = 8},
  [12] = {.lex_state = 8},
  [13] = {.lex_state = 8},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 8},
  [27] = {.lex_state = 8},
  [28] = {.lex_state = 8},
  [29] = {.lex_state = 8},
  [30] = {.lex_state = 8},
  [31] = {.lex_state = 8},
  [32] = {.lex_state = 8},
  [33] = {.lex_state = 8},
  [34] = {.lex_state = 8},
  [35] = {.lex_state = 8},
  [36] = {.lex_state = 8},
  [37] = {.lex_state = 8},
  [38] = {.lex_state = 8},
  [39] = {.lex_state = 8},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 57},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
};

enum {
  ts_external_token__string_fragment = 0,
  ts_external_token__multistring_start = 1,
  ts_external_token__multistring_part_fixed = 2,
  ts_external_token__multistring_ipol_start = 3,
  ts_external_token__multistring_end = 4,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__string_fragment] = sym__string_fragment,
  [ts_external_token__multistring_start] = sym__multistring_start,
  [ts_external_token__multistring_part_fixed] = sym__multistring_part_fixed,
  [ts_external_token__multistring_ipol_start] = sym__multistring_ipol_start,
  [ts_external_token__multistring_end] = sym__multistring_end,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__string_fragment] = true,
    [ts_external_token__multistring_start] = true,
    [ts_external_token__multistring_part_fixed] = true,
    [ts_external_token__multistring_ipol_start] = true,
    [ts_external_token__multistring_end] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_keyword] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(1),
    [sym_ident] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_Array] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [sym__string_fragment] = ACTIONS(1),
    [sym__multistring_start] = ACTIONS(1),
    [sym__multistring_part_fixed] = ACTIONS(1),
    [sym__multistring_ipol_start] = ACTIONS(1),
    [sym__multistring_end] = ACTIONS(1),
  },
  [1] = {
    [sym_term] = STATE(43),
    [sym_uni_term] = STATE(46),
    [sym_applicative] = STATE(2),
    [sym_type_array] = STATE(12),
    [sym_record_operand] = STATE(12),
    [sym_atom] = STATE(13),
    [sym_bool] = STATE(4),
    [sym_infix_b_op] = STATE(29),
    [sym_infix_u_op] = STATE(29),
    [sym_infix_expr] = STATE(28),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(5),
    [sym_ident] = ACTIONS(7),
    [anon_sym_import] = ACTIONS(9),
    [anon_sym_Array] = ACTIONS(11),
    [anon_sym_LPAREN] = ACTIONS(13),
    [anon_sym_null] = ACTIONS(7),
    [anon_sym_BQUOTE] = ACTIONS(15),
    [anon_sym_true] = ACTIONS(17),
    [anon_sym_false] = ACTIONS(17),
    [anon_sym_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(21),
  },
  [2] = {
    [sym_record_operand] = STATE(11),
    [sym_atom] = STATE(13),
    [sym_bool] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(5),
    [sym_ident] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(13),
    [anon_sym_RPAREN] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(7),
    [anon_sym_BQUOTE] = ACTIONS(15),
    [anon_sym_true] = ACTIONS(17),
    [anon_sym_false] = ACTIONS(17),
    [anon_sym_EQ_EQ] = ACTIONS(23),
    [anon_sym_BANG_EQ] = ACTIONS(23),
    [anon_sym_LT] = ACTIONS(25),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [anon_sym_GT] = ACTIONS(25),
    [anon_sym_GT_EQ] = ACTIONS(23),
    [anon_sym_AMP_AMP] = ACTIONS(23),
    [anon_sym_PIPE_PIPE] = ACTIONS(23),
    [anon_sym_PLUS] = ACTIONS(25),
    [anon_sym_DASH] = ACTIONS(25),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_SLASH] = ACTIONS(23),
    [anon_sym_DASH_GT] = ACTIONS(23),
    [anon_sym_AMP] = ACTIONS(25),
    [anon_sym_PLUS_PLUS] = ACTIONS(23),
    [anon_sym_AT] = ACTIONS(23),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(27),
    [sym_ident] = ACTIONS(29),
    [anon_sym_LPAREN] = ACTIONS(27),
    [anon_sym_RPAREN] = ACTIONS(27),
    [anon_sym_null] = ACTIONS(29),
    [anon_sym_BQUOTE] = ACTIONS(27),
    [anon_sym_true] = ACTIONS(29),
    [anon_sym_false] = ACTIONS(29),
    [anon_sym_EQ_EQ] = ACTIONS(27),
    [anon_sym_BANG_EQ] = ACTIONS(27),
    [anon_sym_LT] = ACTIONS(29),
    [anon_sym_LT_EQ] = ACTIONS(27),
    [anon_sym_GT] = ACTIONS(29),
    [anon_sym_GT_EQ] = ACTIONS(27),
    [anon_sym_AMP_AMP] = ACTIONS(27),
    [anon_sym_PIPE_PIPE] = ACTIONS(27),
    [anon_sym_PLUS] = ACTIONS(29),
    [anon_sym_DASH] = ACTIONS(29),
    [anon_sym_STAR] = ACTIONS(27),
    [anon_sym_SLASH] = ACTIONS(27),
    [anon_sym_DASH_GT] = ACTIONS(27),
    [anon_sym_AMP] = ACTIONS(29),
    [anon_sym_PLUS_PLUS] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(27),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(31),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(31),
    [sym_ident] = ACTIONS(33),
    [anon_sym_LPAREN] = ACTIONS(31),
    [anon_sym_RPAREN] = ACTIONS(31),
    [anon_sym_null] = ACTIONS(33),
    [anon_sym_BQUOTE] = ACTIONS(31),
    [anon_sym_true] = ACTIONS(33),
    [anon_sym_false] = ACTIONS(33),
    [anon_sym_EQ_EQ] = ACTIONS(31),
    [anon_sym_BANG_EQ] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
    [anon_sym_LT_EQ] = ACTIONS(31),
    [anon_sym_GT] = ACTIONS(33),
    [anon_sym_GT_EQ] = ACTIONS(31),
    [anon_sym_AMP_AMP] = ACTIONS(31),
    [anon_sym_PIPE_PIPE] = ACTIONS(31),
    [anon_sym_PLUS] = ACTIONS(33),
    [anon_sym_DASH] = ACTIONS(33),
    [anon_sym_STAR] = ACTIONS(31),
    [anon_sym_SLASH] = ACTIONS(31),
    [anon_sym_DASH_GT] = ACTIONS(31),
    [anon_sym_AMP] = ACTIONS(33),
    [anon_sym_PLUS_PLUS] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(31),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(35),
    [sym_ident] = ACTIONS(37),
    [anon_sym_LPAREN] = ACTIONS(35),
    [anon_sym_RPAREN] = ACTIONS(35),
    [anon_sym_null] = ACTIONS(37),
    [anon_sym_BQUOTE] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [anon_sym_EQ_EQ] = ACTIONS(35),
    [anon_sym_BANG_EQ] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
    [anon_sym_LT_EQ] = ACTIONS(35),
    [anon_sym_GT] = ACTIONS(37),
    [anon_sym_GT_EQ] = ACTIONS(35),
    [anon_sym_AMP_AMP] = ACTIONS(35),
    [anon_sym_PIPE_PIPE] = ACTIONS(35),
    [anon_sym_PLUS] = ACTIONS(37),
    [anon_sym_DASH] = ACTIONS(37),
    [anon_sym_STAR] = ACTIONS(35),
    [anon_sym_SLASH] = ACTIONS(35),
    [anon_sym_DASH_GT] = ACTIONS(35),
    [anon_sym_AMP] = ACTIONS(37),
    [anon_sym_PLUS_PLUS] = ACTIONS(35),
    [anon_sym_AT] = ACTIONS(35),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(39),
    [sym_ident] = ACTIONS(41),
    [anon_sym_LPAREN] = ACTIONS(39),
    [anon_sym_RPAREN] = ACTIONS(39),
    [anon_sym_null] = ACTIONS(41),
    [anon_sym_BQUOTE] = ACTIONS(39),
    [anon_sym_true] = ACTIONS(41),
    [anon_sym_false] = ACTIONS(41),
    [anon_sym_EQ_EQ] = ACTIONS(39),
    [anon_sym_BANG_EQ] = ACTIONS(39),
    [anon_sym_LT] = ACTIONS(41),
    [anon_sym_LT_EQ] = ACTIONS(39),
    [anon_sym_GT] = ACTIONS(41),
    [anon_sym_GT_EQ] = ACTIONS(39),
    [anon_sym_AMP_AMP] = ACTIONS(39),
    [anon_sym_PIPE_PIPE] = ACTIONS(39),
    [anon_sym_PLUS] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(41),
    [anon_sym_STAR] = ACTIONS(39),
    [anon_sym_SLASH] = ACTIONS(39),
    [anon_sym_DASH_GT] = ACTIONS(39),
    [anon_sym_AMP] = ACTIONS(41),
    [anon_sym_PLUS_PLUS] = ACTIONS(39),
    [anon_sym_AT] = ACTIONS(39),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(43),
    [sym_ident] = ACTIONS(45),
    [anon_sym_LPAREN] = ACTIONS(43),
    [anon_sym_RPAREN] = ACTIONS(43),
    [anon_sym_null] = ACTIONS(45),
    [anon_sym_BQUOTE] = ACTIONS(43),
    [anon_sym_true] = ACTIONS(45),
    [anon_sym_false] = ACTIONS(45),
    [anon_sym_EQ_EQ] = ACTIONS(43),
    [anon_sym_BANG_EQ] = ACTIONS(43),
    [anon_sym_LT] = ACTIONS(45),
    [anon_sym_LT_EQ] = ACTIONS(43),
    [anon_sym_GT] = ACTIONS(45),
    [anon_sym_GT_EQ] = ACTIONS(43),
    [anon_sym_AMP_AMP] = ACTIONS(43),
    [anon_sym_PIPE_PIPE] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(45),
    [anon_sym_DASH] = ACTIONS(45),
    [anon_sym_STAR] = ACTIONS(43),
    [anon_sym_SLASH] = ACTIONS(43),
    [anon_sym_DASH_GT] = ACTIONS(43),
    [anon_sym_AMP] = ACTIONS(45),
    [anon_sym_PLUS_PLUS] = ACTIONS(43),
    [anon_sym_AT] = ACTIONS(43),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(47),
    [sym_ident] = ACTIONS(49),
    [anon_sym_LPAREN] = ACTIONS(47),
    [anon_sym_RPAREN] = ACTIONS(47),
    [anon_sym_null] = ACTIONS(49),
    [anon_sym_BQUOTE] = ACTIONS(47),
    [anon_sym_true] = ACTIONS(49),
    [anon_sym_false] = ACTIONS(49),
    [anon_sym_EQ_EQ] = ACTIONS(47),
    [anon_sym_BANG_EQ] = ACTIONS(47),
    [anon_sym_LT] = ACTIONS(49),
    [anon_sym_LT_EQ] = ACTIONS(47),
    [anon_sym_GT] = ACTIONS(49),
    [anon_sym_GT_EQ] = ACTIONS(47),
    [anon_sym_AMP_AMP] = ACTIONS(47),
    [anon_sym_PIPE_PIPE] = ACTIONS(47),
    [anon_sym_PLUS] = ACTIONS(49),
    [anon_sym_DASH] = ACTIONS(49),
    [anon_sym_STAR] = ACTIONS(47),
    [anon_sym_SLASH] = ACTIONS(47),
    [anon_sym_DASH_GT] = ACTIONS(47),
    [anon_sym_AMP] = ACTIONS(49),
    [anon_sym_PLUS_PLUS] = ACTIONS(47),
    [anon_sym_AT] = ACTIONS(47),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(51),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(51),
    [sym_ident] = ACTIONS(53),
    [anon_sym_LPAREN] = ACTIONS(51),
    [anon_sym_RPAREN] = ACTIONS(51),
    [anon_sym_null] = ACTIONS(53),
    [anon_sym_BQUOTE] = ACTIONS(51),
    [anon_sym_true] = ACTIONS(53),
    [anon_sym_false] = ACTIONS(53),
    [anon_sym_EQ_EQ] = ACTIONS(51),
    [anon_sym_BANG_EQ] = ACTIONS(51),
    [anon_sym_LT] = ACTIONS(53),
    [anon_sym_LT_EQ] = ACTIONS(51),
    [anon_sym_GT] = ACTIONS(53),
    [anon_sym_GT_EQ] = ACTIONS(51),
    [anon_sym_AMP_AMP] = ACTIONS(51),
    [anon_sym_PIPE_PIPE] = ACTIONS(51),
    [anon_sym_PLUS] = ACTIONS(53),
    [anon_sym_DASH] = ACTIONS(53),
    [anon_sym_STAR] = ACTIONS(51),
    [anon_sym_SLASH] = ACTIONS(51),
    [anon_sym_DASH_GT] = ACTIONS(51),
    [anon_sym_AMP] = ACTIONS(53),
    [anon_sym_PLUS_PLUS] = ACTIONS(51),
    [anon_sym_AT] = ACTIONS(51),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(55),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(55),
    [sym_ident] = ACTIONS(57),
    [anon_sym_LPAREN] = ACTIONS(55),
    [anon_sym_RPAREN] = ACTIONS(55),
    [anon_sym_null] = ACTIONS(57),
    [anon_sym_BQUOTE] = ACTIONS(55),
    [anon_sym_true] = ACTIONS(57),
    [anon_sym_false] = ACTIONS(57),
    [anon_sym_EQ_EQ] = ACTIONS(55),
    [anon_sym_BANG_EQ] = ACTIONS(55),
    [anon_sym_LT] = ACTIONS(57),
    [anon_sym_LT_EQ] = ACTIONS(55),
    [anon_sym_GT] = ACTIONS(57),
    [anon_sym_GT_EQ] = ACTIONS(55),
    [anon_sym_AMP_AMP] = ACTIONS(55),
    [anon_sym_PIPE_PIPE] = ACTIONS(55),
    [anon_sym_PLUS] = ACTIONS(57),
    [anon_sym_DASH] = ACTIONS(57),
    [anon_sym_STAR] = ACTIONS(55),
    [anon_sym_SLASH] = ACTIONS(55),
    [anon_sym_DASH_GT] = ACTIONS(55),
    [anon_sym_AMP] = ACTIONS(57),
    [anon_sym_PLUS_PLUS] = ACTIONS(55),
    [anon_sym_AT] = ACTIONS(55),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(59),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(59),
    [sym_ident] = ACTIONS(61),
    [anon_sym_LPAREN] = ACTIONS(59),
    [anon_sym_RPAREN] = ACTIONS(59),
    [anon_sym_null] = ACTIONS(61),
    [anon_sym_BQUOTE] = ACTIONS(59),
    [anon_sym_true] = ACTIONS(61),
    [anon_sym_false] = ACTIONS(61),
    [anon_sym_EQ_EQ] = ACTIONS(59),
    [anon_sym_BANG_EQ] = ACTIONS(59),
    [anon_sym_LT] = ACTIONS(61),
    [anon_sym_LT_EQ] = ACTIONS(59),
    [anon_sym_GT] = ACTIONS(61),
    [anon_sym_GT_EQ] = ACTIONS(59),
    [anon_sym_AMP_AMP] = ACTIONS(59),
    [anon_sym_PIPE_PIPE] = ACTIONS(59),
    [anon_sym_PLUS] = ACTIONS(61),
    [anon_sym_DASH] = ACTIONS(61),
    [anon_sym_STAR] = ACTIONS(59),
    [anon_sym_SLASH] = ACTIONS(59),
    [anon_sym_DASH_GT] = ACTIONS(59),
    [anon_sym_AMP] = ACTIONS(61),
    [anon_sym_PLUS_PLUS] = ACTIONS(59),
    [anon_sym_AT] = ACTIONS(59),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(63),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(63),
    [sym_ident] = ACTIONS(65),
    [anon_sym_LPAREN] = ACTIONS(63),
    [anon_sym_RPAREN] = ACTIONS(63),
    [anon_sym_null] = ACTIONS(65),
    [anon_sym_BQUOTE] = ACTIONS(63),
    [anon_sym_true] = ACTIONS(65),
    [anon_sym_false] = ACTIONS(65),
    [anon_sym_EQ_EQ] = ACTIONS(63),
    [anon_sym_BANG_EQ] = ACTIONS(63),
    [anon_sym_LT] = ACTIONS(65),
    [anon_sym_LT_EQ] = ACTIONS(63),
    [anon_sym_GT] = ACTIONS(65),
    [anon_sym_GT_EQ] = ACTIONS(63),
    [anon_sym_AMP_AMP] = ACTIONS(63),
    [anon_sym_PIPE_PIPE] = ACTIONS(63),
    [anon_sym_PLUS] = ACTIONS(65),
    [anon_sym_DASH] = ACTIONS(65),
    [anon_sym_STAR] = ACTIONS(63),
    [anon_sym_SLASH] = ACTIONS(63),
    [anon_sym_DASH_GT] = ACTIONS(63),
    [anon_sym_AMP] = ACTIONS(65),
    [anon_sym_PLUS_PLUS] = ACTIONS(63),
    [anon_sym_AT] = ACTIONS(63),
  },
  [13] = {
    [ts_builtin_sym_end] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(67),
    [sym_ident] = ACTIONS(69),
    [anon_sym_LPAREN] = ACTIONS(67),
    [anon_sym_RPAREN] = ACTIONS(67),
    [anon_sym_null] = ACTIONS(69),
    [anon_sym_BQUOTE] = ACTIONS(67),
    [anon_sym_true] = ACTIONS(69),
    [anon_sym_false] = ACTIONS(69),
    [anon_sym_EQ_EQ] = ACTIONS(67),
    [anon_sym_BANG_EQ] = ACTIONS(67),
    [anon_sym_LT] = ACTIONS(69),
    [anon_sym_LT_EQ] = ACTIONS(67),
    [anon_sym_GT] = ACTIONS(69),
    [anon_sym_GT_EQ] = ACTIONS(67),
    [anon_sym_AMP_AMP] = ACTIONS(67),
    [anon_sym_PIPE_PIPE] = ACTIONS(67),
    [anon_sym_PLUS] = ACTIONS(69),
    [anon_sym_DASH] = ACTIONS(69),
    [anon_sym_STAR] = ACTIONS(67),
    [anon_sym_SLASH] = ACTIONS(67),
    [anon_sym_DASH_GT] = ACTIONS(67),
    [anon_sym_AMP] = ACTIONS(69),
    [anon_sym_PLUS_PLUS] = ACTIONS(67),
    [anon_sym_AT] = ACTIONS(67),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(28), 1,
      sym_infix_expr,
    STATE(44), 1,
      sym_uni_term,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [56] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(38), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [109] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(31), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [162] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(26), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [215] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(37), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [268] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(36), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [321] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(35), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [374] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(34), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [427] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(33), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [480] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(27), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [533] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(32), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [586] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    STATE(30), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_type_array,
      sym_record_operand,
    STATE(29), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [639] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(73), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(71), 13,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH_GT,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
  [665] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(75), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(73), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
    ACTIONS(71), 9,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [697] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_AMP_AMP,
    ACTIONS(91), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(93), 1,
      anon_sym_DASH_GT,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(75), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(81), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
    ACTIONS(83), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [741] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(23), 13,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH_GT,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
  [767] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(75), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(97), 7,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [803] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(75), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(97), 9,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [837] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(75), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(97), 5,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [875] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_AMP_AMP,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(75), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(97), 4,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [915] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(97), 9,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [945] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(97), 11,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH_GT,
  [973] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_AMP_AMP,
    ACTIONS(91), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(93), 1,
      anon_sym_DASH_GT,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(75), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(97), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
  [1017] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(75), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(97), 9,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [1051] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(97), 11,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH_GT,
  [1079] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    STATE(3), 1,
      sym_record_operand,
    STATE(4), 1,
      sym_bool,
    STATE(13), 1,
      sym_atom,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
  [1109] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(101), 1,
      sym_ident,
    ACTIONS(103), 1,
      anon_sym_DQUOTE,
    STATE(9), 1,
      sym_enum_tag,
    STATE(10), 1,
      sym_static_string,
  [1125] = 3,
    ACTIONS(105), 1,
      sym_comment,
    ACTIONS(107), 1,
      sym_chunk_literal,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
  [1135] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      sym_static_string,
  [1145] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 1,
      ts_builtin_sym_end,
  [1152] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(113), 1,
      anon_sym_RPAREN,
  [1159] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 1,
      anon_sym_DQUOTE,
  [1166] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(117), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(14)] = 0,
  [SMALL_STATE(15)] = 56,
  [SMALL_STATE(16)] = 109,
  [SMALL_STATE(17)] = 162,
  [SMALL_STATE(18)] = 215,
  [SMALL_STATE(19)] = 268,
  [SMALL_STATE(20)] = 321,
  [SMALL_STATE(21)] = 374,
  [SMALL_STATE(22)] = 427,
  [SMALL_STATE(23)] = 480,
  [SMALL_STATE(24)] = 533,
  [SMALL_STATE(25)] = 586,
  [SMALL_STATE(26)] = 639,
  [SMALL_STATE(27)] = 665,
  [SMALL_STATE(28)] = 697,
  [SMALL_STATE(29)] = 741,
  [SMALL_STATE(30)] = 767,
  [SMALL_STATE(31)] = 803,
  [SMALL_STATE(32)] = 837,
  [SMALL_STATE(33)] = 875,
  [SMALL_STATE(34)] = 915,
  [SMALL_STATE(35)] = 945,
  [SMALL_STATE(36)] = 973,
  [SMALL_STATE(37)] = 1017,
  [SMALL_STATE(38)] = 1051,
  [SMALL_STATE(39)] = 1079,
  [SMALL_STATE(40)] = 1109,
  [SMALL_STATE(41)] = 1125,
  [SMALL_STATE(42)] = 1135,
  [SMALL_STATE(43)] = 1145,
  [SMALL_STATE(44)] = 1152,
  [SMALL_STATE(45)] = 1159,
  [SMALL_STATE(46)] = 1166,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_expr, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_expr, 1),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_array, 2),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_array, 2),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_string, 3),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_string, 3),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 3),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 3),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_string, 2),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_string, 2),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool, 1),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 2),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_tag, 1),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_tag, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_applicative, 2),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_applicative, 2),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_applicative, 1),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_applicative, 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_operand, 1),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_record_operand, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_u_op, 2, .production_id = 1),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_u_op, 2, .production_id = 1),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uni_term, 1),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_b_op, 3, .production_id = 2),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_b_op, 3, .production_id = 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [111] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term, 1),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_nickel_external_scanner_create(void);
void tree_sitter_nickel_external_scanner_destroy(void *);
bool tree_sitter_nickel_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_nickel_external_scanner_serialize(void *, char *);
void tree_sitter_nickel_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_nickel(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_keyword,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_nickel_external_scanner_create,
      tree_sitter_nickel_external_scanner_destroy,
      tree_sitter_nickel_external_scanner_scan,
      tree_sitter_nickel_external_scanner_serialize,
      tree_sitter_nickel_external_scanner_deserialize,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
