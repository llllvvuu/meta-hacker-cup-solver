
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

using namespace std;

const int MOD(998244353);
int dp[26][101], N, T;
vector<string> vectors;

// Function to solve and count nodes
int solve() {
  // Initializing all node counts as zero
  for (int i = 0; i < 26; ++i) for (int j = 0; j <= 100; ++j) dp[i][j] = 0;

  // For every wildcard string
  for (auto &it : vectors) {
    int qmarks = 0;
    for (auto &c : it) qmarks += c == '?';
    int prev = 1;
    for (int i = 0; i < it.size(); ++i) {
      char c = it[i];
      dp[islower(c) ? c - 'A' : 0][i + 1] += prev * (qmarks + 1);
      if (c == '?') {
        for (int j = 0; j < 26; ++j) {
          dp[j][i + 1] += prev;
        }
      } else if (islower(c)) {
        dp[c - 'A'][i + 1] += prev - dp[c - 'A'][i];
      }
      prev = dp[c == '?' ? 0 : c - 'A'][i + 1];
    }
  }

  // Compute the sum of unique nodes
  int sum = 1;
  for (int i = 0; i < 26; ++i)
    for (int j = 0; j <= 100; ++j)
      sum = (sum + dp[i][j]) % MOD;

  return sum - 26 * 100 % MOD;
}

int main() {
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    vectors.clear();
    vectors.resize(N);
    for (int i = 0; i < N; ++i)
      cin >> vectors[i];
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
