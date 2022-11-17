#include <string>
#include <vector>

using namespace std;

string evaluate(string s, vector<vector<string>>& knowledge) {
  auto it = s.begin() - s.begin();
  const auto bg = s.begin();
  while (true) {
    auto lbrack = s.find("(", it);
    auto rbrack = s.find(")", it);
    if (lbrack == std::string::npos) {
      break;
    }
    string key_i = s.substr(lbrack + 1, (rbrack - lbrack) - 1);
    bool found = false;
    string value_i;
    for (auto p : knowledge) {
      if (p[0] == key_i) {
        found = true;
        value_i = p[1];
        break;
      }
    }
    if (found) {
      s.replace(lbrack, (rbrack - lbrack) + 1, value_i);
    } else {
      s.replace(lbrack, (rbrack - lbrack) + 1, "?");
    }
  }
  return s;
}

int main(int argc, char const* argv[]) {
  /* code */
  string s = "(a)(a)(a)aaa";
  vector<vector<string>> knowledge = {{"a", "yes"}};
  s = evaluate(s, knowledge);
  return 0;
}
