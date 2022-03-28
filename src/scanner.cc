#include <stdint.h>
#include <tree_sitter/parser.h>

namespace {

enum TokenType {
  MULTSTR_START,
  MULTSTR_END,
};

struct Scanner {
  uint8_t delimiter_percent_count;
  bool started_multstr;

  void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

  void advance(TSLexer *lexer) {
    lexer->advance(lexer, false);
  }

  unsigned serialize(char *buffer) {
    buffer[0] = delimiter_percent_count;
    buffer[1] = started_multstr;
    return 2;
  }

  void deserialize(const char *buffer, unsigned length) {
    // We have a constant size state, so this case should never happen. In case
    // it does, we initialize a fresh state.
    if (length != 2) {
      delimiter_percent_count = 0;
      started_multstr = false;
    } else {
      delimiter_percent_count = buffer[0];
      started_multstr = buffer[1];
    }
  }

  // Scans the multistring start. Assumes that the m indicating a multistring
  // was already consumed.
  bool scan_multstr_start(TSLexer *lexer) {
    lexer->result_symbol = MULTSTR_START;
    started_multstr = true;
    delimiter_percent_count = 0;
    bool quote = false;

    // Count the number of percentages
    while (lexer->lookahead == '%') {
      delimiter_percent_count++;
      advance(lexer);
    }

    if (lexer->lookahead == '"') {
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
    started_multstr = false;
    bool m = false;

    // Consume all %-signs
    while (lexer->lookahead == '%' && delimiter_percent_count > 0) {
      delimiter_percent_count--;
      advance(lexer);
    }

    if (lexer->lookahead == 'm') {
      m = true;
      advance(lexer);
    }

    // An END is fully scanned when we started with an '"' (precondition of
    // this function), consumed all %-signs and ended with an m.
    return (m && delimiter_percent_count == 0);
  }

  bool scan(TSLexer *lexer, const bool *valid_symbols) {
    if (lexer->lookahead == 'm') {
      advance(lexer);
      if (lexer->lookahead == '%') {
        return scan_multstr_start(lexer);
      }
    }

    if (lexer->lookahead == '"') {
      advance(lexer);
      if (lexer->lookahead == '%') {
        return scan_multstr_end(lexer);
      }
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
