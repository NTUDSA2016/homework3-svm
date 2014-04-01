#pragma once

#include <fstream>
#include <string>

class Tokenizer {
  std::istream& input;
public:
  Tokenizer(std::istream& input_stream)
    : input(input_stream) {}
  std::string peekToken();
  std::string nextToken();
};
