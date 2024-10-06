
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
using namespace std;

long long mod_pow(long long x, long long y, long long mod) {
  long long res = 1; x %= mod;
  while (y) {
    if (y & 1) res = (res * x) % 998244353;
    y >>= 1; x = (x * x) % 998244353;
  }
  return res;
}

long long solve(long long w, long long g, long long l) {
  long long d = (w - g + l) % 998244353;
  long long inv2 = mod_pow(2, -1, 998244353);
  
  if (d <= l + 1) {
    long long dp[d], sum[d+2];
    dp[0] = 0; sum[0] = 0;
    for (int i = 1; i <= d; i++) {
      sum[i] = (sum[i-1] + i) % 998244353;
      dp[i] = (dp[i-1] + 2 * (sum[i] + dp[i-1] + 1) * inv2) % 998244353;
    }
    return dp[d];
  } else {
    return d - (l + 1);
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long W, G, L;
    cin >> W >> G >> L;
    cout << "Case #" << t << ": " << solve(W, G, L) << endl;
  }
  return 0;
}
