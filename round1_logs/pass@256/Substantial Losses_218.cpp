
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
const int mod = 998244353;

long long expectedSteps(long long W, long long G, long long L) {
  if (W <= G || G - W > L) return 0; // No chance to reach G without overstepping L constraint
  if (W == G + 1 && L == 0) return 1; // Always one day to reach G if W is G+1 and L is 0

  long long N = G - L; // N defines the range where we can apply dynamic programming
  vector<long long> dp(N + 1); // dp[i] - expected steps to reach G from i
  
  dp[N] = 0; // Reach G from G itself requires no more steps

  long long inv2 = (mod + 1) / 2; // Inverse of 2 modulo 998244353

  for (long long i = N - 1; i >= G; --i) {
    if (W - i > L) {
      dp[i] = dp[i + 1]; 
    } else {
      // Calculate expectation value using the relationship mentioned above
      dp[i] = 1 + inv2 * (dp[i + 1] + dp[max(i - 1, G)]);
      dp[i] %= mod; 
    }
  }
    
  // If weight is at G already, it took 0 days else calculate and return steps inversely.
  long long ans = W >= G ? 0 : dp[G];
  return ans; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long W, G, L;
    cin >> W >> G >> L;
    long long ans = expectedSteps(W, G, L);
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
