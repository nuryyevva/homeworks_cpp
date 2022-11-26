#include "utils.hpp"

#include <stack>

std::vector<std::string> SplitString(const std::string &data) {
  std::string word = "";
  std::vector<std::string> words;
  for (int i = 0; i < data.size(); i++) {
    if (data[i] == ' ' || data[i] == '\t') {
      if (!word.empty()) {
        words.push_back(word);
      }
      word.clear();
    } else {
      if (data[i] == '\n') {
        word.push_back('\n');
        // word.push_back('n');
      } else {
        word.push_back(data[i]);
      }
    }
    if (data[i] == ' ' && data[i + 1] == '(') {
      while (data[i] != ')') {
        word.push_back(data[i + 1]);
        i++;
      }
      i += 1;
      words.push_back(word);
      word.clear();
    }
  }
  if (!word.empty()) {
    words.push_back(word);
  }
  return {words};
}
