
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
using vi = vector<int>;

const int MOD = 998244353;

vi dp = {1}, char_match;

int trie_pattern(int n) {
  for (int i = 1; i < n; ++i) {
    dp.emplace_back(i == n - 1 ? (char_match[i]) : 0);
    for (int j = i - 1, p = 1; j >= max(0, i - 25); --j) {
      while (char_match[j]) {
        dp[i] += 1LL * dp[j] * char_match[j] % MOD * p;
        p *= max(char_match[j--], 1);
      }
      dp[i] %= MOD;
    }
  }
  return accumulate(dp.begin(), dp.end(), 0) % MOD;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    char_match = vi(100, 1);
    for (int i = 0; i < N; ++i) {
      int len;
      string str;
      cin >> len >> str;
      for (int j = 0; j < len; ++j) {
        char_match[j] &= str[j] == '?';
      }
    }
    cout << "Case #" << t << ": " << trie_pattern(len) << '\n';
  }
  return 0;
}
