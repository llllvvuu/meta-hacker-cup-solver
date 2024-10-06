
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

int dp[1 << 25][100];

int solve(const vector<string> &wildcards, int state, int length) {
  if (length == (int)wildcards[0].size()) return 1; // reached end of prefix
  if (dp[state][length] != -1) return dp[state][length];
  dp[state][length] = 0;
  for (int i = 0; i < wildcards.size(); i++) {
    if (state & (1 << i)) continue; // already processed this wildcard
    bool isPossible = true;
    for (int j = i; j < wildcards.size(); j++) {
      if ((state & (1 << j)) == 0 && wildcards[j][length] != '?' && wildcards[j][length] != wildcards[i][length]) {
        isPossible = false;
        break;
      }
    }
    if (isPossible) {
      dp[state][length] = (dp[state][length] + solve(wildcards, state | (1 << i), length + 1)) % MOD;
    }
  }
  return dp[state][length];
}

long long modInv(long long a, long long m) {
  if (a == 0) return 0;
  int m0 = m;
  int y = 0, x = 1;
  while (a > 1) {
    int q = a / m;
    tie(m, a) = make_tuple(a % m, m);
    tie(y, x) = make_tuple(x - q * y, y);
  }
  return x < 0 ? x + m0 : x;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    vector<string> wildcards(N);
    for (int i = 0; i < N; i++) {
      cin >> wildcards[i];
    }
    int max_length = 0;
    for (const auto& str: wildcards) {
      max_length = max(max_length, (int)str.size());
    }
    for (int i = 0; i < 1 << N; i++) {
      for (int j = 0; j <= max_length; j++) {
        dp[i][j] = -1;
      }
    }
    int result = solve(wildcards, 0, 0);
    result = (result * modInv(26, modInv(26 - N + 1, MOD))) % MOD;
    cout << result << '\n';
  }
  return 0;
}
