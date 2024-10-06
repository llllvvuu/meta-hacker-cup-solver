
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

const long long M = 998244353;
vector<int> trie[10001];
vector<long long> ways;
vector<int> alt;
vector<vector<int>> dp;

int dfs(int node, int idx) {
  if (dp[idx][node] != -1) return dp[idx][node];
  if (idx == -1) return dp[idx][node] = 1;
  dp[idx][node] = 0;
  if (trie[node].size() == 0 && idx > -1) return dp[idx][node] = 0;
  alt[idx] = trie[node].size() ? trie[node][0] : -1;
  dp[idx][node] = dfs(alt[idx], idx - 1);
  for (int i = 1; i < trie[node].size(); i++)
    dp[idx][node] = (dp[idx][node] + dfs(trie[node][i], idx)) % M;
  if (idx > 0) {
    dp[idx][node] = (dp[idx][node] + dfs(alt[idx], idx - 1) * 25) % M;
  }
  return dp[idx][node];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int N;
    cin >> N;
    ways = vector<long long>(N * 101);
    trie = vector<vector<int>>(N * 101);
    alt = vector<int>(101);
    dp = vector<vector<int>>(101, vector<int>(N * 101, -1));
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.length(); j++) {
        if (j == 0) {
          if (s[j] != '?') trie[i].push_back(i + 1);
        } else {
          int last = i * 101 + (j - 1);
          if (s[j] != '?') {
            trie[last].push_back(i * 101 + j);
          } else {
            for (int c = 0; c < 26; c++) trie[last].push_back(i * 101 + j);
          }
        }
      }
    }
    for (int i = N; i < N * 101; i++) dfs(alt[0] = i * 101, 100);
    long long ans = 1;
    for (int i = 0; i < 100; i++) {
      ways[i] += ways[i + 1];
      ans = (ans + ways[i]) % M;
    }
    cout << "Case #" << cas << ": " << ans << endl;
  }
  return 0;
}
