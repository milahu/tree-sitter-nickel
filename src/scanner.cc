//#include <tree_sitter/parser.h>
#include "tree-sitter/lib/include/tree_sitter/parser.h"
#include "tree-sitter/lib/src/lexer.h" // Lexer, Length
// http://tree-sitter.github.io/tree-sitter/creating-parsers#external-scanners
// https://github.com/tree-sitter/tree-sitter/issues/281

#include <stack> // std::stack
// https://en.cppreference.com/w/cpp/container/stack
// https://www.geeksforgeeks.org/stack-in-cpp-stl/

// https://stackoverflow.com/a/27351464/10440128
//#define DEBUG 1
#if defined(DEBUG) && DEBUG > 0
 #include <stdio.h> // fprintf
 #define DEBUG_PRINT(fmt, args...) fprintf(stderr, "scanner.cc:%d: " fmt, __LINE__, ##args)
#else
 #define DEBUG_PRINT(fmt, args...) // dont print
#endif

enum TokenType {
  STRING_FRAGMENT,
  MULTISTRING_START,
  MULTISTRING_PART_FIXED,
  MULTISTRING_IPOL_START,
  MULTISTRING_END,
};

static void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

// custom state, shared across calls to scan()
unsigned int multistring_level = 0;
int next_token = -1;

// Here we only parse literal fragment inside a string.
// Delimiter, interpolation and escape sequence are handled by the parser and we simply stop at them.
//
// The implementation is inspired by tree-sitter-javascript:
// https://github.com/tree-sitter/tree-sitter-javascript/blob/fdeb68ac8d2bd5a78b943528bb68ceda3aade2eb/src/scanner.c#L19
static bool scan_string_fragment(TSLexer *lexer) {
  DEBUG_PRINT("scan_string_fragment\n");
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

static bool scan_multistring_start(TSLexer *lexer) {
  DEBUG_PRINT("scan_multistring_start\n");
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
    DEBUG_PRINT("scan_multistring_start: found multistring_level = %i\n", multistring_level);
    return true;
  }
  multistring_level = 1; // reset to default value
  DEBUG_PRINT("scan_multistring_start: not found\n");
  return false;
}

