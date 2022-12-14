#include "utils.hpp"

#include <stack>

int Calculate(const std::string &data) {
  std::string number = "";
  std::vector<std::string> nums_to_calc;
  for (int i = 0; i < data.size(); i++) {
    if (data[i] == '+' || data[i] == '-' || data[i] == '*') {
      nums_to_calc.push_back(number);
      number.clear();
    } else {
      number += data[i];
    }
  }
  nums_to_calc.push_back(number);
  int m = std::stoi(nums_to_calc[0]);
  int n = std::stoi(nums_to_calc[1]);
  for (int j = 0; j < data.size(); j++) {
    if (data[j] == '+') {
      return (m + n);
    }
    if (data[j] == '-') {
      return (m - n);
    }
    if (data[j] == '*') {
      return (m * n);
    }
  }
  return 0;
}
