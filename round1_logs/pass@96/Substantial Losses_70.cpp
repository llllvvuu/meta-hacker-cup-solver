
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

int mul(int a, int b) {
  return (int)((long long)a * b % MOD);
}

int pow_mod(int a, int b) {
  int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = mul(x, y);
    }
    y = mul(y, y);
    b /= 2;
  }
  return x;
}

int inv(int a) {
  return pow_mod(a, MOD - 2);
}

long long dp[100001]; // precomputed dp for probability scaling

int main() {
  int T;
  cin >> T;
  dp[0] = 0;
  for (int i = 1; i <= 100000; i++) {
    dp[i] = (int)(((long long)i * (2 * dd[1] + 1LL) - 2 * dp[i - 1]) % MOD);
  }
  
  for (int i = 1; i <= T; i++) {
    long long W, G, L;
    cin >> W >> G >> L;
    cout << "Case #" << i << ": ";

    long long wn = max(0LL, W - G - L);
    if (wn <= 100000) {
      cout << dp[(int)wn] * inv(2) % MOD << endl;
    } else {
      long long n = W - G - L - 100000;
      long long res = dp[100000];
      res = mul(res, inv(pow_mod(2, 100000)));
      res = mul(res, inv(pow_mod(2, -n)));
      res = mul(res, (n + 1) * (2 - inv(n + 1)));
      res = mul(res, inv(2));

      cout << res << endl;
    }
  }
  return 0;
}