static bool scan_multistring_part_fixed_wrong(TSLexer *lexer) {
  DEBUG_PRINT("scan_multistring_part_fixed_wrong\n");
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
  Lexer *internal_lexer = (Lexer *)lexer; // typecast: TSLexer -> Lexer
  // possible token_end positions
  // allows to seek back after calling `advance(lexer)`
  // using C++ std::stack template to store Length structs
  // let's hope this does not blow up the WASM binary size too much ...
  // a pure C solution would be more verbose
  // https://github.com/tree-sitter/tree-sitter/issues/1688
  std::stack<Length> token_end_candidates;
  DEBUG_PRINT("scan_multistring_part_fixed\n");
  unsigned int percent_seen = 0;
  lexer->result_symbol = MULTISTRING_PART_FIXED;
  for (bool has_content = false;; has_content = true) {
    lexer->mark_end(lexer); // end of _multistring_part_fixed token is here
    // clear the stack
    while (!token_end_candidates.empty()) {
      token_end_candidates.pop();
    }
    DEBUG_PRINT("token_end_candidates add %i\n", internal_lexer->current_position.bytes);
    token_end_candidates.push(internal_lexer->current_position); // TODO value or reference?
    switch (lexer->lookahead) {
      case '"':
        DEBUG_PRINT("scan_multistring_part_fixed: stop after \"\n");
        return has_content;
      case '\\':
        DEBUG_PRINT("scan_multistring_part_fixed: stop after \\\n"); // -> start of escape sequence
        return has_content;
      case '%':
        percent_seen = 1;
        advance(lexer);
        while (lexer->lookahead == '%') {
          percent_seen++;
          token_end_candidates.push(internal_lexer->current_position); // TODO value or reference?
          DEBUG_PRINT("token_end_candidates add %i\n", internal_lexer->current_position.bytes);
          advance(lexer);
        }
        if (percent_seen < multistring_level) {
          // not enough % for richterm -> continue parsing the _multistring_part_fixed token
          DEBUG_PRINT("scan_multistring_part_fixed: found %i of %i %% -> fixed chars\n", percent_seen, multistring_level);
          continue;
        }
        if (percent_seen > multistring_level) {
          // seek back to end of _multistring_part_fixed token
          for (int k = 0; k < (multistring_level - 1); k++) {
            DEBUG_PRINT("scan_multistring_part_fixed: skip position %i of %i: %i\n", (k+1), multistring_level, token_end_candidates.top().bytes);
            DEBUG_PRINT("scan_multistring_part_fixed: stack size: %i\n", token_end_candidates.size());
            token_end_candidates.pop();
          }
          // set end of _multistring_part_fixed token
          DEBUG_PRINT("scan_multistring_part_fixed: stack size: %i\n", token_end_candidates.size());
          DEBUG_PRINT("scan_multistring_part_fixed: set token end\n");
          internal_lexer->token_end_position = token_end_candidates.top(); // note: segfault when stack is empty
          DEBUG_PRINT("scan_multistring_part_fixed: token_end_position.bytes = %i\n", internal_lexer->token_end_position.bytes);
          // yield _multistring_part_fixed token
          return true;
          // next token: MultiStrIpol (aka. RichTerm)
        }
        if (percent_seen == multistring_level) {
          // exact number of %
          DEBUG_PRINT("scan_multistring_part_fixed: found %% %i of %i\n", percent_seen, multistring_level);
        }
        //if (percent_seen == multistring_level && lexer->lookahead == '{') {
        if (lexer->lookahead == '{') {
          if (has_content) {
            DEBUG_PRINT("scan_multistring_part_fixed: found nonempty fixed string before RichTerm\n");
            next_token = MULTISTRING_IPOL_START; // avoid double scanning -> fast path
            DEBUG_PRINT("scan_multistring_part_fixed: next_token = %i\n", next_token);
          }
          else {
            // fast path: yield RICHTERM_START here
            DEBUG_PRINT("scan_multistring_part_fixed: found empty fixed string before RichTerm -> yield RichTerm token\n");
            advance(lexer); // consume { as part of RICHTERM_START
            lexer->result_symbol = MULTISTRING_IPOL_START;
            lexer->mark_end(lexer); // end of _multistring_part_fixed token is here
            return true;
            // TODO or: return false && set next_token = RichTerm
          }
          return has_content;
        }
        /*
        if (lexer->lookahead != '"' && lexer->lookahead != '\\') {
          DEBUG_PRINT("scan_multistring_part_fixed: lexer->lookahead %c is not \" or \\ -> advance && break\n", lexer->lookahead);
          // Any char following '$' other than '"', '\\' and '{' (which was handled above)
          // should be consumed as additional string content.
          // This means `$${` doesn't start an interpolation, but `$$${` does.
          advance(lexer);
        }
        */
        break;
      // Simply give up on EOF or '\0'.
      case '\0':
        DEBUG_PRINT("scan_multistring_part_fixed: giving up at end of string\n");
        return false;
      default:
        advance(lexer);
        DEBUG_PRINT("scan_multistring_part_fixed: found fixed char\n");
    }
  }
}

static bool scan_multistring_richterm_start(TSLexer *lexer) {
  DEBUG_PRINT("scan_multistring_richterm_start\n");
  lexer->result_symbol = MULTISTRING_IPOL_START;
  DEBUG_PRINT("scan_multistring_richterm_start: next_token = %i\n", next_token);
  if (next_token == MULTISTRING_IPOL_START) {
    // fast path
    DEBUG_PRINT("scan_multistring_richterm_start: fast path\n");
    next_token = -1; // reset
    // consume '%' * multistring_level
    // consume '{' * 1
    for (unsigned int i = 0; i < (multistring_level + 1); i++) {
      advance(lexer);
    }
    lexer->mark_end(lexer);
    return true;
  }
  DEBUG_PRINT("scan_multistring_richterm_start: slow path\n");
  // %{ comes after this
  // consume all the % required in this multistring
  for (unsigned int i = 0; i < multistring_level; i++) {
    if (lexer->lookahead != '%') {
      return false;
    }
    advance(lexer);
  }
  if (lexer->lookahead != '{') {
    return false;
  }
  advance(lexer);
  lexer->mark_end(lexer);
  return true;
}

