#include <tree_sitter/parser.h>

#include <stdio.h> // printf

enum TokenType {
  STRING_FRAGMENT,
  INDENTED_STRING_FRAGMENT,
  MULTISTRING_START,
  MULTISTRING_PART_FIXED,
  MULTISTRING_RICHTERM_PREFIX, // $._multistring_richterm_prefix
  MULTISTRING_END,
};

static void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

// Here we only parse literal fragment inside a string.
// Delimiter, interpolation and escape sequence are handled by the parser and we simply stop at them.
//
// The implementation is inspired by tree-sitter-javascript:
// https://github.com/tree-sitter/tree-sitter-javascript/blob/fdeb68ac8d2bd5a78b943528bb68ceda3aade2eb/src/scanner.c#L19
static bool scan_string_fragment(TSLexer *lexer) {
  printf("scan_string_fragment\n");
  lexer->result_symbol = STRING_FRAGMENT;
  for (bool has_content = false;; has_content = true) {
    lexer->mark_end(lexer);
    switch (lexer->lookahead) {
      case '"':
      case '\\':
        return has_content;
      case '%':
        advance(lexer);
        if (lexer->lookahead == '{') {
          return has_content;
        } else if (lexer->lookahead != '"' && lexer->lookahead != '\\') {
          // Any char following '$' other than '"', '\\' and '{' (which was handled above)
          // should be consumed as additional string content.
          // This means `$${` doesn't start an interpolation, but `$$${` does.
          advance(lexer);
        }
        break;
      // Simply give up on EOF or '\0'.
      case '\0':
        return false;
      default:
        advance(lexer);
    }
  }
}

// See comments of scan_string_fragment.
static bool scan_indented_string_fragment(TSLexer *lexer) {
  printf("scan_indented_string_fragment\n");
  lexer->result_symbol = INDENTED_STRING_FRAGMENT;
  for (bool has_content = false;; has_content = true) {
    lexer->mark_end(lexer);
    switch (lexer->lookahead) {
      case '%':
        advance(lexer);
        // TODO require multiple % when in "multi level" string %%m"..."m%% (multistring_level = 2)
        if (lexer->lookahead == '{') {
          return has_content;
        } else if (lexer->lookahead != '\'') {
          // Any char following '$' other than '\'' and '{' (which was handled above)
          // should be consumed as additional string content.
          // This means `$${` doesn't start an interpolation, but `$$${` does.
          advance(lexer);
        }
        break;
      case '\"':
        advance(lexer);
        if (lexer->lookahead == '%') {
          advance(lexer);
          if (lexer->lookahead == 'm') {
            // end of stringblock
            // Two single quotes always stop current string fragment.
            // It can be either an end delimiter '', or escape sequences ''', ''$, ''\<any>
            return has_content;
          }
        }
        break;
      // Simply give up on EOF or '\0'.
      case '\0':
        return false;
      default:
        advance(lexer);
    }
  }
}

unsigned int multistring_level = 0;

static bool scan_multistring_start(TSLexer *lexer) {
  printf("scan_multistring_start\n");
  lexer->result_symbol = MULTISTRING_START;
  // m% was parsed before this
  // expected: m%" m%%" m%%%" m%%%%" ...
  // multistring_level = number of %
  //unsigned int multistring_level = 1;
  multistring_level = 1;
  while (lexer->lookahead == '%') {
    advance(lexer);
    //lexer->mark_end(lexer); // TODO(milahu) why?
    multistring_level++;
    // FIXME skip_unrecognized_character
    // FIXME lexed_lookahead sym:ERROR, size:3
  }
  // TODO store multistring_level in parser state?
  // multistring_level is required to parse RichTerm and _multistring_end
  if (lexer->lookahead == '"') {
    advance(lexer);
    //lexer->mark_end(lexer); // TODO(milahu) why?
    printf("scan_multistring_part_fixed: multistring_level = %i\n", multistring_level);
    return true;
  }
  multistring_level = 1; // reset to default value
  return false;
}



static bool scan_multistring_part_fixed_wrong(TSLexer *lexer) {
  printf("scan_multistring_part_fixed_wrong\n");
  lexer->result_symbol = MULTISTRING_PART_FIXED;
  // scan until %{ %%{ %%%{ %%%%{ ...
  // multistring_level = number of %
  // TODO return false if content is empty
  // see "has_content" in other functions
  for (unsigned int i = 0; i < multistring_level; i++) {
    if (lexer->lookahead == '%') {
      advance(lexer);
    }
    else {
      return false;
    }
  }
  if (lexer->lookahead == '{') {
    advance(lexer);
    return true;
  }
  return false;
}

