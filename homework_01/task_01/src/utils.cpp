#include "utils.hpp"

#include <stack>

std::vector<std::string> SplitString(const std::string &data) {
  std::string a = "";
  std::vector<std::string> b;
  for (auto x : data) {
    if (x == ' ') {
      b.push_back(a);
      a = "";
    } else {
      a = a + x;
    }
  }
  b.push_back(a);
  return {b};
}
