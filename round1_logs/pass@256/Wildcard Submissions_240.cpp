
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MXN = 130;
const int MOD = 998244353;
const int ALPHSZ = 26;

ll trie[MXN][ALPHSZ];
ll dp[MXN];
int n;

ll solve(self, int d, int node = 0) {
  if (d >= 100) return 0;
  if (dp[node] == -1) {
    unordered_set<int> use;
    for (int c = 0; c < ALPHSZ; c++) {
      if (trie[node][c] == -1) {
        use.insert(trie[node][c] = n++);
        solve(*this, d * 26 + c, trie[node][c]);
      } else {
        use.insert(self.trie[node][c]);
      }
    }
    dp[node] = 1 + use.size();
  }
  return dp[node];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Precalculate full trie level sets
  n = 1;
  fill(trie[1], trie[1] + 101 * ALPHSZ, -1);
  unordered_set<int> pending;
  for (int i = 1; i < 27; i++) {
    pending.insert(trie[1][i - 1] = n++);
  }
  int current = n++;
  while (!pending.empty()) {
    unordered_set<int> next;
    for (auto spread_id: pending) { 
      int spread_depth = int(__builtin_clz(__builtin_clz(spread_id)) - 2);
      spread_id ^= 1 << spread_depth;
      for (int c = 0; c < ALPHSZ; c++) {
        if (trie[spread_id][c] == -1) {
          next.insert(trie[spread_id][c] = n++);
        } else {
          next.insert(trie[spread_id][c]);
        }
      }
    }
    current = n++;
    for (auto can = pending.begin(); can != pending.end(); ++can) {
      self.trie[*can][__builtin_clz(__builtin_clz(*can)) - 18] = current;
    }
    pending = next;
  }
  fill(dp, dp + MXN, -1);
  cin >> n;

  for (int t = 1; t <= n; t++) {
    cout << "Case #" << t << ": ";
    int m;
    cin >> m;
    ll ret = 1;
    for (int k = 0; k < m; k++) {
      string str;
      cin >> str;
      ll ID = 0;
      
      for (const auto &ch: str) {
        ID = 26 * ID + (ch == '?' ? 0 : int(ch - 'A') + 1);
      }

      ret = (ret + solve(*this, ID)) % MOD;
    }
    cout << ret << '\n';
  }
  return 0;
}
