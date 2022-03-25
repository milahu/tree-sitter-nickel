#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 50
#define LARGE_STATE_COUNT 15
#define SYMBOL_COUNT 51
#define ALIAS_COUNT 0
#define TOKEN_COUNT 38
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
  anon_sym_PERCENT = 15,
  anon_sym_EQ_EQ = 16,
  anon_sym_BANG_EQ = 17,
  anon_sym_LT = 18,
  anon_sym_LT_EQ = 19,
  anon_sym_GT = 20,
  anon_sym_GT_EQ = 21,
  anon_sym_AMP_AMP = 22,
  anon_sym_PIPE_PIPE = 23,
  anon_sym_PLUS = 24,
  anon_sym_DASH = 25,
  anon_sym_STAR = 26,
  anon_sym_SLASH = 27,
  anon_sym_DASH_GT = 28,
  anon_sym_AMP = 29,
  anon_sym_PLUS_PLUS = 30,
  anon_sym_AT = 31,
  anon_sym_BANG = 32,
  sym__string_fragment = 33,
  sym__multistring_start = 34,
  sym__multistring_part_fixed = 35,
  sym__multistring_ipol_start = 36,
  sym__multistring_end = 37,
  sym_term = 38,
  sym_uni_term = 39,
  sym_applicative = 40,
  sym_type_array = 41,
  sym_record_operand = 42,
  sym_atom = 43,
  sym_bool = 44,
  sym_static_string = 45,
  sym_enum_tag = 46,
  sym_builtin = 47,
  sym_infix_b_op = 48,
  sym_infix_u_op = 49,
  sym_infix_expr = 50,
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
  [anon_sym_PERCENT] = "%",
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
  [sym_builtin] = "builtin",
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
  [anon_sym_PERCENT] = anon_sym_PERCENT,
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
  [sym_builtin] = sym_builtin,
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
  [anon_sym_PERCENT] = {
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
  [sym_builtin] = {
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
      if (lookahead == '!') ADVANCE(78);
      if (lookahead == '"') ADVANCE(58);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '%') ADVANCE(59);
      if (lookahead == '&') ADVANCE(74);
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == ')') ADVANCE(55);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(68);
      if (lookahead == '-') ADVANCE(70);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == '<') ADVANCE(62);
      if (lookahead == '=') ADVANCE(4);
      if (lookahead == '>') ADVANCE(64);
      if (lookahead == '@') ADVANCE(76);
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
      if (lookahead == '!') ADVANCE(77);
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '%') ADVANCE(59);
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == '-') ADVANCE(69);
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
      if (lookahead == '=') ADVANCE(61);
      END_STATE();
    case 4:
      if (lookahead == '=') ADVANCE(60);
      END_STATE();
    case 5:
      if (lookahead == '|') ADVANCE(67);
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
      if (lookahead == '%') ADVANCE(59);
      if (lookahead == '&') ADVANCE(74);
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == ')') ADVANCE(55);
      if (lookahead == '*') ADVANCE(71);
      if (lookahead == '+') ADVANCE(68);
      if (lookahead == '-') ADVANCE(70);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == '<') ADVANCE(62);
      if (lookahead == '=') ADVANCE(4);
      if (lookahead == '>') ADVANCE(64);
      if (lookahead == '@') ADVANCE(76);
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
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(63);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(65);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(75);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(73);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '&') ADVANCE(66);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(61);
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
  [14] = {.lex_state = 8},
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
  [26] = {.lex_state = 1},
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
  [40] = {.lex_state = 8},
  [41] = {.lex_state = 2},
  [42] = {.lex_state = 57},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
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
    [anon_sym_PERCENT] = ACTIONS(1),
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
    [sym_term] = STATE(45),
    [sym_uni_term] = STATE(47),
    [sym_applicative] = STATE(2),
    [sym_type_array] = STATE(13),
    [sym_record_operand] = STATE(13),
    [sym_atom] = STATE(14),
    [sym_bool] = STATE(4),
    [sym_builtin] = STATE(4),
    [sym_infix_b_op] = STATE(34),
    [sym_infix_u_op] = STATE(34),
    [sym_infix_expr] = STATE(33),
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
    [anon_sym_PERCENT] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
    [anon_sym_BANG] = ACTIONS(23),
  },
  [2] = {
    [sym_record_operand] = STATE(3),
    [sym_atom] = STATE(14),
    [sym_bool] = STATE(4),
    [sym_builtin] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(25),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(5),
    [sym_ident] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(13),
    [anon_sym_RPAREN] = ACTIONS(25),
    [anon_sym_null] = ACTIONS(7),
    [anon_sym_BQUOTE] = ACTIONS(15),
    [anon_sym_true] = ACTIONS(17),
    [anon_sym_false] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(19),
    [anon_sym_EQ_EQ] = ACTIONS(25),
    [anon_sym_BANG_EQ] = ACTIONS(25),
    [anon_sym_LT] = ACTIONS(27),
    [anon_sym_LT_EQ] = ACTIONS(25),
    [anon_sym_GT] = ACTIONS(27),
    [anon_sym_GT_EQ] = ACTIONS(25),
    [anon_sym_AMP_AMP] = ACTIONS(25),
    [anon_sym_PIPE_PIPE] = ACTIONS(25),
    [anon_sym_PLUS] = ACTIONS(27),
    [anon_sym_DASH] = ACTIONS(27),
    [anon_sym_STAR] = ACTIONS(25),
    [anon_sym_SLASH] = ACTIONS(25),
    [anon_sym_DASH_GT] = ACTIONS(25),
    [anon_sym_AMP] = ACTIONS(27),
    [anon_sym_PLUS_PLUS] = ACTIONS(25),
    [anon_sym_AT] = ACTIONS(25),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(29),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(29),
    [sym_ident] = ACTIONS(31),
    [anon_sym_LPAREN] = ACTIONS(29),
    [anon_sym_RPAREN] = ACTIONS(29),
    [anon_sym_null] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(29),
    [anon_sym_true] = ACTIONS(31),
    [anon_sym_false] = ACTIONS(31),
    [anon_sym_PERCENT] = ACTIONS(29),
    [anon_sym_EQ_EQ] = ACTIONS(29),
    [anon_sym_BANG_EQ] = ACTIONS(29),
    [anon_sym_LT] = ACTIONS(31),
    [anon_sym_LT_EQ] = ACTIONS(29),
    [anon_sym_GT] = ACTIONS(31),
    [anon_sym_GT_EQ] = ACTIONS(29),
    [anon_sym_AMP_AMP] = ACTIONS(29),
    [anon_sym_PIPE_PIPE] = ACTIONS(29),
    [anon_sym_PLUS] = ACTIONS(31),
    [anon_sym_DASH] = ACTIONS(31),
    [anon_sym_STAR] = ACTIONS(29),
    [anon_sym_SLASH] = ACTIONS(29),
    [anon_sym_DASH_GT] = ACTIONS(29),
    [anon_sym_AMP] = ACTIONS(31),
    [anon_sym_PLUS_PLUS] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(29),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(33),
    [sym_ident] = ACTIONS(35),
    [anon_sym_LPAREN] = ACTIONS(33),
    [anon_sym_RPAREN] = ACTIONS(33),
    [anon_sym_null] = ACTIONS(35),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_true] = ACTIONS(35),
    [anon_sym_false] = ACTIONS(35),
    [anon_sym_PERCENT] = ACTIONS(33),
    [anon_sym_EQ_EQ] = ACTIONS(33),
    [anon_sym_BANG_EQ] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
    [anon_sym_LT_EQ] = ACTIONS(33),
    [anon_sym_GT] = ACTIONS(35),
    [anon_sym_GT_EQ] = ACTIONS(33),
    [anon_sym_AMP_AMP] = ACTIONS(33),
    [anon_sym_PIPE_PIPE] = ACTIONS(33),
    [anon_sym_PLUS] = ACTIONS(35),
    [anon_sym_DASH] = ACTIONS(35),
    [anon_sym_STAR] = ACTIONS(33),
    [anon_sym_SLASH] = ACTIONS(33),
    [anon_sym_DASH_GT] = ACTIONS(33),
    [anon_sym_AMP] = ACTIONS(35),
    [anon_sym_PLUS_PLUS] = ACTIONS(33),
    [anon_sym_AT] = ACTIONS(33),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(37),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(37),
    [sym_ident] = ACTIONS(39),
    [anon_sym_LPAREN] = ACTIONS(37),
    [anon_sym_RPAREN] = ACTIONS(37),
    [anon_sym_null] = ACTIONS(39),
    [anon_sym_BQUOTE] = ACTIONS(37),
    [anon_sym_true] = ACTIONS(39),
    [anon_sym_false] = ACTIONS(39),
    [anon_sym_PERCENT] = ACTIONS(37),
    [anon_sym_EQ_EQ] = ACTIONS(37),
    [anon_sym_BANG_EQ] = ACTIONS(37),
    [anon_sym_LT] = ACTIONS(39),
    [anon_sym_LT_EQ] = ACTIONS(37),
    [anon_sym_GT] = ACTIONS(39),
    [anon_sym_GT_EQ] = ACTIONS(37),
    [anon_sym_AMP_AMP] = ACTIONS(37),
    [anon_sym_PIPE_PIPE] = ACTIONS(37),
    [anon_sym_PLUS] = ACTIONS(39),
    [anon_sym_DASH] = ACTIONS(39),
    [anon_sym_STAR] = ACTIONS(37),
    [anon_sym_SLASH] = ACTIONS(37),
    [anon_sym_DASH_GT] = ACTIONS(37),
    [anon_sym_AMP] = ACTIONS(39),
    [anon_sym_PLUS_PLUS] = ACTIONS(37),
    [anon_sym_AT] = ACTIONS(37),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(41),
    [sym_ident] = ACTIONS(43),
    [anon_sym_LPAREN] = ACTIONS(41),
    [anon_sym_RPAREN] = ACTIONS(41),
    [anon_sym_null] = ACTIONS(43),
    [anon_sym_BQUOTE] = ACTIONS(41),
    [anon_sym_true] = ACTIONS(43),
    [anon_sym_false] = ACTIONS(43),
    [anon_sym_PERCENT] = ACTIONS(41),
    [anon_sym_EQ_EQ] = ACTIONS(41),
    [anon_sym_BANG_EQ] = ACTIONS(41),
    [anon_sym_LT] = ACTIONS(43),
    [anon_sym_LT_EQ] = ACTIONS(41),
    [anon_sym_GT] = ACTIONS(43),
    [anon_sym_GT_EQ] = ACTIONS(41),
    [anon_sym_AMP_AMP] = ACTIONS(41),
    [anon_sym_PIPE_PIPE] = ACTIONS(41),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_STAR] = ACTIONS(41),
    [anon_sym_SLASH] = ACTIONS(41),
    [anon_sym_DASH_GT] = ACTIONS(41),
    [anon_sym_AMP] = ACTIONS(43),
    [anon_sym_PLUS_PLUS] = ACTIONS(41),
    [anon_sym_AT] = ACTIONS(41),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(45),
    [sym_ident] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(45),
    [anon_sym_RPAREN] = ACTIONS(45),
    [anon_sym_null] = ACTIONS(47),
    [anon_sym_BQUOTE] = ACTIONS(45),
    [anon_sym_true] = ACTIONS(47),
    [anon_sym_false] = ACTIONS(47),
    [anon_sym_PERCENT] = ACTIONS(45),
    [anon_sym_EQ_EQ] = ACTIONS(45),
    [anon_sym_BANG_EQ] = ACTIONS(45),
    [anon_sym_LT] = ACTIONS(47),
    [anon_sym_LT_EQ] = ACTIONS(45),
    [anon_sym_GT] = ACTIONS(47),
    [anon_sym_GT_EQ] = ACTIONS(45),
    [anon_sym_AMP_AMP] = ACTIONS(45),
    [anon_sym_PIPE_PIPE] = ACTIONS(45),
    [anon_sym_PLUS] = ACTIONS(47),
    [anon_sym_DASH] = ACTIONS(47),
    [anon_sym_STAR] = ACTIONS(45),
    [anon_sym_SLASH] = ACTIONS(45),
    [anon_sym_DASH_GT] = ACTIONS(45),
    [anon_sym_AMP] = ACTIONS(47),
    [anon_sym_PLUS_PLUS] = ACTIONS(45),
    [anon_sym_AT] = ACTIONS(45),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(49),
    [sym_ident] = ACTIONS(51),
    [anon_sym_LPAREN] = ACTIONS(49),
    [anon_sym_RPAREN] = ACTIONS(49),
    [anon_sym_null] = ACTIONS(51),
    [anon_sym_BQUOTE] = ACTIONS(49),
    [anon_sym_true] = ACTIONS(51),
    [anon_sym_false] = ACTIONS(51),
    [anon_sym_PERCENT] = ACTIONS(49),
    [anon_sym_EQ_EQ] = ACTIONS(49),
    [anon_sym_BANG_EQ] = ACTIONS(49),
    [anon_sym_LT] = ACTIONS(51),
    [anon_sym_LT_EQ] = ACTIONS(49),
    [anon_sym_GT] = ACTIONS(51),
    [anon_sym_GT_EQ] = ACTIONS(49),
    [anon_sym_AMP_AMP] = ACTIONS(49),
    [anon_sym_PIPE_PIPE] = ACTIONS(49),
    [anon_sym_PLUS] = ACTIONS(51),
    [anon_sym_DASH] = ACTIONS(51),
    [anon_sym_STAR] = ACTIONS(49),
    [anon_sym_SLASH] = ACTIONS(49),
    [anon_sym_DASH_GT] = ACTIONS(49),
    [anon_sym_AMP] = ACTIONS(51),
    [anon_sym_PLUS_PLUS] = ACTIONS(49),
    [anon_sym_AT] = ACTIONS(49),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(53),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(53),
    [sym_ident] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(53),
    [anon_sym_RPAREN] = ACTIONS(53),
    [anon_sym_null] = ACTIONS(55),
    [anon_sym_BQUOTE] = ACTIONS(53),
    [anon_sym_true] = ACTIONS(55),
    [anon_sym_false] = ACTIONS(55),
    [anon_sym_PERCENT] = ACTIONS(53),
    [anon_sym_EQ_EQ] = ACTIONS(53),
    [anon_sym_BANG_EQ] = ACTIONS(53),
    [anon_sym_LT] = ACTIONS(55),
    [anon_sym_LT_EQ] = ACTIONS(53),
    [anon_sym_GT] = ACTIONS(55),
    [anon_sym_GT_EQ] = ACTIONS(53),
    [anon_sym_AMP_AMP] = ACTIONS(53),
    [anon_sym_PIPE_PIPE] = ACTIONS(53),
    [anon_sym_PLUS] = ACTIONS(55),
    [anon_sym_DASH] = ACTIONS(55),
    [anon_sym_STAR] = ACTIONS(53),
    [anon_sym_SLASH] = ACTIONS(53),
    [anon_sym_DASH_GT] = ACTIONS(53),
    [anon_sym_AMP] = ACTIONS(55),
    [anon_sym_PLUS_PLUS] = ACTIONS(53),
    [anon_sym_AT] = ACTIONS(53),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(57),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(57),
    [sym_ident] = ACTIONS(59),
    [anon_sym_LPAREN] = ACTIONS(57),
    [anon_sym_RPAREN] = ACTIONS(57),
    [anon_sym_null] = ACTIONS(59),
    [anon_sym_BQUOTE] = ACTIONS(57),
    [anon_sym_true] = ACTIONS(59),
    [anon_sym_false] = ACTIONS(59),
    [anon_sym_PERCENT] = ACTIONS(57),
    [anon_sym_EQ_EQ] = ACTIONS(57),
    [anon_sym_BANG_EQ] = ACTIONS(57),
    [anon_sym_LT] = ACTIONS(59),
    [anon_sym_LT_EQ] = ACTIONS(57),
    [anon_sym_GT] = ACTIONS(59),
    [anon_sym_GT_EQ] = ACTIONS(57),
    [anon_sym_AMP_AMP] = ACTIONS(57),
    [anon_sym_PIPE_PIPE] = ACTIONS(57),
    [anon_sym_PLUS] = ACTIONS(59),
    [anon_sym_DASH] = ACTIONS(59),
    [anon_sym_STAR] = ACTIONS(57),
    [anon_sym_SLASH] = ACTIONS(57),
    [anon_sym_DASH_GT] = ACTIONS(57),
    [anon_sym_AMP] = ACTIONS(59),
    [anon_sym_PLUS_PLUS] = ACTIONS(57),
    [anon_sym_AT] = ACTIONS(57),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(61),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(61),
    [sym_ident] = ACTIONS(63),
    [anon_sym_LPAREN] = ACTIONS(61),
    [anon_sym_RPAREN] = ACTIONS(61),
    [anon_sym_null] = ACTIONS(63),
    [anon_sym_BQUOTE] = ACTIONS(61),
    [anon_sym_true] = ACTIONS(63),
    [anon_sym_false] = ACTIONS(63),
    [anon_sym_PERCENT] = ACTIONS(61),
    [anon_sym_EQ_EQ] = ACTIONS(61),
    [anon_sym_BANG_EQ] = ACTIONS(61),
    [anon_sym_LT] = ACTIONS(63),
    [anon_sym_LT_EQ] = ACTIONS(61),
    [anon_sym_GT] = ACTIONS(63),
    [anon_sym_GT_EQ] = ACTIONS(61),
    [anon_sym_AMP_AMP] = ACTIONS(61),
    [anon_sym_PIPE_PIPE] = ACTIONS(61),
    [anon_sym_PLUS] = ACTIONS(63),
    [anon_sym_DASH] = ACTIONS(63),
    [anon_sym_STAR] = ACTIONS(61),
    [anon_sym_SLASH] = ACTIONS(61),
    [anon_sym_DASH_GT] = ACTIONS(61),
    [anon_sym_AMP] = ACTIONS(63),
    [anon_sym_PLUS_PLUS] = ACTIONS(61),
    [anon_sym_AT] = ACTIONS(61),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(65),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(65),
    [sym_ident] = ACTIONS(67),
    [anon_sym_LPAREN] = ACTIONS(65),
    [anon_sym_RPAREN] = ACTIONS(65),
    [anon_sym_null] = ACTIONS(67),
    [anon_sym_BQUOTE] = ACTIONS(65),
    [anon_sym_true] = ACTIONS(67),
    [anon_sym_false] = ACTIONS(67),
    [anon_sym_PERCENT] = ACTIONS(65),
    [anon_sym_EQ_EQ] = ACTIONS(65),
    [anon_sym_BANG_EQ] = ACTIONS(65),
    [anon_sym_LT] = ACTIONS(67),
    [anon_sym_LT_EQ] = ACTIONS(65),
    [anon_sym_GT] = ACTIONS(67),
    [anon_sym_GT_EQ] = ACTIONS(65),
    [anon_sym_AMP_AMP] = ACTIONS(65),
    [anon_sym_PIPE_PIPE] = ACTIONS(65),
    [anon_sym_PLUS] = ACTIONS(67),
    [anon_sym_DASH] = ACTIONS(67),
    [anon_sym_STAR] = ACTIONS(65),
    [anon_sym_SLASH] = ACTIONS(65),
    [anon_sym_DASH_GT] = ACTIONS(65),
    [anon_sym_AMP] = ACTIONS(67),
    [anon_sym_PLUS_PLUS] = ACTIONS(65),
    [anon_sym_AT] = ACTIONS(65),
  },
  [13] = {
    [ts_builtin_sym_end] = ACTIONS(69),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(69),
    [sym_ident] = ACTIONS(71),
    [anon_sym_LPAREN] = ACTIONS(69),
    [anon_sym_RPAREN] = ACTIONS(69),
    [anon_sym_null] = ACTIONS(71),
    [anon_sym_BQUOTE] = ACTIONS(69),
    [anon_sym_true] = ACTIONS(71),
    [anon_sym_false] = ACTIONS(71),
    [anon_sym_PERCENT] = ACTIONS(69),
    [anon_sym_EQ_EQ] = ACTIONS(69),
    [anon_sym_BANG_EQ] = ACTIONS(69),
    [anon_sym_LT] = ACTIONS(71),
    [anon_sym_LT_EQ] = ACTIONS(69),
    [anon_sym_GT] = ACTIONS(71),
    [anon_sym_GT_EQ] = ACTIONS(69),
    [anon_sym_AMP_AMP] = ACTIONS(69),
    [anon_sym_PIPE_PIPE] = ACTIONS(69),
    [anon_sym_PLUS] = ACTIONS(71),
    [anon_sym_DASH] = ACTIONS(71),
    [anon_sym_STAR] = ACTIONS(69),
    [anon_sym_SLASH] = ACTIONS(69),
    [anon_sym_DASH_GT] = ACTIONS(69),
    [anon_sym_AMP] = ACTIONS(71),
    [anon_sym_PLUS_PLUS] = ACTIONS(69),
    [anon_sym_AT] = ACTIONS(69),
  },
  [14] = {
    [ts_builtin_sym_end] = ACTIONS(73),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(73),
    [sym_ident] = ACTIONS(75),
    [anon_sym_LPAREN] = ACTIONS(73),
    [anon_sym_RPAREN] = ACTIONS(73),
    [anon_sym_null] = ACTIONS(75),
    [anon_sym_BQUOTE] = ACTIONS(73),
    [anon_sym_true] = ACTIONS(75),
    [anon_sym_false] = ACTIONS(75),
    [anon_sym_PERCENT] = ACTIONS(73),
    [anon_sym_EQ_EQ] = ACTIONS(73),
    [anon_sym_BANG_EQ] = ACTIONS(73),
    [anon_sym_LT] = ACTIONS(75),
    [anon_sym_LT_EQ] = ACTIONS(73),
    [anon_sym_GT] = ACTIONS(75),
    [anon_sym_GT_EQ] = ACTIONS(73),
    [anon_sym_AMP_AMP] = ACTIONS(73),
    [anon_sym_PIPE_PIPE] = ACTIONS(73),
    [anon_sym_PLUS] = ACTIONS(75),
    [anon_sym_DASH] = ACTIONS(75),
    [anon_sym_STAR] = ACTIONS(73),
    [anon_sym_SLASH] = ACTIONS(73),
    [anon_sym_DASH_GT] = ACTIONS(73),
    [anon_sym_AMP] = ACTIONS(75),
    [anon_sym_PLUS_PLUS] = ACTIONS(73),
    [anon_sym_AT] = ACTIONS(73),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 18,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(33), 1,
      sym_infix_expr,
    STATE(48), 1,
      sym_uni_term,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [60] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(30), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [117] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(32), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [174] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(35), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [231] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(27), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [288] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(31), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [345] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(28), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [402] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(38), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [459] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(29), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [516] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(37), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [573] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(36), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [630] = 17,
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
      anon_sym_PERCENT,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_BANG,
    STATE(2), 1,
      sym_applicative,
    STATE(14), 1,
      sym_atom,
    STATE(39), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
    STATE(13), 2,
      sym_type_array,
      sym_record_operand,
    STATE(34), 2,
      sym_infix_b_op,
      sym_infix_u_op,
  [687] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(77), 13,
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
  [713] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_AMP_AMP,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(83), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(91), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(81), 4,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [753] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(81), 11,
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
  [781] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(91), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(81), 9,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [815] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_AMP_AMP,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(101), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(103), 1,
      anon_sym_DASH_GT,
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
    ACTIONS(91), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
  [859] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(81), 11,
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
  [887] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_AMP_AMP,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(101), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(103), 1,
      anon_sym_DASH_GT,
    ACTIONS(83), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(91), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(105), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
  [931] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(25), 13,
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
  [957] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 5,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_AMP,
    ACTIONS(81), 9,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [987] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(79), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
    ACTIONS(77), 9,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [1019] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(83), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(91), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(81), 5,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [1057] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(91), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(99), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(81), 9,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [1091] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_AMP,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(87), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(91), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(97), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(81), 7,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
  [1127] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      anon_sym_PERCENT,
    STATE(12), 1,
      sym_record_operand,
    STATE(14), 1,
      sym_atom,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_bool,
      sym_builtin,
  [1161] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 1,
      sym_ident,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    STATE(10), 1,
      sym_enum_tag,
    STATE(11), 1,
      sym_static_string,
  [1177] = 3,
    ACTIONS(111), 1,
      sym_comment,
    ACTIONS(113), 1,
      sym_chunk_literal,
    ACTIONS(115), 1,
      anon_sym_DQUOTE,
  [1187] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    STATE(3), 1,
      sym_static_string,
  [1197] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(117), 1,
      sym_ident,
  [1204] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      ts_builtin_sym_end,
  [1211] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_DQUOTE,
  [1218] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 1,
      ts_builtin_sym_end,
  [1225] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 1,
      anon_sym_RPAREN,
  [1232] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      anon_sym_PERCENT,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(15)] = 0,
  [SMALL_STATE(16)] = 60,
  [SMALL_STATE(17)] = 117,
  [SMALL_STATE(18)] = 174,
  [SMALL_STATE(19)] = 231,
  [SMALL_STATE(20)] = 288,
  [SMALL_STATE(21)] = 345,
  [SMALL_STATE(22)] = 402,
  [SMALL_STATE(23)] = 459,
  [SMALL_STATE(24)] = 516,
  [SMALL_STATE(25)] = 573,
  [SMALL_STATE(26)] = 630,
  [SMALL_STATE(27)] = 687,
  [SMALL_STATE(28)] = 713,
  [SMALL_STATE(29)] = 753,
  [SMALL_STATE(30)] = 781,
  [SMALL_STATE(31)] = 815,
  [SMALL_STATE(32)] = 859,
  [SMALL_STATE(33)] = 887,
  [SMALL_STATE(34)] = 931,
  [SMALL_STATE(35)] = 957,
  [SMALL_STATE(36)] = 987,
  [SMALL_STATE(37)] = 1019,
  [SMALL_STATE(38)] = 1057,
  [SMALL_STATE(39)] = 1091,
  [SMALL_STATE(40)] = 1127,
  [SMALL_STATE(41)] = 1161,
  [SMALL_STATE(42)] = 1177,
  [SMALL_STATE(43)] = 1187,
  [SMALL_STATE(44)] = 1197,
  [SMALL_STATE(45)] = 1204,
  [SMALL_STATE(46)] = 1211,
  [SMALL_STATE(47)] = 1218,
  [SMALL_STATE(48)] = 1225,
  [SMALL_STATE(49)] = 1232,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_expr, 1),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_expr, 1),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_applicative, 2),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_applicative, 2),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 1),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_string, 3),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_string, 3),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_builtin, 3),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_builtin, 3),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 3),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 3),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool, 1),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool, 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_string, 2),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_string, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 2),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 2),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_tag, 1),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum_tag, 1),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_array, 2),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_array, 2),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_applicative, 1),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_applicative, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_operand, 1),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_record_operand, 1),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_u_op, 2, .production_id = 1),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_u_op, 2, .production_id = 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_b_op, 3, .production_id = 2),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_b_op, 3, .production_id = 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uni_term, 1),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [119] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term, 1),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
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
