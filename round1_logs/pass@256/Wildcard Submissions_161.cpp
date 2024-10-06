
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
const int MOD = 998244353;
int dp[105][101]; // Number of strings with prefix of length i up to j characters

int dfs(vector<string>& p, int n, int i) {
  int& res = dp[n][i]; // retrieve current memoized result if any, else compute
  if (res != -1) return res; // has memoized result for i characters of n nodes
  string& pattern = p[n];
  if (i == (int)pattern.size() || pattern[i] == '?') // all characters matched or wildcard
    res = 1;
  else // for normal character, traverse further infer result from children nodes
    res = dfs(p, (pattern[i] - 'A'), i + 1); // consider a-z as 0 to 25 (A=0, B=1 ...)
  return res;
}

int solve(vector<string>& patterns) {
  int N = (int)patterns.size(), total = 1; // total will accumulate all result nodes
  for (int n = 0; n < N; n++) {
    memset(dp, -1, sizeof(dp)); // initialize or clear the cache
    total = (total + dfs(patterns, n, 0) - 1) % MOD;
  }
  return total; // total nodes modulo MOD
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, cases = 1; // counter for the number of test cases
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<string> patterns(N);
    for (int i = 0; i < N; i++) cin >> patterns[i];
    cout << "Case #" << cases++ << ": " << solve(patterns) << endl;
  }
}
