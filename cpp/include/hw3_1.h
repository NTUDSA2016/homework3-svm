#pragma once

#include <fstream>
#include <list>
#include <string>
#include "tokenizer.h"   // `Tokenizer` is defined here
#include "instruction.h" // `inst_t` is defined here

class Parser {
  Tokenizer input;
public:
  /*
  @param input_stream: an input `istream` (e.g. cin)
  @description: create a parser with input `input_stream`
  */
  Parser(std::istream& input_stream)
    : input(input_stream) {}
  /*
  @description:
    Parse the input into SVM instructions.
  */
  std::list<inst_t> parse() { return this->parseTopExpr(); }
private:
  /*
  @return: the compiled instructions
  @description: the provided function that handles `topexpr`
  */
  std::list<inst_t> parseTopExpr();
  /*
  @return: the compiled instructions
  @description:
    the function you need to implement. This function
    should handle `expr` and call `topexpr` when needed.
  */
  std::list<inst_t> parseExpr();
};