// based on scan_string_fragment
static bool scan_multistring_part_fixed(TSLexer *lexer) {
  printf("scan_multistring_part_fixed\n");
  lexer->result_symbol = MULTISTRING_PART_FIXED;
  for (bool has_content = false;; has_content = true) {
    lexer->mark_end(lexer);
    switch (lexer->lookahead) {
      case '"':
        printf("scan_multistring_part_fixed: stop after \"\n");
        return has_content;
      case '\\':
        printf("scan_multistring_part_fixed: stop after \\\n");
        return has_content;
      case '%':
        advance(lexer);
        // consume the required number of % in this multistring
        unsigned int i;
        for (i = 0; i < (multistring_level - 1); i++) {
          if (lexer->lookahead == '%') {
            printf("scan_multistring_part_fixed: found %% %i of %i\\\n", (i+1), multistring_level);
            advance(lexer);
          }
          else {
            printf("scan_multistring_part_fixed: found %c but expected %%\\\n", lexer->lookahead);
            break;
          }
        }
        printf("scan_multistring_part_fixed: found all %%\n");
        // TODO off by one error?
        // (multistring_level - 2) ?
        // (multistring_level - 1) ?
        printf("scan_multistring_part_fixed: i = %i\n", i);
        printf("scan_multistring_part_fixed: multistring_level = %i\n", multistring_level);
        if (i == (multistring_level - 2) && lexer->lookahead == '{') {
          if (has_content) {
            printf("scan_multistring_part_fixed: found nonempty fixed string before RichTerm\n");
          }
          else {
            printf("scan_multistring_part_fixed: found empty fixed string before RichTerm\n");
          }
          return has_content;
        }
        if (lexer->lookahead != '"' && lexer->lookahead != '\\') {
          printf("scan_multistring_part_fixed: lexer->lookahead %c is not \" or \\ -> advance && break\n", lexer->lookahead);
          // Any char following '$' other than '"', '\\' and '{' (which was handled above)
          // should be consumed as additional string content.
          // This means `$${` doesn't start an interpolation, but `$$${` does.
          advance(lexer);
        }
        break;
      // Simply give up on EOF or '\0'.
      case '\0':
        printf("scan_multistring_part_fixed: giving up at end of string\n");
        return false;
      default:
        printf("scan_multistring_part_fixed: default advance\n");
        advance(lexer);
    }
  }
}


static bool scan_multistring_richterm_prefix(TSLexer *lexer) {
  printf("scan_multistring_richterm_prefix\n");
  lexer->result_symbol = MULTISTRING_RICHTERM_PREFIX;
  // %{ comes after this
  // consume all the % required in this multistring
  for (unsigned int i = 0; i < (multistring_level - 1); i++) {
    if (lexer->lookahead == '%') {
      advance(lexer);
    }
    else {
      return false;
    }
  }
  return true;
}

// m%%%%"a"%%%%m
// 0123456
static bool scan_multistring_end(TSLexer *lexer) {
  printf("scan_multistring_end\n");
  lexer->result_symbol = MULTISTRING_END;
  // "% was parsed before this
  // expected: "%m "%%m "%%%m "%%%%m ...
  // multistring_level = number of %
  for (unsigned int i = 0; i < (multistring_level - 1); i++) {
    if (lexer->lookahead == '%') {
      advance(lexer);
      printf("scan_multistring_end: found %% %i of %i\n", (i+1), (multistring_level - 1));
    }
    else {
      printf("scan_multistring_end: found %c but expected %% -> return false\n", lexer->lookahead);
      return false;
    }
  }
  if (lexer->lookahead == 'm') {
    advance(lexer);
    printf("scan_multistring_end: found m -> return true\n");
    return true;
  }
  printf("scan_multistring_end: not found m -> return false\n");
  return false;
}







void *tree_sitter_nickel_external_scanner_create() {
  return NULL;
}

// TODO(milahu) refactor? move the special parser functions to end of file + add function signatures
bool tree_sitter_nickel_external_scanner_scan (
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
  ) {
  // This never happens in valid grammar. Only during error recovery, everything becomes valid.
  // See: https://github.com/tree-sitter/tree-sitter/issues/1259
  //
  // We should not consume any content as string fragment during error recovery, or we'll break
  // more valid grammar below.
  // The test 'attrset typing field following string' covers this.
  if (
    valid_symbols[STRING_FRAGMENT] &&
    valid_symbols[INDENTED_STRING_FRAGMENT] &&
    valid_symbols[MULTISTRING_START] &&
    valid_symbols[MULTISTRING_PART_FIXED] &&
    valid_symbols[MULTISTRING_RICHTERM_PREFIX] &&
    valid_symbols[MULTISTRING_END]
  ) {
    return false;
  }
  if (valid_symbols[STRING_FRAGMENT]) {
    return scan_string_fragment(lexer);
  }
  if (valid_symbols[INDENTED_STRING_FRAGMENT]) {
    return scan_indented_string_fragment(lexer);
  }
  if (valid_symbols[MULTISTRING_START]) {
    return scan_multistring_start(lexer);
  }
  if (valid_symbols[MULTISTRING_PART_FIXED]) {
    return scan_multistring_part_fixed(lexer);
  }
  if (valid_symbols[MULTISTRING_RICHTERM_PREFIX]) {
    return scan_multistring_richterm_prefix(lexer);
  }
  if (valid_symbols[MULTISTRING_END]) {
    return scan_multistring_end(lexer);
  }
  return false;
}

unsigned tree_sitter_nickel_external_scanner_serialize(void *payload, char *buffer) {
  return 0;
}

void tree_sitter_nickel_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) { }

void tree_sitter_nickel_external_scanner_destroy(void *payload) { }
