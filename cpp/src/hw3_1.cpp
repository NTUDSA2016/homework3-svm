#include <iostream>
#include <list>
#include <string>

#include "hw3_1.h"
#include "instruction.h"

using std::list;
using std::string;

list<inst_t> Parser::parseTopExpr() {
}

list<inst_t> Parser::parseExpr() {
  // TODO: implement your algorithm here
}

int main() {
  list<inst_t> insts(Parser(std::cin).parse());
  for (const inst_t& inst : insts)
    std::cout << inst.toString() << std::endl;
  return 0;
}
