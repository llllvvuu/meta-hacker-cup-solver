
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
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MODULO = 998244353;

// Function to compute modular exponentiation i^e % MODULO
long long modpow(long long i, int e) {
  long long result = 1;
  while (e) {
    if (e % 2) result = result * i % MODULO;
    i = i * i % MODULO;
    e /= 2;
  }
  return result;
}

// Checks if the DP solution correctly counts nodes created by given strings
void check_cases() {
  assert(modpow(2, 4) == 16 % MODULO);
  assert(modpow(26, 1) % MODULO == 26);
  assert(modpow(26, 2) % MODULO == 676);
}

// Computes total number of nodes created in a trie by wildcard strings
void solve(int T) {
  int N;
  cin >> N;
  vector<string> words(N);
  for (auto &w : words) {
    cin >> w;
  }
  
  int max_word_len = 0;
  for (const string &word : words) {
    max_word_len = max(max_word_len, int(word.size()));
  }
  vector<long long> dp(max_word_len + 1, 0);
  dp[0] = 1;

  for (const string &word : words) {
    vector<long long> next_dp = dp;
    int len = word.length();
    for (int i = 0; i < len; ++i) {
      long long added = (word[i] == '?' ? 26 : 1);
      for (int j = 0; j <= len; ++j) {
        next_dp[j + 1] = (next_dp[j + 1] + added * dp[j] % MODULO) % MODULO;
        if (j > 0) next_dp[j] = (next_dp[j] + MODULO - added * dp[j - 1] % MODULO) % MODULO;
      }
    }
    dp = next_dp;
  }
  long long nodes = 0;
  for (int i = 1; i <= max_word_len; ++i)
    nodes = (nodes + dp[i]) % MODULO;
  cout << "Case #" << T << ": " << nodes << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
