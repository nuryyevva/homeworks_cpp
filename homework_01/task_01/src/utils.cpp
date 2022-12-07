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
      word.push_back(data[i]);
    }
    if (data[i] == ' ' && data[i + 1] == '(') {
      int open_brackets = 1;
      int close_brackets = 0;
      while (close_brackets / open_brackets != 1 ||
             close_brackets % open_brackets != 0) {
        if (data[i + 2] == '(') {
          open_brackets += 1;
        }
        if (data[i + 1] == ')') {
          close_brackets += 1;
        }
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
