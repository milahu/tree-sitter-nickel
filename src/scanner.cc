#include <cwctype>
#include <stdint.h>
#include <tree_sitter/parser.h>

namespace {

enum TokenType {
  MULTSTR_START,
  MULTSTR_END,
  STR_START,
  STR_END,
  INTERPOLATION_START,
  INTERPOLATION_END,
};

struct Scanner {
  uint8_t interpolation_expected_percent_count;

  void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

  void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

  int32_t lookahead(TSLexer *lexer) {
    return lexer->lookahead;
  }

  unsigned serialize(char *buffer) {
    buffer[0] = interpolation_expected_percent_count;
    return 1;
  }

  void deserialize(const char *buffer, unsigned length) {
    // We have a constant size state, so this case should never happen. In case
    // it does, we initialize a fresh state.
    if (length != 1) {
      interpolation_expected_percent_count = 0;
    } else {
      interpolation_expected_percent_count = buffer[0];
    }
  }

  // Scans the multistring start. Assumes that the m indicating a multistring
  // was already consumed.
  bool scan_multstr_start(TSLexer *lexer) {
    lexer->result_symbol = MULTSTR_START;
    interpolation_expected_percent_count = 0;
    bool quote = false;

    // Count the number of percentages
    while (lookahead(lexer) == '%') {
      interpolation_expected_percent_count++;
      advance(lexer);
    }

    if (lookahead(lexer) == '"') {
      quote = true;
      advance(lexer);
    }

    // A START is fully scanned with we started with an 'm' (precondition of
    // this function), more than 0 percent signs (precondition of this
    // function), and a quote character.
    return quote;
  }

  // Scans the multistring end. Assumes that the " has already been consumed
  bool scan_multstr_end(TSLexer *lexer) {
    lexer->result_symbol = MULTSTR_END;
    bool m = false;

    // Consume all %-signs
    while (lookahead(lexer) == '%' &&
           interpolation_expected_percent_count > 0) {
      interpolation_expected_percent_count--;
      advance(lexer);
    }

    if (lookahead(lexer) == 'm') {
      m = true;
      advance(lexer);
    }

    // An END is fully scanned when we started with an '"' (precondition of
    // this function), consumed all %-signs and ended with an m.
    return (m && interpolation_expected_percent_count == 0);
  }

  // Precondition of this function is that the lookahead is '"'
  bool scan_str_start(TSLexer *lexer) {
    lexer->result_symbol = STR_START;

    // Interpolation in strings are preceded by a single % sign.
    interpolation_expected_percent_count = 1;

    advance(lexer);

    return true;
  }

  // Precondition of this function is that the lookahead is '"'
  bool scan_str_end(TSLexer *lexer) {
    lexer->result_symbol = STR_END;

    advance(lexer);

    return true;
  }

  bool scan_interpolation_start(TSLexer *lexer) {
    lexer->result_symbol = INTERPOLATION_START;

    bool brace = false;
    // local because we don't want to update the state
    uint8_t percent_count = 0;

    while (lookahead(lexer) == '%') {
      percent_count++;
      advance(lexer);
    }

    if (lookahead(lexer) == '{') {
      brace = true;
      advance(lexer);
    }

    return brace && (percent_count == interpolation_expected_percent_count);
  }

  // Precondition of this function is that the lookahead is '}'
  bool scan_interpolation_end(TSLexer *lexer) {
    lexer->result_symbol = INTERPOLATION_END;

    advance(lexer);

    return true;
  }

  bool scan(TSLexer *lexer, const bool *valid_symbols) {
    while (iswspace(lookahead(lexer))) {
      skip(lexer);
    }

    if (lookahead(lexer) == 'm' && valid_symbols[MULTSTR_START]) {
      advance(lexer);
      if (lookahead(lexer) == '%') {
        return scan_multstr_start(lexer);
      }
    }

    if (lookahead(lexer) == '"' && valid_symbols[MULTSTR_END]) {
      advance(lexer);
      if (lookahead(lexer) == '%') {
        return scan_multstr_end(lexer);
      }
    }

    if (lookahead(lexer) == '"' && valid_symbols[STR_START]) {
      return scan_str_start(lexer);
    }

    if (lookahead(lexer) == '"' && valid_symbols[STR_END]) {
      return scan_str_end(lexer);
    }

    if (lookahead(lexer) == '%' && valid_symbols[INTERPOLATION_START]) {
      return scan_interpolation_start(lexer);
    }

    if (lookahead(lexer) == '}' && valid_symbols[INTERPOLATION_END]) {
      return scan_interpolation_end(lexer);
    }

    return false;
  }
};

} // namespace

extern "C" {

void *tree_sitter_nickel_external_scanner_create() { return new Scanner(); }

bool tree_sitter_nickel_external_scanner_scan(void *payload, TSLexer *lexer,
                                              const bool *valid_symbols) {
  Scanner *scanner = static_cast<Scanner *>(payload);
  return scanner->scan(lexer, valid_symbols);
}

unsigned tree_sitter_nickel_external_scanner_serialize(void *payload,
                                                       char *state) {
  Scanner *scanner = static_cast<Scanner *>(payload);
  return scanner->serialize(state);
}

void tree_sitter_nickel_external_scanner_deserialize(void *payload,
                                                     const char *state,
                                                     unsigned length) {
  Scanner *scanner = static_cast<Scanner *>(payload);
  scanner->deserialize(state, length);
}

void tree_sitter_nickel_external_scanner_destroy(void *payload) {
  Scanner *scanner = static_cast<Scanner *>(payload);
  delete scanner;
}
}
