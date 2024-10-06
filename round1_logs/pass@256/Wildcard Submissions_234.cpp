
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
typedef long long ll;

const int MOD = 998244353;

struct Trie {
  vector<vector<int>> edges;
  vector<int> cnt;

  Trie() : edges(1, vector<int>(26, -1)), cnt(1, 1) {}

  void add(const string& w) {
    int u = 0;
    for (char ch : w) {
      int idx = ch - 'A';
      if (edges[u][idx] == -1) {
        edges[u][idx] = edges.size();
        edges.emplace_back(vector<int>(26, -1));
        cnt.emplace_back(0);
      }
      u = edges[u][idx];
      cnt[u]++;
    }
  }

  int get() { return cnt[0]; }
};

bool vis[2][1 << 26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T, N, Q;
  string s;
  ll ans;
  Trie trie;

  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    trie = Trie();
    memset(vis, 0, sizeof(vis));

    for (int n = 0; n < N; n++) {
      cin >> s;
      Q = 0;
      for (char ch : s) {
        if (ch == '?') Q++;
      }
      for (int mask = 0; mask < (1 << Q); mask++) {
        if (vis[Q & 1][mask]) continue;
        trie.add(s);
        vis[Q & 1][mask] = true;
      }
    }
    ans = trie.get();
    cout << "Case #" << t << ": " << ans << endl;
  }
  
  return 0;
}
