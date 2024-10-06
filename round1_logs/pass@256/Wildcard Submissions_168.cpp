
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
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> pow2(27, 0);
    pow2[0] = 1;
    for (int i = 1; i < 27; i++) {
      pow2[i] = (pow2[i - 1] << 1) % MOD;
    }
    vector<long long> dp(1 << 26, 0);
    dp[0] = 1;
    for (int case_id = 0; case_id < N; case_id++) {
      string s;
      cin >> s;
      vector<int> require(26, 0);
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?') {
          continue;
        } else {
          require[s[i] - 'A'] = 1;
        }
      }
      vector<long long> ndp(1 << 26, 0);
      for (int mask = 0; mask < (1 << 26); mask++) {
        if (dp[mask] == 0) {
          continue;
        }
        int add = 0;
        for (int i = 0; i < 26; i++) {
          if (require[i] && mask & 1 << i) {
            add = (add + pow2[i]) % MOD;
          }
        }
        for (int i = 0; i < 26; i++) {
          if (require[i]) {
            int new_mask = mask | 1 << i;
            ndp[new_mask] = (ndp[new_mask] + dp[mask]) % MOD;
          }
        }
        ndp[mask] = (ndp[mask] + add) % MOD;
      }
      dp = ndp;
    }
    
    long long sol = 0;
    for (int i = 0; i < (1 << 26); i++) {
      sol += dp[i];
      sol %= MOD;
    }

    cout << "Case #" << t << ": " << sol << "\n";
  }
  return 0;
}
