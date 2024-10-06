
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
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
constexpr long long MOD = 998244353;

long long solve(const std::string &s, std::vector<long long> &previous) {
  long long dp[5][105];  // Truthful length + 1, subject string length + 1
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;  // Base case: empty prefix contributing one empty string

  for (size_t j = 0; j < s.length(); ++j) {
    if (s[j] == '?') {
      // handle '?' by branching off from each position
      for (int i = 0; i < 5; ++i) {
        for (int k = 0; k <= j; ++k) {
          dp[i][(int)j + 1] += previous[k] * (i > 0) + dp[i][k];
          dp[i][(int)j + 1] %= MOD;
        }
      }
    } else {
      // pass the character, update only one state
      for (int i = 0; i < 5; ++i) {
        dp[i + (s[j] <= 'M')][(int)j + 1] += dp[i][j];
        dp[i + (s[j] <= 'M')][(int)j + 1] %= MOD;
      }
    }
  }

  // sum the entire inserted edges to get counts
  long long total = 0;
  for (int i = 0; i <= 4; ++i) {
    for (int j = 0; j <= 100; ++j) {
      total += dp[i][j];
      total %= MOD;
    }
  }

  return total;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 1; i <= t; ++i) {
    int n;
    std::cin >> n;
    std::vector<std::string> wildcards(n);
    for (auto &wildcard : wildcards) {
      std::cin >> wildcard;
    }

    // init the storage for counting edges, ignorable initializer list
    std::vector<long long> previous(101);
    previous[0] = 1;  // empty string adds one root node
    for (const auto &wildcard : wildcards) {
      long long newEdgeCount = solve(wildcard, previous);
      // shift the counts for the new wildcard insertion
      for (int j = 1; j <= (int)wildcard.length(); ++j) {
        current[j] += newEdgeCount;
        current[j] %= MOD;
      }
    }

    std::cout << "Case #" << i << ": " << current.back() << std::endl;
  }
  return 0;
}
