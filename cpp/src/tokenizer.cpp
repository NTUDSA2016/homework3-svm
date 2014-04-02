#include <cctype>
#include <fstream>
#include <string>
#include <stdexcept>
#include "tokenizer.h"

using std::string;

bool Tokenizer::has_more() {
  this->fill_token();
  return not this->is_eof;
}

string Tokenizer::peekToken() {
  this->fill_token();
  if (this->is_eof)
    throw std::runtime_error("Tokenizer::peekToken(): going over end of input");
  return this->next_token;
}

string Tokenizer::nextToken() {
  this->fill_token();
  if (this->is_eof)
    throw std::runtime_error("Tokenizer::nextToken(): going over end of input");
  string token;
  this->next_token.swap(token);
  return token;
}

void Tokenizer::fill_token() {
  using std::isdigit;
  using std::isalpha;
  using std::isalnum;
  using std::isspace;
  static const char* syms[] = {
    "->", "<=", "\\", "(", ")",
    "@", "^", "*", "/", "+", "-",
    nullptr
  };
  if (this->is_eof or not this->next_token.empty())
    return;
  for (;;) {
    if (this->cur == this->end) {
      if (not std::getline(this->input, this->token_buf)) {
        this->is_eof = true;
        break;
      }
      this->cur = this->token_buf.cbegin();
      this->end = this->token_buf.cend();
    }
    string::const_iterator nxt = this->cur;
    if (isspace(*nxt)) {
      ++this->cur;
      continue;
    } else if (nxt+1 != this->end and *nxt=='/' and *(nxt+1)=='/') { // comment
      this->cur = this->end;
      continue;
    } else if (isdigit(*nxt)) { // [0-9]+
      while (isdigit(*nxt)) ++nxt;
    } else if (isalpha(*this->cur) or *this->cur=='_') { // [_a-zA-z][_a-zA-z0-9]*
      while (isalnum(*nxt) or *nxt=='_') ++nxt;
    } else { // symbols
      size_t i;
      for (i = 0; syms[i]; ++i) {
        int k;
        for (k = 0, nxt = cur; syms[i][k] and nxt!=this->end; ++k, ++nxt)
          if (syms[i][k] != *nxt) break;
        if (syms[i][k] == '\0')
          break;
      }
      if (not syms[i])
        throw std::runtime_error(string("Tokenize::fill_token(): unknown input symbol ") + *nxt);
    }
    this->next_token = string(this->cur, nxt);
    this->cur = nxt;
    break;
  }
}
