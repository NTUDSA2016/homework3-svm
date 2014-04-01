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
  if (this->is_eof or not this->next_token.empty())
    return;
  for (;;) {
    if (this->cur == this->end) {
      if (not std::getline(this->input, this->token_buf)) {
        this->is_eof = true;
        break;
      }
      this->cur = this->token_buf.begin();
      this->end = this->token_buf.end();
    }
  }
}
