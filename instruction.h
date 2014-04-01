#pragma once

#include <vector>
#include <string>

struct inst_t {
  enum class type_t {
    pow, imul, idiv, add, sub, setle,
    closure, ret, jz
  };
  // constructor that parse the given string into an instruction
  explicit inst_t(const std::string& repr);
  std::string toString() const;

  type_t code;
  std::string s_data;
  std::vector<int> i_data;
};
