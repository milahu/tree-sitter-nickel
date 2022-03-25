#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 44
#define LARGE_STATE_COUNT 12
#define SYMBOL_COUNT 47
#define ALIAS_COUNT 0
#define TOKEN_COUNT 36
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 3

enum {
  sym_keyword = 1,
  sym_comment = 2,
  sym_num_literal = 3,
  sym_ident = 4,
  anon_sym_BANG = 5,
  anon_sym_DASH = 6,
  anon_sym_EQ_EQ = 7,
  anon_sym_BANG_EQ = 8,
  anon_sym_LT = 9,
  anon_sym_LT_EQ = 10,
  anon_sym_GT = 11,
  anon_sym_GT_EQ = 12,
  anon_sym_AMP_AMP = 13,
  anon_sym_PIPE_PIPE = 14,
  anon_sym_PLUS = 15,
  anon_sym_STAR = 16,
  anon_sym_SLASH = 17,
  anon_sym_DASH_GT = 18,
  anon_sym_AMP = 19,
  anon_sym_PLUS_PLUS = 20,
  anon_sym_AT = 21,
  anon_sym_import = 22,
  anon_sym_DQUOTE = 23,
  anon_sym_Array = 24,
  anon_sym_LPAREN = 25,
  anon_sym_RPAREN = 26,
  anon_sym_null = 27,
  anon_sym_true = 28,
  anon_sym_false = 29,
  sym_chunk_literal = 30,
  sym__string_fragment = 31,
  sym__multistring_start = 32,
  sym__multistring_part_fixed = 33,
  sym__multistring_ipol_start = 34,
  sym__multistring_end = 35,
  sym_term = 36,
  sym_uni_term = 37,
  sym_infix_expr = 38,
  sym_infix_u_op = 39,
  sym_infix_b_op = 40,
  sym_applicative = 41,
  sym_static_string = 42,
  sym_type_array = 43,
  sym_record_operand = 44,
  sym_atom = 45,
  sym_bool = 46,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_keyword] = "keyword",
  [sym_comment] = "comment",
  [sym_num_literal] = "num_literal",
  [sym_ident] = "ident",
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
  [sym_num_literal] = sym_num_literal,
  [sym_ident] = sym_ident,
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
  [sym_num_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_ident] = {
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
      if (eof) ADVANCE(8);
      if (lookahead == '!') ADVANCE(53);
      if (lookahead == '"') ADVANCE(71);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '&') ADVANCE(68);
      if (lookahead == '(') ADVANCE(73);
      if (lookahead == ')') ADVANCE(74);
      if (lookahead == '*') ADVANCE(65);
      if (lookahead == '+') ADVANCE(64);
      if (lookahead == '-') ADVANCE(55);
      if (lookahead == '.') ADVANCE(5);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '<') ADVANCE(58);
      if (lookahead == '=') ADVANCE(3);
      if (lookahead == '>') ADVANCE(60);
      if (lookahead == '@') ADVANCE(70);
      if (lookahead == 'A') ADVANCE(40);
      if (lookahead == '_') ADVANCE(6);
      if (lookahead == 'd') ADVANCE(19);
      if (lookahead == 'e') ADVANCE(30);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'i') ADVANCE(50);
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 'm') ADVANCE(24);
      if (lookahead == 'n') ADVANCE(45);
      if (lookahead == 's') ADVANCE(48);
      if (lookahead == 't') ADVANCE(28);
      if (lookahead == '|') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(52);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '(') ADVANCE(73);
      if (lookahead == '-') ADVANCE(54);
      if (lookahead == '.') ADVANCE(5);
      if (lookahead == 'A') ADVANCE(40);
      if (lookahead == '_') ADVANCE(6);
      if (lookahead == 'd') ADVANCE(19);
      if (lookahead == 'e') ADVANCE(30);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'i') ADVANCE(50);
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 'm') ADVANCE(24);
      if (lookahead == 'n') ADVANCE(45);
      if (lookahead == 's') ADVANCE(48);
      if (lookahead == 't') ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      if (('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 2:
      if (lookahead == '=') ADVANCE(57);
      END_STATE();
    case 3:
      if (lookahead == '=') ADVANCE(56);
      END_STATE();
    case 4:
      if (lookahead == '|') ADVANCE(63);
      END_STATE();
    case 5:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 6:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 7:
      if (eof) ADVANCE(8);
      if (lookahead == '!') ADVANCE(2);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '&') ADVANCE(68);
      if (lookahead == '(') ADVANCE(73);
      if (lookahead == ')') ADVANCE(74);
      if (lookahead == '*') ADVANCE(65);
      if (lookahead == '+') ADVANCE(64);
      if (lookahead == '-') ADVANCE(55);
      if (lookahead == '.') ADVANCE(5);
      if (lookahead == '/') ADVANCE(66);
      if (lookahead == '<') ADVANCE(58);
      if (lookahead == '=') ADVANCE(3);
      if (lookahead == '>') ADVANCE(60);
      if (lookahead == '@') ADVANCE(70);
      if (lookahead == '_') ADVANCE(6);
      if (lookahead == 'd') ADVANCE(19);
      if (lookahead == 'e') ADVANCE(30);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'i') ADVANCE(50);
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 'm') ADVANCE(24);
      if (lookahead == 'n') ADVANCE(45);
      if (lookahead == 's') ADVANCE(48);
      if (lookahead == 't') ADVANCE(28);
      if (lookahead == '|') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_keyword);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_num_literal);
      if (lookahead == '.') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_num_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(30);
      if (lookahead == 'o') ADVANCE(41);
      if (lookahead == 'u') ADVANCE(34);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(49);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(33);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(46);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'c') ADVANCE(10);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'c') ADVANCE(27);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == 'o') ADVANCE(17);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(34);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(10);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(43);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(15);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(39);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'f') ADVANCE(16);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'g') ADVANCE(21);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'h') ADVANCE(10);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'h') ADVANCE(20);
      if (lookahead == 'r') ADVANCE(47);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'i') ADVANCE(44);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(42);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(10);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(43);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'l') ADVANCE(31);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'n') ADVANCE(10);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'o') ADVANCE(37);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'p') ADVANCE(35);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(43);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(14);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(26);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(38);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(23);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 's') ADVANCE(21);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 't') ADVANCE(10);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 't') ADVANCE(18);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'u') ADVANCE(33);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'u') ADVANCE(32);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'u') ADVANCE(21);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'w') ADVANCE(29);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'y') ADVANCE(72);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'f' ||
          lookahead == 'n') ADVANCE(10);
      if (lookahead == 'm') ADVANCE(36);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(57);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(67);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(59);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(61);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(69);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '&') ADVANCE(62);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_Array);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_chunk_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(75);
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
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 7},
  [5] = {.lex_state = 7},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 7},
  [8] = {.lex_state = 7},
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 7},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 7},
  [14] = {.lex_state = 7},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 7},
  [17] = {.lex_state = 7},
  [18] = {.lex_state = 7},
  [19] = {.lex_state = 7},
  [20] = {.lex_state = 7},
  [21] = {.lex_state = 7},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 7},
  [33] = {.lex_state = 7},
  [34] = {.lex_state = 7},
  [35] = {.lex_state = 7},
  [36] = {.lex_state = 7},
  [37] = {.lex_state = 7},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 75},
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
    [sym_num_literal] = ACTIONS(1),
    [sym_ident] = ACTIONS(1),
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
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym__string_fragment] = ACTIONS(1),
    [sym__multistring_start] = ACTIONS(1),
    [sym__multistring_part_fixed] = ACTIONS(1),
    [sym__multistring_ipol_start] = ACTIONS(1),
    [sym__multistring_end] = ACTIONS(1),
  },
  [1] = {
    [sym_term] = STATE(43),
    [sym_uni_term] = STATE(42),
    [sym_infix_expr] = STATE(13),
    [sym_infix_u_op] = STATE(17),
    [sym_infix_b_op] = STATE(17),
    [sym_applicative] = STATE(2),
    [sym_type_array] = STATE(7),
    [sym_record_operand] = STATE(7),
    [sym_atom] = STATE(9),
    [sym_bool] = STATE(3),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(5),
    [sym_ident] = ACTIONS(7),
    [anon_sym_BANG] = ACTIONS(9),
    [anon_sym_DASH] = ACTIONS(11),
    [anon_sym_import] = ACTIONS(13),
    [anon_sym_Array] = ACTIONS(15),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_null] = ACTIONS(7),
    [anon_sym_true] = ACTIONS(19),
    [anon_sym_false] = ACTIONS(19),
  },
  [2] = {
    [sym_record_operand] = STATE(11),
    [sym_atom] = STATE(9),
    [sym_bool] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(5),
    [sym_ident] = ACTIONS(7),
    [anon_sym_DASH] = ACTIONS(23),
    [anon_sym_EQ_EQ] = ACTIONS(21),
    [anon_sym_BANG_EQ] = ACTIONS(21),
    [anon_sym_LT] = ACTIONS(23),
    [anon_sym_LT_EQ] = ACTIONS(21),
    [anon_sym_GT] = ACTIONS(23),
    [anon_sym_GT_EQ] = ACTIONS(21),
    [anon_sym_AMP_AMP] = ACTIONS(21),
    [anon_sym_PIPE_PIPE] = ACTIONS(21),
    [anon_sym_PLUS] = ACTIONS(23),
    [anon_sym_STAR] = ACTIONS(21),
    [anon_sym_SLASH] = ACTIONS(21),
    [anon_sym_DASH_GT] = ACTIONS(21),
    [anon_sym_AMP] = ACTIONS(23),
    [anon_sym_PLUS_PLUS] = ACTIONS(21),
    [anon_sym_AT] = ACTIONS(21),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_RPAREN] = ACTIONS(21),
    [anon_sym_null] = ACTIONS(7),
    [anon_sym_true] = ACTIONS(19),
    [anon_sym_false] = ACTIONS(19),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(25),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(25),
    [sym_ident] = ACTIONS(27),
    [anon_sym_DASH] = ACTIONS(27),
    [anon_sym_EQ_EQ] = ACTIONS(25),
    [anon_sym_BANG_EQ] = ACTIONS(25),
    [anon_sym_LT] = ACTIONS(27),
    [anon_sym_LT_EQ] = ACTIONS(25),
    [anon_sym_GT] = ACTIONS(27),
    [anon_sym_GT_EQ] = ACTIONS(25),
    [anon_sym_AMP_AMP] = ACTIONS(25),
    [anon_sym_PIPE_PIPE] = ACTIONS(25),
    [anon_sym_PLUS] = ACTIONS(27),
    [anon_sym_STAR] = ACTIONS(25),
    [anon_sym_SLASH] = ACTIONS(25),
    [anon_sym_DASH_GT] = ACTIONS(25),
    [anon_sym_AMP] = ACTIONS(27),
    [anon_sym_PLUS_PLUS] = ACTIONS(25),
    [anon_sym_AT] = ACTIONS(25),
    [anon_sym_LPAREN] = ACTIONS(25),
    [anon_sym_RPAREN] = ACTIONS(25),
    [anon_sym_null] = ACTIONS(27),
    [anon_sym_true] = ACTIONS(27),
    [anon_sym_false] = ACTIONS(27),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(29),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(29),
    [sym_ident] = ACTIONS(31),
    [anon_sym_DASH] = ACTIONS(31),
    [anon_sym_EQ_EQ] = ACTIONS(29),
    [anon_sym_BANG_EQ] = ACTIONS(29),
    [anon_sym_LT] = ACTIONS(31),
    [anon_sym_LT_EQ] = ACTIONS(29),
    [anon_sym_GT] = ACTIONS(31),
    [anon_sym_GT_EQ] = ACTIONS(29),
    [anon_sym_AMP_AMP] = ACTIONS(29),
    [anon_sym_PIPE_PIPE] = ACTIONS(29),
    [anon_sym_PLUS] = ACTIONS(31),
    [anon_sym_STAR] = ACTIONS(29),
    [anon_sym_SLASH] = ACTIONS(29),
    [anon_sym_DASH_GT] = ACTIONS(29),
    [anon_sym_AMP] = ACTIONS(31),
    [anon_sym_PLUS_PLUS] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LPAREN] = ACTIONS(29),
    [anon_sym_RPAREN] = ACTIONS(29),
    [anon_sym_null] = ACTIONS(31),
    [anon_sym_true] = ACTIONS(31),
    [anon_sym_false] = ACTIONS(31),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(33),
    [sym_ident] = ACTIONS(35),
    [anon_sym_DASH] = ACTIONS(35),
    [anon_sym_EQ_EQ] = ACTIONS(33),
    [anon_sym_BANG_EQ] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
    [anon_sym_LT_EQ] = ACTIONS(33),
    [anon_sym_GT] = ACTIONS(35),
    [anon_sym_GT_EQ] = ACTIONS(33),
    [anon_sym_AMP_AMP] = ACTIONS(33),
    [anon_sym_PIPE_PIPE] = ACTIONS(33),
    [anon_sym_PLUS] = ACTIONS(35),
    [anon_sym_STAR] = ACTIONS(33),
    [anon_sym_SLASH] = ACTIONS(33),
    [anon_sym_DASH_GT] = ACTIONS(33),
    [anon_sym_AMP] = ACTIONS(35),
    [anon_sym_PLUS_PLUS] = ACTIONS(33),
    [anon_sym_AT] = ACTIONS(33),
    [anon_sym_LPAREN] = ACTIONS(33),
    [anon_sym_RPAREN] = ACTIONS(33),
    [anon_sym_null] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(35),
    [anon_sym_false] = ACTIONS(35),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(37),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(37),
    [sym_ident] = ACTIONS(39),
    [anon_sym_DASH] = ACTIONS(39),
    [anon_sym_EQ_EQ] = ACTIONS(37),
    [anon_sym_BANG_EQ] = ACTIONS(37),
    [anon_sym_LT] = ACTIONS(39),
    [anon_sym_LT_EQ] = ACTIONS(37),
    [anon_sym_GT] = ACTIONS(39),
    [anon_sym_GT_EQ] = ACTIONS(37),
    [anon_sym_AMP_AMP] = ACTIONS(37),
    [anon_sym_PIPE_PIPE] = ACTIONS(37),
    [anon_sym_PLUS] = ACTIONS(39),
    [anon_sym_STAR] = ACTIONS(37),
    [anon_sym_SLASH] = ACTIONS(37),
    [anon_sym_DASH_GT] = ACTIONS(37),
    [anon_sym_AMP] = ACTIONS(39),
    [anon_sym_PLUS_PLUS] = ACTIONS(37),
    [anon_sym_AT] = ACTIONS(37),
    [anon_sym_LPAREN] = ACTIONS(37),
    [anon_sym_RPAREN] = ACTIONS(37),
    [anon_sym_null] = ACTIONS(39),
    [anon_sym_true] = ACTIONS(39),
    [anon_sym_false] = ACTIONS(39),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(41),
    [sym_ident] = ACTIONS(43),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_EQ_EQ] = ACTIONS(41),
    [anon_sym_BANG_EQ] = ACTIONS(41),
    [anon_sym_LT] = ACTIONS(43),
    [anon_sym_LT_EQ] = ACTIONS(41),
    [anon_sym_GT] = ACTIONS(43),
    [anon_sym_GT_EQ] = ACTIONS(41),
    [anon_sym_AMP_AMP] = ACTIONS(41),
    [anon_sym_PIPE_PIPE] = ACTIONS(41),
    [anon_sym_PLUS] = ACTIONS(43),
    [anon_sym_STAR] = ACTIONS(41),
    [anon_sym_SLASH] = ACTIONS(41),
    [anon_sym_DASH_GT] = ACTIONS(41),
    [anon_sym_AMP] = ACTIONS(43),
    [anon_sym_PLUS_PLUS] = ACTIONS(41),
    [anon_sym_AT] = ACTIONS(41),
    [anon_sym_LPAREN] = ACTIONS(41),
    [anon_sym_RPAREN] = ACTIONS(41),
    [anon_sym_null] = ACTIONS(43),
    [anon_sym_true] = ACTIONS(43),
    [anon_sym_false] = ACTIONS(43),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(45),
    [sym_ident] = ACTIONS(47),
    [anon_sym_DASH] = ACTIONS(47),
    [anon_sym_EQ_EQ] = ACTIONS(45),
    [anon_sym_BANG_EQ] = ACTIONS(45),
    [anon_sym_LT] = ACTIONS(47),
    [anon_sym_LT_EQ] = ACTIONS(45),
    [anon_sym_GT] = ACTIONS(47),
    [anon_sym_GT_EQ] = ACTIONS(45),
    [anon_sym_AMP_AMP] = ACTIONS(45),
    [anon_sym_PIPE_PIPE] = ACTIONS(45),
    [anon_sym_PLUS] = ACTIONS(47),
    [anon_sym_STAR] = ACTIONS(45),
    [anon_sym_SLASH] = ACTIONS(45),
    [anon_sym_DASH_GT] = ACTIONS(45),
    [anon_sym_AMP] = ACTIONS(47),
    [anon_sym_PLUS_PLUS] = ACTIONS(45),
    [anon_sym_AT] = ACTIONS(45),
    [anon_sym_LPAREN] = ACTIONS(45),
    [anon_sym_RPAREN] = ACTIONS(45),
    [anon_sym_null] = ACTIONS(47),
    [anon_sym_true] = ACTIONS(47),
    [anon_sym_false] = ACTIONS(47),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(49),
    [sym_ident] = ACTIONS(51),
    [anon_sym_DASH] = ACTIONS(51),
    [anon_sym_EQ_EQ] = ACTIONS(49),
    [anon_sym_BANG_EQ] = ACTIONS(49),
    [anon_sym_LT] = ACTIONS(51),
    [anon_sym_LT_EQ] = ACTIONS(49),
    [anon_sym_GT] = ACTIONS(51),
    [anon_sym_GT_EQ] = ACTIONS(49),
    [anon_sym_AMP_AMP] = ACTIONS(49),
    [anon_sym_PIPE_PIPE] = ACTIONS(49),
    [anon_sym_PLUS] = ACTIONS(51),
    [anon_sym_STAR] = ACTIONS(49),
    [anon_sym_SLASH] = ACTIONS(49),
    [anon_sym_DASH_GT] = ACTIONS(49),
    [anon_sym_AMP] = ACTIONS(51),
    [anon_sym_PLUS_PLUS] = ACTIONS(49),
    [anon_sym_AT] = ACTIONS(49),
    [anon_sym_LPAREN] = ACTIONS(49),
    [anon_sym_RPAREN] = ACTIONS(49),
    [anon_sym_null] = ACTIONS(51),
    [anon_sym_true] = ACTIONS(51),
    [anon_sym_false] = ACTIONS(51),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(53),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(53),
    [sym_ident] = ACTIONS(55),
    [anon_sym_DASH] = ACTIONS(55),
    [anon_sym_EQ_EQ] = ACTIONS(53),
    [anon_sym_BANG_EQ] = ACTIONS(53),
    [anon_sym_LT] = ACTIONS(55),
    [anon_sym_LT_EQ] = ACTIONS(53),
    [anon_sym_GT] = ACTIONS(55),
    [anon_sym_GT_EQ] = ACTIONS(53),
    [anon_sym_AMP_AMP] = ACTIONS(53),
    [anon_sym_PIPE_PIPE] = ACTIONS(53),
    [anon_sym_PLUS] = ACTIONS(55),
    [anon_sym_STAR] = ACTIONS(53),
    [anon_sym_SLASH] = ACTIONS(53),
    [anon_sym_DASH_GT] = ACTIONS(53),
    [anon_sym_AMP] = ACTIONS(55),
    [anon_sym_PLUS_PLUS] = ACTIONS(53),
    [anon_sym_AT] = ACTIONS(53),
    [anon_sym_LPAREN] = ACTIONS(53),
    [anon_sym_RPAREN] = ACTIONS(53),
    [anon_sym_null] = ACTIONS(55),
    [anon_sym_true] = ACTIONS(55),
    [anon_sym_false] = ACTIONS(55),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(57),
    [sym_comment] = ACTIONS(3),
    [sym_num_literal] = ACTIONS(57),
    [sym_ident] = ACTIONS(59),
    [anon_sym_DASH] = ACTIONS(59),
    [anon_sym_EQ_EQ] = ACTIONS(57),
    [anon_sym_BANG_EQ] = ACTIONS(57),
    [anon_sym_LT] = ACTIONS(59),
    [anon_sym_LT_EQ] = ACTIONS(57),
    [anon_sym_GT] = ACTIONS(59),
    [anon_sym_GT_EQ] = ACTIONS(57),
    [anon_sym_AMP_AMP] = ACTIONS(57),
    [anon_sym_PIPE_PIPE] = ACTIONS(57),
    [anon_sym_PLUS] = ACTIONS(59),
    [anon_sym_STAR] = ACTIONS(57),
    [anon_sym_SLASH] = ACTIONS(57),
    [anon_sym_DASH_GT] = ACTIONS(57),
    [anon_sym_AMP] = ACTIONS(59),
    [anon_sym_PLUS_PLUS] = ACTIONS(57),
    [anon_sym_AT] = ACTIONS(57),
    [anon_sym_LPAREN] = ACTIONS(57),
    [anon_sym_RPAREN] = ACTIONS(57),
    [anon_sym_null] = ACTIONS(59),
    [anon_sym_true] = ACTIONS(59),
    [anon_sym_false] = ACTIONS(59),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(13), 1,
      sym_infix_expr,
    STATE(41), 1,
      sym_uni_term,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [53] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(77), 1,
      anon_sym_DASH_GT,
    ACTIONS(79), 1,
      anon_sym_AMP,
    ACTIONS(61), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
    ACTIONS(63), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
  [97] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_AMP,
    ACTIONS(63), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 7,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [133] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(19), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [183] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(85), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(83), 11,
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
  [211] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(21), 13,
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
  [237] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(63), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(89), 3,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_AMP,
    ACTIONS(87), 9,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [269] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(87), 13,
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
  [295] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_AMP,
    ACTIONS(63), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(83), 9,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [329] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(73), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(77), 1,
      anon_sym_DASH_GT,
    ACTIONS(79), 1,
      anon_sym_AMP,
    ACTIONS(63), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
  [373] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(34), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [423] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(14), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [473] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(36), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [523] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(35), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [573] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(33), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [623] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(32), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [673] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(21), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [723] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(20), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [773] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(16), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [823] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(9), 1,
      anon_sym_BANG,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      anon_sym_import,
    ACTIONS(15), 1,
      anon_sym_Array,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_applicative,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(18), 1,
      sym_infix_expr,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_type_array,
      sym_record_operand,
    STATE(17), 2,
      sym_infix_u_op,
      sym_infix_b_op,
  [873] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(85), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(83), 11,
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
  [901] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(71), 1,
      anon_sym_AMP_AMP,
    ACTIONS(79), 1,
      anon_sym_AMP,
    ACTIONS(63), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 4,
      ts_builtin_sym_end,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [941] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(85), 5,
      anon_sym_DASH,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_PLUS,
      anon_sym_AMP,
    ACTIONS(83), 9,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [971] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_AMP,
    ACTIONS(63), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(65), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(67), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(69), 2,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(83), 5,
      ts_builtin_sym_end,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [1009] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_AMP,
    ACTIONS(63), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(75), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(81), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_AT,
    ACTIONS(85), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(83), 9,
      ts_builtin_sym_end,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_DASH_GT,
      anon_sym_RPAREN,
  [1043] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym_num_literal,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    STATE(3), 1,
      sym_bool,
    STATE(9), 1,
      sym_atom,
    STATE(10), 1,
      sym_record_operand,
    ACTIONS(7), 2,
      sym_ident,
      anon_sym_null,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
  [1070] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      sym_static_string,
  [1080] = 3,
    ACTIONS(93), 1,
      sym_comment,
    ACTIONS(95), 1,
      anon_sym_DQUOTE,
    ACTIONS(97), 1,
      sym_chunk_literal,
  [1090] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 1,
      anon_sym_DQUOTE,
  [1097] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(101), 1,
      anon_sym_RPAREN,
  [1104] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 1,
      ts_builtin_sym_end,
  [1111] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(105), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(12)] = 0,
  [SMALL_STATE(13)] = 53,
  [SMALL_STATE(14)] = 97,
  [SMALL_STATE(15)] = 133,
  [SMALL_STATE(16)] = 183,
  [SMALL_STATE(17)] = 211,
  [SMALL_STATE(18)] = 237,
  [SMALL_STATE(19)] = 269,
  [SMALL_STATE(20)] = 295,
  [SMALL_STATE(21)] = 329,
  [SMALL_STATE(22)] = 373,
  [SMALL_STATE(23)] = 423,
  [SMALL_STATE(24)] = 473,
  [SMALL_STATE(25)] = 523,
  [SMALL_STATE(26)] = 573,
  [SMALL_STATE(27)] = 623,
  [SMALL_STATE(28)] = 673,
  [SMALL_STATE(29)] = 723,
  [SMALL_STATE(30)] = 773,
  [SMALL_STATE(31)] = 823,
  [SMALL_STATE(32)] = 873,
  [SMALL_STATE(33)] = 901,
  [SMALL_STATE(34)] = 941,
  [SMALL_STATE(35)] = 971,
  [SMALL_STATE(36)] = 1009,
  [SMALL_STATE(37)] = 1043,
  [SMALL_STATE(38)] = 1070,
  [SMALL_STATE(39)] = 1080,
  [SMALL_STATE(40)] = 1090,
  [SMALL_STATE(41)] = 1097,
  [SMALL_STATE(42)] = 1104,
  [SMALL_STATE(43)] = 1111,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_expr, 1),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_expr, 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 1),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 1),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_string, 3),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_string, 3),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atom, 3),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atom, 3),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_string, 2),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_string, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_applicative, 1),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_applicative, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool, 1),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool, 1),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_operand, 1),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_record_operand, 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_array, 2),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_array, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_applicative, 2),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_applicative, 2),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uni_term, 1),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_b_op, 3, .production_id = 2),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_b_op, 3, .production_id = 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_infix_u_op, 2, .production_id = 1),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_infix_u_op, 2, .production_id = 1),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term, 1),
  [105] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
