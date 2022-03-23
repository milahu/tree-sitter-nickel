#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 44
#define LARGE_STATE_COUNT 12
#define SYMBOL_COUNT 46
#define ALIAS_COUNT 0
#define TOKEN_COUNT 35
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 3

enum {
  sym_keyword = 1,
  sym_comment = 2,
  anon_sym_BANG = 3,
  anon_sym_DASH = 4,
  anon_sym_EQ_EQ = 5,
  anon_sym_BANG_EQ = 6,
  anon_sym_LT = 7,
  anon_sym_LT_EQ = 8,
  anon_sym_GT = 9,
  anon_sym_GT_EQ = 10,
  anon_sym_AMP_AMP = 11,
  anon_sym_PIPE_PIPE = 12,
  anon_sym_PLUS = 13,
  anon_sym_STAR = 14,
  anon_sym_SLASH = 15,
  anon_sym_DASH_GT = 16,
  anon_sym_AMP = 17,
  anon_sym_PLUS_PLUS = 18,
  anon_sym_AT = 19,
  anon_sym_import = 20,
  anon_sym_DQUOTE = 21,
  anon_sym_Array = 22,
  anon_sym_LPAREN = 23,
  anon_sym_RPAREN = 24,
  anon_sym_null = 25,
  sym_num_literal = 26,
  anon_sym_true = 27,
  anon_sym_false = 28,
  sym_chunk_literal = 29,
  sym__string_fragment = 30,
  sym__multistring_start = 31,
  sym__multistring_part_fixed = 32,
  sym__multistring_ipol_start = 33,
  sym__multistring_end = 34,
  sym_term = 35,
  sym_uni_term = 36,
  sym_infix_expr = 37,
  sym_infix_u_op = 38,
  sym_infix_b_op = 39,
  sym_applicative = 40,
  sym_static_string = 41,
  sym_type_array = 42,
  sym_record_operand = 43,
  sym_atom = 44,
  sym_bool = 45,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_keyword] = "keyword",
  [sym_comment] = "comment",
  [anon_sym_BANG] = "!",
  [anon_sym_DASH] = "-",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_LT] = "<",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_AMP] = "&",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_AT] = "@",
  [anon_sym_import] = "import",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_Array] = "Array",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_null] = "null",
  [sym_num_literal] = "num_literal",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_chunk_literal] = "chunk_literal",
  [sym__string_fragment] = "_string_fragment",
  [sym__multistring_start] = "_multistring_start",
  [sym__multistring_part_fixed] = "_multistring_part_fixed",
  [sym__multistring_ipol_start] = "_multistring_ipol_start",
  [sym__multistring_end] = "_multistring_end",
  [sym_term] = "term",
  [sym_uni_term] = "uni_term",
  [sym_infix_expr] = "infix_expr",
  [sym_infix_u_op] = "infix_u_op",
  [sym_infix_b_op] = "infix_b_op",
  [sym_applicative] = "applicative",
  [sym_static_string] = "static_string",
  [sym_type_array] = "type_array",
  [sym_record_operand] = "record_operand",
  [sym_atom] = "atom",
  [sym_bool] = "bool",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_keyword] = sym_keyword,
  [sym_comment] = sym_comment,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_PLUS_PLUS] = anon_sym_PLUS_PLUS,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_Array] = anon_sym_Array,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_null] = anon_sym_null,
  [sym_num_literal] = sym_num_literal,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_chunk_literal] = sym_chunk_literal,
  [sym__string_fragment] = sym__string_fragment,
  [sym__multistring_start] = sym__multistring_start,
  [sym__multistring_part_fixed] = sym__multistring_part_fixed,
  [sym__multistring_ipol_start] = sym__multistring_ipol_start,
  [sym__multistring_end] = sym__multistring_end,
  [sym_term] = sym_term,
  [sym_uni_term] = sym_uni_term,
  [sym_infix_expr] = sym_infix_expr,
  [sym_infix_u_op] = sym_infix_u_op,
  [sym_infix_b_op] = sym_infix_b_op,
  [sym_applicative] = sym_applicative,
  [sym_static_string] = sym_static_string,
  [sym_type_array] = sym_type_array,
  [sym_record_operand] = sym_record_operand,
  [sym_atom] = sym_atom,
  [sym_bool] = sym_bool,
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
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
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
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
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
  [sym_num_literal] = {
    .visible = true,
    .named = true,
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
  [sym_infix_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_infix_u_op] = {
    .visible = true,
    .named = true,
  },
  [sym_infix_b_op] = {
    .visible = true,
    .named = true,
  },
  [sym_applicative] = {
    .visible = true,
    .named = true,
  },
  [sym_static_string] = {
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
      if (eof) ADVANCE(45);
      if (lookahead == '!') ADVANCE(49);
      if (lookahead == '"') ADVANCE(67);
      if (lookahead == '#') ADVANCE(46);
      if (lookahead == '&') ADVANCE(64);
      if (lookahead == '(') ADVANCE(69);
      if (lookahead == ')') ADVANCE(70);
      if (lookahead == '*') ADVANCE(61);
      if (lookahead == '+') ADVANCE(60);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '.') ADVANCE(43);
      if (lookahead == '/') ADVANCE(62);
      if (lookahead == '<') ADVANCE(54);
      if (lookahead == '=') ADVANCE(3);
      if (lookahead == '>') ADVANCE(56);
      if (lookahead == '@') ADVANCE(66);
      if (lookahead == 'A') ADVANCE(31);
      if (lookahead == 'd') ADVANCE(10);
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(13);
      if (lookahead == 'm') ADVANCE(15);
      if (lookahead == 'n') ADVANCE(36);
      if (lookahead == 's') ADVANCE(39);
      if (lookahead == 't') ADVANCE(19);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(48);
      if (lookahead == '#') ADVANCE(46);
      if (lookahead == '(') ADVANCE(69);
      if (lookahead == '-') ADVANCE(50);
      if (lookahead == '.') ADVANCE(43);
      if (lookahead == 'A') ADVANCE(31);
      if (lookahead == 'd') ADVANCE(10);
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(13);
      if (lookahead == 'm') ADVANCE(15);
      if (lookahead == 'n') ADVANCE(36);
      if (lookahead == 's') ADVANCE(39);
      if (lookahead == 't') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 2:
      if (lookahead == '=') ADVANCE(53);
      END_STATE();
    case 3:
      if (lookahead == '=') ADVANCE(52);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(21);
      if (lookahead == 'o') ADVANCE(32);
      if (lookahead == 'u') ADVANCE(25);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(40);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(37);
      END_STATE();
    case 8:
      if (lookahead == 'c') ADVANCE(47);
      END_STATE();
    case 9:
      if (lookahead == 'c') ADVANCE(18);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(16);
      if (lookahead == 'o') ADVANCE(8);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(6);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 16:
      if (lookahead == 'f') ADVANCE(7);
      END_STATE();
    case 17:
      if (lookahead == 'g') ADVANCE(12);
      END_STATE();
    case 18:
      if (lookahead == 'h') ADVANCE(47);
      END_STATE();
    case 19:
      if (lookahead == 'h') ADVANCE(11);
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 20:
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(47);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(34);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(22);
      END_STATE();
    case 25:
      if (lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(28);
      END_STATE();
    case 27:
      if (lookahead == 'p') ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 29:
      if (lookahead == 'r') ADVANCE(5);
      END_STATE();
    case 30:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(12);
      END_STATE();
    case 34:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 35:
      if (lookahead == 't') ADVANCE(9);
      END_STATE();
    case 36:
      if (lookahead == 'u') ADVANCE(24);
      END_STATE();
    case 37:
      if (lookahead == 'u') ADVANCE(23);
      END_STATE();
    case 38:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 39:
      if (lookahead == 'w') ADVANCE(20);
      END_STATE();
    case 40:
      if (lookahead == 'y') ADVANCE(68);
      END_STATE();
    case 41:
      if (lookahead == '|') ADVANCE(59);
      END_STATE();
    case 42:
      if (lookahead == 'f' ||
          lookahead == 'n') ADVANCE(47);
      if (lookahead == 'm') ADVANCE(27);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 44:
      if (eof) ADVANCE(45);
      if (lookahead == '!') ADVANCE(2);
      if (lookahead == '#') ADVANCE(46);
      if (lookahead == '&') ADVANCE(64);
      if (lookahead == '(') ADVANCE(69);
      if (lookahead == ')') ADVANCE(70);
      if (lookahead == '*') ADVANCE(61);
      if (lookahead == '+') ADVANCE(60);
      if (lookahead == '-') ADVANCE(51);
      if (lookahead == '.') ADVANCE(43);
      if (lookahead == '/') ADVANCE(62);
      if (lookahead == '<') ADVANCE(54);
      if (lookahead == '=') ADVANCE(3);
      if (lookahead == '>') ADVANCE(56);
      if (lookahead == '@') ADVANCE(66);
      if (lookahead == 'd') ADVANCE(10);
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(13);
      if (lookahead == 'm') ADVANCE(15);
      if (lookahead == 'n') ADVANCE(36);
      if (lookahead == 's') ADVANCE(39);
      if (lookahead == 't') ADVANCE(19);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(53);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(63);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(55);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(57);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(65);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '&') ADVANCE(58);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_Array);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_num_literal);
      if (lookahead == '.') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_num_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_chunk_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
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
  [2] = {.lex_state = 44},
  [3] = {.lex_state = 44},
  [4] = {.lex_state = 44},
  [5] = {.lex_state = 44},
  [6] = {.lex_state = 44},
  [7] = {.lex_state = 44},
  [8] = {.lex_state = 44},
  [9] = {.lex_state = 44},
  [10] = {.lex_state = 44},
  [11] = {.lex_state = 44},
  [12] = {.lex_state = 44},
  [13] = {.lex_state = 44},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 44},
  [16] = {.lex_state = 44},
  [17] = {.lex_state = 44},
  [18] = {.lex_state = 44},
  [19] = {.lex_state = 44},
  [20] = {.lex_state = 44},
  [21] = {.lex_state = 44},
  [22] = {.lex_state = 44},
  [23] = {.lex_state = 44},
  [24] = {.lex_state = 44},
  [25] = {.lex_state = 44},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 73},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
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
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_Array] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [sym_num_literal] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym__string_fragment] = ACTIONS(1),
    [sym__multistring_start] = ACTIONS(1),
    [sym__multistring_part_fixed] = ACTIONS(1),
    [sym__multistring_ipol_start] = ACTIONS(1),
    [sym__multistring_end] = ACTIONS(1),
  },
  [1] = {
    [sym_term] = STATE(41),
    [sym_uni_term] = STATE(43),
    [sym_infix_expr] = STATE(12),
    [sym_infix_u_op] = STATE(17),
    [sym_infix_b_op] = STATE(17),
    [sym_applicative] = STATE(2),
    [sym_type_array] = STATE(7),
    [sym_record_operand] = STATE(7),
    [sym_atom] = STATE(10),
    [sym_bool] = STATE(8),
    [sym_comment] = ACTIONS(3),
    [anon_sym_BANG] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_import] = ACTIONS(9),
    [anon_sym_Array] = ACTIONS(11),
    [anon_sym_LPAREN] = ACTIONS(13),
    [anon_sym_null] = ACTIONS(15),
    [sym_num_literal] = ACTIONS(15),
    [anon_sym_true] = ACTIONS(17),
    [anon_sym_false] = ACTIONS(17),
  },
  [2] = {
    [sym_record_operand] = STATE(3),
    [sym_atom] = STATE(10),
    [sym_bool] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(19),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(21),
    [anon_sym_EQ_EQ] = ACTIONS(19),
    [anon_sym_BANG_EQ] = ACTIONS(19),
    [anon_sym_LT] = ACTIONS(21),
    [anon_sym_LT_EQ] = ACTIONS(19),
    [anon_sym_GT] = ACTIONS(21),
    [anon_sym_GT_EQ] = ACTIONS(19),
    [anon_sym_AMP_AMP] = ACTIONS(19),
    [anon_sym_PIPE_PIPE] = ACTIONS(19),
    [anon_sym_PLUS] = ACTIONS(21),
    [anon_sym_STAR] = ACTIONS(19),
    [anon_sym_SLASH] = ACTIONS(19),
    [anon_sym_DASH_GT] = ACTIONS(19),
    [anon_sym_AMP] = ACTIONS(21),
    [anon_sym_PLUS_PLUS] = ACTIONS(19),
    [anon_sym_AT] = ACTIONS(19),
    [anon_sym_LPAREN] = ACTIONS(13),
    [anon_sym_RPAREN] = ACTIONS(19),
    [anon_sym_null] = ACTIONS(15),
    [sym_num_literal] = ACTIONS(15),
    [anon_sym_true] = ACTIONS(17),
    [anon_sym_false] = ACTIONS(17),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(25),
    [anon_sym_EQ_EQ] = ACTIONS(23),
    [anon_sym_BANG_EQ] = ACTIONS(23),
    [anon_sym_LT] = ACTIONS(25),
    [anon_sym_LT_EQ] = ACTIONS(23),
    [anon_sym_GT] = ACTIONS(25),
    [anon_sym_GT_EQ] = ACTIONS(23),
    [anon_sym_AMP_AMP] = ACTIONS(23),
    [anon_sym_PIPE_PIPE] = ACTIONS(23),
    [anon_sym_PLUS] = ACTIONS(25),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_SLASH] = ACTIONS(23),
    [anon_sym_DASH_GT] = ACTIONS(23),
    [anon_sym_AMP] = ACTIONS(25),
    [anon_sym_PLUS_PLUS] = ACTIONS(23),
    [anon_sym_AT] = ACTIONS(23),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(23),
    [sym_num_literal] = ACTIONS(23),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(29),
    [anon_sym_EQ_EQ] = ACTIONS(27),
    [anon_sym_BANG_EQ] = ACTIONS(27),
    [anon_sym_LT] = ACTIONS(29),
    [anon_sym_LT_EQ] = ACTIONS(27),
    [anon_sym_GT] = ACTIONS(29),
    [anon_sym_GT_EQ] = ACTIONS(27),
    [anon_sym_AMP_AMP] = ACTIONS(27),
    [anon_sym_PIPE_PIPE] = ACTIONS(27),
    [anon_sym_PLUS] = ACTIONS(29),
    [anon_sym_STAR] = ACTIONS(27),
    [anon_sym_SLASH] = ACTIONS(27),
    [anon_sym_DASH_GT] = ACTIONS(27),
    [anon_sym_AMP] = ACTIONS(29),
    [anon_sym_PLUS_PLUS] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(27),
    [anon_sym_LPAREN] = ACTIONS(27),
    [anon_sym_RPAREN] = ACTIONS(27),
    [anon_sym_null] = ACTIONS(27),
    [sym_num_literal] = ACTIONS(27),
    [anon_sym_true] = ACTIONS(27),
    [anon_sym_false] = ACTIONS(27),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(31),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(33),
    [anon_sym_EQ_EQ] = ACTIONS(31),
    [anon_sym_BANG_EQ] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
    [anon_sym_LT_EQ] = ACTIONS(31),
    [anon_sym_GT] = ACTIONS(33),
    [anon_sym_GT_EQ] = ACTIONS(31),
    [anon_sym_AMP_AMP] = ACTIONS(31),
    [anon_sym_PIPE_PIPE] = ACTIONS(31),
    [anon_sym_PLUS] = ACTIONS(33),
    [anon_sym_STAR] = ACTIONS(31),
    [anon_sym_SLASH] = ACTIONS(31),
    [anon_sym_DASH_GT] = ACTIONS(31),
    [anon_sym_AMP] = ACTIONS(33),
    [anon_sym_PLUS_PLUS] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LPAREN] = ACTIONS(31),
    [anon_sym_RPAREN] = ACTIONS(31),
    [anon_sym_null] = ACTIONS(31),
    [sym_num_literal] = ACTIONS(31),
    [anon_sym_true] = ACTIONS(31),
    [anon_sym_false] = ACTIONS(31),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(37),
    [anon_sym_EQ_EQ] = ACTIONS(35),
    [anon_sym_BANG_EQ] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
    [anon_sym_LT_EQ] = ACTIONS(35),
    [anon_sym_GT] = ACTIONS(37),
    [anon_sym_GT_EQ] = ACTIONS(35),
    [anon_sym_AMP_AMP] = ACTIONS(35),
    [anon_sym_PIPE_PIPE] = ACTIONS(35),
    [anon_sym_PLUS] = ACTIONS(37),
    [anon_sym_STAR] = ACTIONS(35),
    [anon_sym_SLASH] = ACTIONS(35),
    [anon_sym_DASH_GT] = ACTIONS(35),
    [anon_sym_AMP] = ACTIONS(37),
    [anon_sym_PLUS_PLUS] = ACTIONS(35),
    [anon_sym_AT] = ACTIONS(35),
    [anon_sym_LPAREN] = ACTIONS(35),
    [anon_sym_RPAREN] = ACTIONS(35),
    [anon_sym_null] = ACTIONS(35),
    [sym_num_literal] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(35),
    [anon_sym_false] = ACTIONS(35),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(41),
    [anon_sym_EQ_EQ] = ACTIONS(39),
    [anon_sym_BANG_EQ] = ACTIONS(39),
    [anon_sym_LT] = ACTIONS(41),
    [anon_sym_LT_EQ] = ACTIONS(39),
    [anon_sym_GT] = ACTIONS(41),
    [anon_sym_GT_EQ] = ACTIONS(39),
    [anon_sym_AMP_AMP] = ACTIONS(39),
    [anon_sym_PIPE_PIPE] = ACTIONS(39),
    [anon_sym_PLUS] = ACTIONS(41),
    [anon_sym_STAR] = ACTIONS(39),
    [anon_sym_SLASH] = ACTIONS(39),
    [anon_sym_DASH_GT] = ACTIONS(39),
    [anon_sym_AMP] = ACTIONS(41),
    [anon_sym_PLUS_PLUS] = ACTIONS(39),
    [anon_sym_AT] = ACTIONS(39),
    [anon_sym_LPAREN] = ACTIONS(39),
    [anon_sym_RPAREN] = ACTIONS(39),
    [anon_sym_null] = ACTIONS(39),
    [sym_num_literal] = ACTIONS(39),
    [anon_sym_true] = ACTIONS(39),
    [anon_sym_false] = ACTIONS(39),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(45),
    [anon_sym_EQ_EQ] = ACTIONS(43),
    [anon_sym_BANG_EQ] = ACTIONS(43),
    [anon_sym_LT] = ACTIONS(45),
    [anon_sym_LT_EQ] = ACTIONS(43),
    [anon_sym_GT] = ACTIONS(45),
    [anon_sym_GT_EQ] = ACTIONS(43),
    [anon_sym_AMP_AMP] = ACTIONS(43),
    [anon_sym_PIPE_PIPE] = ACTIONS(43),
    [anon_sym_PLUS] = ACTIONS(45),
    [anon_sym_STAR] = ACTIONS(43),
    [anon_sym_SLASH] = ACTIONS(43),
    [anon_sym_DASH_GT] = ACTIONS(43),
    [anon_sym_AMP] = ACTIONS(45),
    [anon_sym_PLUS_PLUS] = ACTIONS(43),
    [anon_sym_AT] = ACTIONS(43),
    [anon_sym_LPAREN] = ACTIONS(43),
    [anon_sym_RPAREN] = ACTIONS(43),
    [anon_sym_null] = ACTIONS(43),
    [sym_num_literal] = ACTIONS(43),
    [anon_sym_true] = ACTIONS(43),
    [anon_sym_false] = ACTIONS(43),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(49),
    [anon_sym_EQ_EQ] = ACTIONS(47),
    [anon_sym_BANG_EQ] = ACTIONS(47),
    [anon_sym_LT] = ACTIONS(49),
    [anon_sym_LT_EQ] = ACTIONS(47),
    [anon_sym_GT] = ACTIONS(49),
    [anon_sym_GT_EQ] = ACTIONS(47),
    [anon_sym_AMP_AMP] = ACTIONS(47),
    [anon_sym_PIPE_PIPE] = ACTIONS(47),
    [anon_sym_PLUS] = ACTIONS(49),
    [anon_sym_STAR] = ACTIONS(47),
    [anon_sym_SLASH] = ACTIONS(47),
    [anon_sym_DASH_GT] = ACTIONS(47),
    [anon_sym_AMP] = ACTIONS(49),
    [anon_sym_PLUS_PLUS] = ACTIONS(47),
    [anon_sym_AT] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(47),
    [anon_sym_RPAREN] = ACTIONS(47),
    [anon_sym_null] = ACTIONS(47),
    [sym_num_literal] = ACTIONS(47),
    [anon_sym_true] = ACTIONS(47),
    [anon_sym_false] = ACTIONS(47),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(51),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(53),
    [anon_sym_EQ_EQ] = ACTIONS(51),
    [anon_sym_BANG_EQ] = ACTIONS(51),
    [anon_sym_LT] = ACTIONS(53),
    [anon_sym_LT_EQ] = ACTIONS(51),
    [anon_sym_GT] = ACTIONS(53),
    [anon_sym_GT_EQ] = ACTIONS(51),
    [anon_sym_AMP_AMP] = ACTIONS(51),
    [anon_sym_PIPE_PIPE] = ACTIONS(51),
    [anon_sym_PLUS] = ACTIONS(53),
    [anon_sym_STAR] = ACTIONS(51),
    [anon_sym_SLASH] = ACTIONS(51),
    [anon_sym_DASH_GT] = ACTIONS(51),
    [anon_sym_AMP] = ACTIONS(53),
    [anon_sym_PLUS_PLUS] = ACTIONS(51),
    [anon_sym_AT] = ACTIONS(51),
    [anon_sym_LPAREN] = ACTIONS(51),
    [anon_sym_RPAREN] = ACTIONS(51),
    [anon_sym_null] = ACTIONS(51),
    [sym_num_literal] = ACTIONS(51),
    [anon_sym_true] = ACTIONS(51),
    [anon_sym_false] = ACTIONS(51),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(55),
    [sym_comment] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(57),
    [anon_sym_EQ_EQ] = ACTIONS(55),
    [anon_sym_BANG_EQ] = ACTIONS(55),
    [anon_sym_LT] = ACTIONS(57),
    [anon_sym_LT_EQ] = ACTIONS(55),
    [anon_sym_GT] = ACTIONS(57),
    [anon_sym_GT_EQ] = ACTIONS(55),
    [anon_sym_AMP_AMP] = ACTIONS(55),
    [anon_sym_PIPE_PIPE] = ACTIONS(55),
    [anon_sym_PLUS] = ACTIONS(57),
    [anon_sym_STAR] = ACTIONS(55),
    [anon_sym_SLASH] = ACTIONS(55),
    [anon_sym_DASH_GT] = ACTIONS(55),
    [anon_sym_AMP] = ACTIONS(57),
    [anon_sym_PLUS_PLUS] = ACTIONS(55),
    [anon_sym_AT] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(55),
    [anon_sym_RPAREN] = ACTIONS(55),
    [anon_sym_null] = ACTIONS(55),
    [sym_num_literal] = ACTIONS(55),
    [anon_sym_true] = ACTIONS(55),
    [anon_sym_false] = ACTIONS(55),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(69), 1,
      anon_sym_AMP_AMP,
    ACTIONS(71), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(75), 1,
      anon_sym_DASH_GT,
    ACTIONS(77), 1,
      anon_sym_AMP,
    ACTIONS(59), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(63), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(65), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(67), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
  [44] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(81), 9,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [74] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(12), 1,
      sym_infix_expr,
    STATE(42), 1,
      sym_uni_term,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [124] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(81), 11,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [152] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(77), 1,
      anon_sym_AMP,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(81), 9,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [186] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(21), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(19), 13,
      ts_builtin_sym_end,
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
      anon_sym_RPAREN,
  [212] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(87), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
    ACTIONS(85), 9,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [244] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(85), 13,
      ts_builtin_sym_end,
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
      anon_sym_RPAREN,
  [270] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(69), 1,
      anon_sym_AMP_AMP,
    ACTIONS(71), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(75), 1,
      anon_sym_DASH_GT,
    ACTIONS(77), 1,
      anon_sym_AMP,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(63), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(65), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(67), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(81), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
  [314] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(81), 11,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [342] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(69), 1,
      anon_sym_AMP_AMP,
    ACTIONS(77), 1,
      anon_sym_AMP,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(63), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(65), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(67), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(81), 4,
      ts_builtin_sym_end,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [382] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(77), 1,
      anon_sym_AMP,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(63), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(65), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(67), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(81), 5,
      ts_builtin_sym_end,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [420] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(77), 1,
      anon_sym_AMP,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(81), 9,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [454] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(77), 1,
      anon_sym_AMP,
    ACTIONS(61), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(67), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(73), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(79), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(81), 7,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [490] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(21), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [537] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(20), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [584] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(16), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [631] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(15), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [678] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(18), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [725] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(22), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [772] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(23), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [819] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(24), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [866] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(25), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [913] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(13), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [960] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      anon_sym_BANG,
    ACTIONS(7), 1,
      anon_sym_DASH,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(11), 1,
      anon_sym_Array,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(19), 1,
      sym_infix_expr,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [1007] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_LPAREN,
    STATE(8), 1,
      sym_bool,
    STATE(10), 1,
      sym_atom,
    STATE(11), 1,
      sym_record_operand,
    ACTIONS(15), 2,
      anon_sym_null,
      sym_num_literal,
    ACTIONS(17), 2,
      anon_sym_true,
      anon_sym_false,
  [1031] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_DQUOTE,
    STATE(3), 1,
      sym_static_string,
  [1041] = 3,
    ACTIONS(91), 1,
      sym_comment,
    ACTIONS(93), 1,
      anon_sym_DQUOTE,
    ACTIONS(95), 1,
      sym_chunk_literal,
  [1051] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 1,
      anon_sym_DQUOTE,
  [1058] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 1,
      ts_builtin_sym_end,
  [1065] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(101), 1,
      anon_sym_RPAREN,
  [1072] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(12)] = 0,
  [SMALL_STATE(13)] = 44,
  [SMALL_STATE(14)] = 74,
  [SMALL_STATE(15)] = 124,
  [SMALL_STATE(16)] = 152,
  [SMALL_STATE(17)] = 186,
  [SMALL_STATE(18)] = 212,
  [SMALL_STATE(19)] = 244,
  [SMALL_STATE(20)] = 270,
  [SMALL_STATE(21)] = 314,
  [SMALL_STATE(22)] = 342,
  [SMALL_STATE(23)] = 382,
  [SMALL_STATE(24)] = 420,
  [SMALL_STATE(25)] = 454,
  [SMALL_STATE(26)] = 490,
  [SMALL_STATE(27)] = 537,
  [SMALL_STATE(28)] = 584,
  [SMALL_STATE(29)] = 631,
  [SMALL_STATE(30)] = 678,
  [SMALL_STATE(31)] = 725,
  [SMALL_STATE(32)] = 772,
  [SMALL_STATE(33)] = 819,
  [SMALL_STATE(34)] = 866,
  [SMALL_STATE(35)] = 913,
  [SMALL_STATE(36)] = 960,
  [SMALL_STATE(37)] = 1007,
  [SMALL_STATE(38)] = 1031,
  [SMALL_STATE(39)] = 1041,
  [SMALL_STATE(40)] = 1051,
  [SMALL_STATE(41)] = 1058,
  [SMALL_STATE(42)] = 1065,
  [SMALL_STATE(43)] = 1072,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_expr, 1),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_expr, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_applicative, 2),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_applicative, 2),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_string, 3),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_string, 3),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 3),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 3),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_string, 2),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_string, 2),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_applicative, 1),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_applicative, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 1),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool, 1),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_operand, 1),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_record_operand, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_array, 2),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_array, 2),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uni_term, 1),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_b_op, 3, .production_id = 2),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_b_op, 3, .production_id = 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_u_op, 2, .production_id = 1),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_u_op, 2, .production_id = 1),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [99] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term, 1),
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
