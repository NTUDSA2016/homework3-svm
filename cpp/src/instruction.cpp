#include <vector>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "instruction.h"

using std::string;
using std::vector;

// add an hash instance for the enum class inst_t::type_t
// simply casts the (strongly typed) enum to its underlying type
// http://stackoverflow.com/questions/18837857/
namespace std {
  template<>
  struct hash< ::inst_t::type_t> {
    typedef ::inst_t::type_t argument_type;
    typedef std::underlying_type<argument_type>::type underlying_type;
    typedef std::hash<underlying_type>::result_type result_type;
    result_type operator()(const argument_type& key) const {
      std::hash<underlying_type> hash_fn;
      return hash_fn(static_cast<underlying_type>(key));
    }
  };
}

inst_t inst_t::parse(const string&) {
  throw std::logic_error("inst_t::parse is not implemented");
}

string inst_t::toString() const {
  static const std::unordered_map<type_t, string> inst_str = {
      {type_t::pow, "pow"}, {type_t::imul, "imul"}, {type_t::idiv, "idiv"},
      {type_t::add, "add"}, {type_t::sub, "sub"},   {type_t::setle, "setle"},
      {type_t::push, "push"}, {type_t::access, "access"},
      {type_t::closure, "closure"}, {type_t::apply, "apply"},
      {type_t::ret, "ret"}, {type_t::jz, "jz"}
  };
  string res = inst_str.at(this->code);
  if (this->s_data.size())
    res += " " + this->s_data;
  for (int k : this->i_data)
    res += " " + std::to_string(k);
  return res;
}
