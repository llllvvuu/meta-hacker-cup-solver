
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

long long int mod = 998244353;

/**
 * Fills in the DP table where dp[i][p] holds the # of unique prefixes ending
 * at position i (indexing from 0) with length p
 *
 * @param wildcards A vector containing all wildcard strings
 * @param dp A reference to the DP table
 */
void fillDP(vector<string> &wildcards, vector<vector<long long int>> &dp) {
  dp[0][wildcards[0][0] == '?' ? 26 : 1] = 1;
  for (int i = 1; i < wildcards.size(); i++) {
    long long int max_length = wildcards[i].size();
    for (int l = 1; l <= max_length; l++) {
      // Merge states representing the same prefix length 
      dp[i][l] = dp[i - 1][l];
      if (wildcards[i][l - 1] == '?' && wildcards[i - 1][l - 1] == '?') {
        dp[i][l] += dp[i - 1][l - 1] * 26;
        dp[i][l] %= mod;
        if (l == max_length) dp[i][max_length + 1] += dp[i - 1][max_length];
      } else if (wildcards[i][l - 1] != '?' && wildcards[i - 1][l - 1] != '?' &&
                 wildcards[i][l - 1] != wildcards[i - 1][l - 1]) {
        dp[i][l] += dp[i - 1][l - 1] + (l < max_length ? 26 * dp[i - 1][l - 1] : 0);
        dp[i][l] %= mod;
        if (l == max_length) dp[i][max_length + 1] += dp[i - 1][max_length];
      }
    }
  }
}

/**
 * Computes the total number of nodes in the trie.
 *
 * @param wildcards A vector of all wildcard strings
 */
long long int computeNodes(vector<string> wildcards) {
  auto it = max_element(wildcards.begin(), wildcards.end(),
                        [](string a, string b) { return a.size() < b.size(); });
  int maxlength = it->length();
  vector<vector<long long int>> dp(wildcards.size(), vector<long long int>(maxlength + 2, 0));
  fillDP(wildcards, dp);
  return dp[wildcards.size() - 1][maxlength];
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> wildcards(N);
    for (int i = 0; i < N; i++) {
      cin >> wildcards[i];
    }
    cout << "Case #" << t << ": " << computeNodes(wildcards) % mod << endl;
  }
  return 0;
}
