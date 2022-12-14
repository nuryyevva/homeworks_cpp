#include <catch2/catch_test_macros.hpp>

#include "utils.hpp"

TEST_CASE("SplitString", "[simple]") {
  CHECK(SplitString("") == std::vector<std::string>{});
  CHECK(SplitString("aaa") == std::vector<std::string>{"aaa"});
  CHECK(SplitString("aaa aaa") == std::vector<std::string>{"aaa", "aaa"});
  CHECK(SplitString("aaa aaa ") == std::vector<std::string>{"aaa", "aaa"});
  CHECK(SplitString(" ") == std::vector<std::string>{});
  CHECK(SplitString("??? ??") == std::vector<std::string>{"???", "??"});
  CHECK(SplitString("a\na\ta a") == std::vector<std::string>{"a\na", "a", "a"});
  CHECK(SplitString("\n") == std::vector<std::string>{"\n"});
  CHECK(SplitString("a (a a)") == std::vector<std::string>{"a", "(a a)"});
  CHECK(SplitString("a (a a) b (asd as)  ") ==
        std::vector<std::string>{"a", "(a a)", "b", "(asd as)"});
  CHECK(SplitString("abc (ab (abab (ab a) bab) ca) abab") ==
        std::vector<std::string>{"abc", "(ab (abab (ab a) bab) ca)", "abab"});
  CHECK(SplitString("a (abb (b ba aa)aa) a (a)") ==
        std::vector<std::string>{"a", "(abb (b ba aa)aa)", "a", "(a)"});
}
