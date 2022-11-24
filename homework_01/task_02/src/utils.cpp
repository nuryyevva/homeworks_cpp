#include "utils.hpp"

#include <stack>

int Calculate(const std::string &data) {
  std::string number = "";
  std::vector<std::string> nums_to_calc;
  for (auto x : data) {
    if (x == '+' || x == '-' || x == '*') {
      nums_to_calc.push_back(number);
      number = "";
    } else {
      number += x;
    }
  }
  nums_to_calc.push_back(number);
  int m = std::stoi(nums_to_calc[0]);
  int n = std::stoi(nums_to_calc[1]);
  for (auto x : data) {
    if (x == '+') {
      return (m + n);
    }
    if (x == '-') {
      return (m - n);
    }
    if (x == '*') {
      return (m * n);
    }
  }
  return 0;
}
