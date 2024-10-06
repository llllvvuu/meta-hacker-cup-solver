
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
#include <string>
#include <algorithm>
using namespace std;

const long long MOD = 998244353;

long long solve(const vector<string>& patterns) {
  vector<long long> dp(101, 0); // how many unique prefixes of each length
  dp[0] = 1;

  for (auto&& pat : patterns) {
    bool any = false;
    vector<long long> dp2(dp);

    for (int l = 0; l < (int)pat.size(); l++) {
      if (pat[l] == '?') any = true;
      else {
        if (l > 0) dp2[l] = (dp2[l - 1] + dp2[l]) % MOD;
        dp[l + 1] = (dp[l + 1] + dp2[l]) % MOD;
      }
    }
    if (!any) dp[pat.size()] = (dp[pat.size()] + 1) % MOD;
  }

  long long res = 0;
  for (int l = 0; l <= 100; l++) res = (res + dp[l] * (l + 1)) % MOD;
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> patterns(N);

    for (int i = 0; i < N; i++) cin >> patterns[i];
    cout << "Case #" << t << ": " << solve(patterns) << "\n";
  }
  return 0;
}
