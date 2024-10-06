
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
const int64_t MOD = 998244353;

#include <unordered_set>
#include <iostream>
using namespace std;

int64_t processOneString(string pattern, const string& letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
  unordered_set<int64_t> seen;
  function<void(string, int, int64_t)> dfs = [&](string s, int pos, int64_t hashVal) {
    if (seen.count(hashVal)) return;
    seen.insert(hashVal);
    if (pos == pattern.size()) return;
    if (pattern[pos] == '?') {
      for (char ch : letters) {
        dfs(s + ch, pos + 1, hashVal * 26 + ch - 'A' + 1);
      }
    } else {
      dfs(s + pattern[pos], pos + 1, hashVal * 26 + pattern[pos] - 'A' + 1);
    }
  };
  dfs("", 0, 0);
  return seen.size();
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int64_t totalNodes = 1; // The root
    for (int i = 0; i < N; i++) {
      string S;
      cin >> S;
      totalNodes = (totalNodes + processOneString(S)) % MOD;
    }
    cout << "Case #" << t << ": " << totalNodes << '\n';
  }
  return 0;
}
