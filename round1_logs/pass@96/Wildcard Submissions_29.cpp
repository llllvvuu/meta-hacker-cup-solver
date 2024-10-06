
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
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

struct Edge {
  int to;
  int ch;
};

vector<Edge> trie[(int) 1e6];
bool link[(int) 1e6];
int trans[(int) 1e6][26];
int dp[(int) 1e6][101];
int dp_sum[(int) 1e6][101];

void dfs(int u, int len) {
  if (link[u]) return;
  dp[u][len] = 1;
  for (int i = 0; i < 26; i++) {
    int v = trans[u][i];
    if (v == -1) continue;
    dfs(v, len + 1);
    for (int j = 0; j <= len; j++) {
      dp[u][j] += dp[v][j];
      dp[u][j] %= MOD;
      dp[u][j + 1] += dp[v][j];
      dp[u][j + 1] %= MOD;
    }
  }
  for (int j = 0; j <= len; j++) {
    dp_sum[u][j] = dp[u][j];
    for (int k = 1; k <= j; k++) {
      dp[u][j] += dp_sum[u][j - k];
      dp[u][j] %= MOD;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> sizes;
    for (int i = 0; i < N; i++) {
      cin >> S[i];
      sizes.push_back(S[i].size());
    }
    int root = 0;
    trie[0].push_back({0, 0});  // Initialize root node
    for (int i = 0; i < N; i++) {
      auto &s = S[i];
      int curr = 0;
      for (char ch : s) {
        if (ch == '?') continue;
        int index = ch - 'A';
        int valid = false;
        for (auto &[to, c] : trie[curr]) {
          if (c == index) {
            valid = true;
            curr = to;
            break;
          }
        }
        if (!valid) {
          int new_node;
          if (curr == 0) new_node = 1;
          else new_node = (int) trie[curr].size();
          trie[curr].push_back({new_node, index});
          trans[curr][index] = new_node;
          curr = new_node;
        }
      }
      link[curr] = true;
    }
    for (auto &[to, _] : trie[0]) dfs(to, sizes[i]);
    long long ans = 0;
    for (auto &[to, _] : trie[0]) for (int j = 0; j <= *max_element(sizes.begin(), sizes.end()); j++) {
      ans += dp[to][j];
      ans %= MOD;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
