#include <map>
#include <string>
#include <vector>

using namespace std;

string evaluate(string s, vector<vector<string>>& knowledge) {
  map<string, string> dict;
  for (vector<string>& term : knowledge) {
    dict.insert({term[0], term[1]});
  }

  auto it = s.begin() - s.begin();
  const auto bg = s.begin();
  while (true) {
    auto lbrack = s.find("(", it);
    auto rbrack = s.find(")", it);
    if (lbrack == std::string::npos) {
      break;
    }
    string key_i = s.substr(lbrack + 1, (rbrack - lbrack) - 1);
    string value_i;
    map<string, string>::iterator fd = dict.find(key_i);
    if (fd != dict.end()) {  // found
      s.replace(lbrack, (rbrack - lbrack) + 1, fd->second);
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
