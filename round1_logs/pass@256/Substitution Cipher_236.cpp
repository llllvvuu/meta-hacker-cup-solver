
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
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int MOD = 998244353;

unordered_map<int, vector<pair<string, int>>> memo;

string recover(const string &s, int i) {
  if (i == s.size()) return "";
  if (memo.find(i) != memo.end()) return memo[i].back().first;

  vector<pair<string, int>> res;
  string prefix = "";
  for (int j = i; j < min<int>(i + 2, (int)s.size()); j++) {
    if (s[j] == '?') {
      prefix += '0';
    } else {
      prefix += s[j];
    }
    if (prefix.empty() || stoi(prefix) > 26) break;

    string tmp = recover(s, j + 1);
    for (int k = 0; k < tmp.size(); k++) {
      string n_string = prefix + tmp.substr(k);
      while (n_string.back() == '0') n_string.pop_back();
      if (!n_string.empty() && stoi(n_string) <= 26) {
        res.push_back({n_string, 1});
      }
    }
  }

  sort(begin(res), end(res), [](auto &a, auto &b) {
    return a.first.size() < b.first.size() || (a.first.size() == b.first.size() && a.first < b.first);
  });

  int sum = 0;
  for (auto &[str, sub] : res) {
    long long count = 1;
    if (!str.empty()) count = sub * (1 + min(str.size(), 2) - 1) % MOD;

    sum = (sum + sub) % MOD;
    res.back().second = sum;
  }

  memo[i] = res;
  return res.back().first;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string eq;
    int K;
    cin >> eq >> K;

    memo.clear();
    string result = recover(eq, 0);
    cout << "Case #" << t << ": " << result << " " << memo[0].back().second << "\n";
  }
  return 0;
}
