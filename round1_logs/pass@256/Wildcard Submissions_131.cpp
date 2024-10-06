
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
#include <vector>
using namespace std;

const int MOD = 998244353;

int N;

struct edge {
  int dst;
  vector<int> rel;
};

vector<edge> g[(1 << 26) + 4];

bool vis[(1 << 26) + 4];

void ch_add(int c, int &cur, int &dp) {
  if (c == '?') return;
  if (!dp) {
    cur = cur * 26 + c - 'A';
    ++dp;
  }
  int mp = 1;
  int last = 0;
  for (int i = 0; i < 26; ++i) {
    if (i + 'A' != c) {
      cur += last * mp;
      cur %= MOD;
      ++mp;
      ++dp;
    } 
    last = (int)pow(26, i + dp);
  }
}

int dfs(int n) {
  vis[n] = 1;
  int res = 1;
  for (int i = 0; i < g[n].size(); ++i) {
    if (!vis[g[n][i].dst]) {
      res += dfs(g[n][i].dst);
      res %= MOD;
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  for (int q = 1; q <= t; ++q) {
    cin >> N;
    // resetting bitmask adjacencies for every case
    for (int i = 0; i < (1 << 26); ++i) {
      g[i].clear();
      vis[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      int v = 0, v_org = 0, len = 0;
      int dp = 0;
      for (char c : s) {
        ch_add(c, v, dp);
        if (c != '?') {
          int copy = v;
          g[v_org].push_back({v, {v}});
          len += (dp - 1);
          if (len) {
            for (int j = 0; j < g[v].size(); ++j) {
              g[v_org].push_back({v, g[v][j].rel});
            }
          }
          v_org = v;
          v = 0;
          dp = 0;
        }
      }
      if (dp != 0 && v < (1 << 26)) {
        g[v_org].push_back({v, {v}});
      }
    }
    cout << "Case #" << q << ": ";
    cout << dfs(0) << endl;
  }
  return 0;
}
