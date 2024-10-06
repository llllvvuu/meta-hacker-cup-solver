
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

const int MOD = 998244353;

int n;
vector<string> s;

//Function to count branches for a subset represented as an index array
int f(const vector<int> &myset) {
  set<string> branches;
  vector<bool> asdp(26);
  map<string, vector<string>> m;
  set<string> dup;

  //Function to extend branch
  auto dfs = [&](auto dfs, string str) -> int {
    if (asdp == vector<bool>(26, true)) {
      return branches.size() > dup.size();
    }
    int res = 0;
    for (const auto &i: myset) {
      if (!asdp[str[0]-'A']) {
        if (str == " ") dup.insert(" "), continue;
        auto it = m.find(str);
        if (it == end(m)) continue;
        for (const auto &w: it->second) {
          for (const auto &c: w) {
            asdp[c - 'A'] = true;
          }
          res += dfs(dfs, c + (w.back() == '?' ? "" : w.substr(1)));
          for (const auto &c: w) {
            asdp[c - 'A'] = false;
          }
          if (!str.empty()) {
            dup.insert(str);
          }
        }
      }
    }
    return res;
  };

  //Preprocess: Fill m and asdp
  for (int i = 0; i < n; i++) {
    string root = "";
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '?') {
        for (char c = 'A'; c <= 'Z'; c++) root += c;
      } else {
        root += s[i][j];
        m[root].push_back(s[i]);
      }
    }
    if (root.size()) {
      asdp[root[0]-'A'] = true;
      if (root.size() > 1)
        branches.insert(root.substr(0, root.size()-1));
    }
  }

  return dfs(dfs, " ");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    long long res = 0;
    for (int i = 1; i < (1 << n); i++) {
      vector<int> myset;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) myset.push_back(j);
      }
      res = (res + f(myset)) % MOD;
    }
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}
