#pragma once

#include <fstream>
#include <string>

class Tokenizer {
  std::istream& input;
  std::string next_token;
  std::string token_buf;
  std::string::const_iterator cur, end;
  bool is_eof;

  void fill_token();
public:
  /*
  @param input_stream: the input of the tokenizer
  @description:
    create a tokenizer that takes the input from
    `input_stream`. `input_stream` should be alive
    through the lifetime of the Tokenizer.
  */
  Tokenizer(std::istream& input_stream)
    : input(input_stream), is_eof(false)
  {
    this->cur = token_buf.end();
    this->end = token_buf.end();
  }

  /*
  @description: return if there are any tokens
  */
  bool has_more();

  /*
  @description: peek the next token in the buffer
  */
  std::string peekToken();

  /*
  @description:
    remove the next token from the buffer and return it
  */
  std::string nextToken();
};
