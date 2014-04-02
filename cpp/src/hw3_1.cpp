#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>

#include "hw3_1.h"
#include "instruction.h"

using std::list;
using std::vector;
using std::string;

int main() {
  list<inst_t> insts(Parser(std::cin).parse());
  for (const inst_t& inst : insts)
    std::cout << inst.toString() << std::endl;
  return 0;
}

list<inst_t> Parser::parseExpr() {
  // TODO: implement your algorithm here
  return list<inst_t>();
}

// Below are the utility and provided functions.
// You can safely skip all of them
list<inst_t> Parser::parseTopExpr() {
  const auto eat = [this](const char *s) -> bool {
    if (not this->hasMore()) return false;
    if (s!=nullptr and this->peekToken() != s) return false;
    this->nextToken();
    return true;
  };
  if (not this->hasMore())
    throw std::runtime_error("empty input");
  if (eat("if")) {
    list<inst_t> con(this->parseExpr());

    if (not eat("then")) throw std::runtime_error("expecting 'then'");
    list<inst_t> th(this->parseExpr());
    th.push_back({inst_t::type_t::ret, "", {}});

    if (not eat("else")) throw std::runtime_error("expecting 'else'");
    list<inst_t> el(this->parseExpr());
    th.push_back({inst_t::type_t::ret, "", {}});

    list<inst_t> buf;
    buf.splice(buf.end(), con);
    buf.push_back({inst_t::type_t::jz, "", {th.size(), th.size() + el.size()}});
    buf.splice(buf.end(), th);
    buf.splice(buf.end(), el);
    return buf;
  } else if (eat("\\")) {
    string id = this->nextToken();
    if (not eat("->")) throw std::runtime_error("expecting '->'");
    list<inst_t> body(this->parseTopExpr());
    body.push_back({inst_t::type_t::ret, "", {}});

    list<inst_t> buf;
    buf.push_back({inst_t::type_t::closure, id, {body.size()}});
    buf.splice(buf.end(), body);
    return buf;
  } else {
    return this->parseExpr();
  }
}

list<inst_t> Parser::parse() {
  Tokenizer tokenizer(this->input_stream);
  while (tokenizer.hasMore())
    this->tokens.emplace_back(tokenizer.nextToken());
  this->cur = this->tokens.cbegin();
  return this->parseTopExpr();
}

string Parser::peekToken() {
  if (not this->hasMore())
    throw std::runtime_error("Parser::peekToken(): going over the end");
  return *this->cur;
}

string Parser::nextToken() {
  if (not this->hasMore())
    throw std::runtime_error("Parser::nextToken(): going over the end");
  string token(*this->cur);
  ++this->cur;
  return token;
}
