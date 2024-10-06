
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
#include <string>
#include <set>
using namespace std;

const int MOD = 998244353;

void addPrefix(string t) {
  set<string> seen;
  function<void(string, int, int)> dfs = [&](string cur, int i, int quota) -> void {
    if (quota < 0) return;
    if (i == t.size()) {
      seen.insert(cur);
      return;
    }
    if (t[i] == '?') {
      for (char ch = 'A'; ch <= 'Z'; ch++) {
        dfs(cur + ch, i + 1, quota - 1);
      }
    } else {
      dfs(cur + t[i], i + 1, quota);
    }
  };
  dfs("", 0, t.size() - 1);
  for (const string& prefix : seen) {
    unique_prefixes.emplace(prefix);
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    unique_prefixes.clear();
    for (int i = 0; i < N; i++) {
      string t;
      cin >> t;
      addPrefix(t);
    }
    cout << "Case #" << t << ": " << unique_prefixes.size() % MOD << endl;
  }
  return 0;
}