static bool scan_multistring_end(TSLexer *lexer) {
  DEBUG_PRINT("scan_multistring_end\n");
  lexer->result_symbol = MULTISTRING_END;
  // "% was parsed before this
  // expected: "%m "%%m "%%%m "%%%%m ...
  // multistring_level = number of %
  for (unsigned int i = 0; i < (multistring_level - 1); i++) {
    if (lexer->lookahead == '%') {
      advance(lexer);
      DEBUG_PRINT("scan_multistring_end: found %% %i of %i\n", (i+1), (multistring_level - 1));
    }
    else {
      DEBUG_PRINT("scan_multistring_end: found %c but expected %% -> return false\n", lexer->lookahead);
      return false;
    }
  }
  if (lexer->lookahead == 'm') {
    advance(lexer);
    DEBUG_PRINT("scan_multistring_end: found m -> return true\n");
    return true;
  }
  DEBUG_PRINT("scan_multistring_end: not found m -> return false\n");
  return false;
}



// interface
// note: `extern "C"` for C++ code

extern "C" void *tree_sitter_nickel_external_scanner_create() {
  return NULL;
}

extern "C" bool tree_sitter_nickel_external_scanner_scan (
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
    valid_symbols[MULTISTRING_START] &&
    valid_symbols[MULTISTRING_PART_FIXED] &&
    valid_symbols[MULTISTRING_IPOL_START] &&
    valid_symbols[MULTISTRING_END]
  ) {
    return false;
  }

  DEBUG_PRINT("valid_symbols[STRING_FRAGMENT] = %i\n", valid_symbols[STRING_FRAGMENT]);
  DEBUG_PRINT("valid_symbols[MULTISTRING_START] = %i\n", valid_symbols[MULTISTRING_START]);
  DEBUG_PRINT("valid_symbols[MULTISTRING_PART_FIXED] = %i\n", valid_symbols[MULTISTRING_PART_FIXED]);
  DEBUG_PRINT("valid_symbols[MULTISTRING_IPOL_START] = %i\n", valid_symbols[MULTISTRING_IPOL_START]);
  DEBUG_PRINT("valid_symbols[MULTISTRING_END] = %i\n", valid_symbols[MULTISTRING_END]);

  if (valid_symbols[STRING_FRAGMENT]) {
    return scan_string_fragment(lexer);
  }
  if (valid_symbols[MULTISTRING_START]) {
    return scan_multistring_start(lexer);
  }
  if (valid_symbols[MULTISTRING_PART_FIXED] && valid_symbols[MULTISTRING_IPOL_START]) {
    DEBUG_PRINT("scan: both symbols are valid: MULTISTRING_PART_FIXED and MULTISTRING_IPOL_START\n");
    DEBUG_PRINT("scan: next_token = %i\n", next_token);
    if (next_token == MULTISTRING_IPOL_START) {
      return scan_multistring_richterm_start(lexer);
    }
  }
  if (valid_symbols[MULTISTRING_PART_FIXED]) {
    return scan_multistring_part_fixed(lexer);
  }
  if (valid_symbols[MULTISTRING_IPOL_START]) {
    return scan_multistring_richterm_start(lexer);
  }
  if (valid_symbols[MULTISTRING_END]) {
    return scan_multistring_end(lexer);
  }
  return false;
}

extern "C" unsigned tree_sitter_nickel_external_scanner_serialize(void *payload, char *buffer) {
  return 0;
}

extern "C" void tree_sitter_nickel_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) { }

extern "C" void tree_sitter_nickel_external_scanner_destroy(void *payload) { }
