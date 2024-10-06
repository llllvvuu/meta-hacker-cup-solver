
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
#include <cstring>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

const int MOD = 998244353;

int dp[101][27]; // Max index is 100 by constraints.
bool vis[101][27];
long long ans = 0;

void dfs(int len, int c) {
  if (vis[len][c]) {
    ans += dp[len][c];
    return;
  }
  vis[len][c] = true;
  for (auto &wcset : getNext(c, len)) {
    int cnt = wcset.size();
    if (cnt == 0) {
      dp[len][c]++;
      continue;
    }
    for (auto i : wcset) {
      dfs(i, c);
    }
    if (cnt == 1) {
      dp[len][c]++;
    } else {
      dp[len][c] += (1LL * cnt * (cnt - 1) / 2); // combination, choose 2
    }
    dp[len][c] %= MOD;
  }
}

vector<vector<int>> getNext(int c, int len) {
  vector<int> leaves;
  for (int i = 0; i < len; i++) {
    vector<int> withWild = {};
    for (int j = 0; j < 26; j++) {
      // If all other characters are wildcards or match the character c
      if (nextMatch(c, i, j)) leaves.push_back(i);
    }
    if (leaves.size() == 26) {
      leaves = {};
    }
    sort(begin(leaves), end(leaves));
    leaves.erase(unique(begin(leaves), end(leaves)), end(leaves));
    int prev = -1;
    vector<vector<int>> res;
    for (int x : leaves) {
      if (x != prev)
        res.push_back({x});
      else if (res.back().size() == 26) continue;
      res.back().push_back(x);
      prev = x;
    }
    leaves.clear();
    copy(begin(res.back()), end(res.back()), back_inserter(leaves));
    if (leaves.empty()) continue;
    sort(begin(leaves), end(leaves));
    leaves.erase(unique(begin(leaves), end(leaves)), end(leaves));
    wcset.push_back(leaves);
  }
  subst[c][len] = wcset;
  return wcset;
}

bool nextMatch(int c, int i, int j) {
  return c == i || j == 25;
}

int main() {
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    ans = 0;
    fill(dp[0], dp[101], -1);
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < 26; i++) dfs(0, i);
    cout << "Case #" << t << ": " << (ans % MOD) << endl;
  }
}
