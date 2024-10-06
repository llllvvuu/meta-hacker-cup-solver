
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
const int MOD = 998244353;

// Modular inverse function
int mod_inv(int a, int m) {
  int m0 = m, t, q;
  int x0 = 0, x1 = 1;
  if (m == 1) return 0;
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0) x1 += m0;
  return x1;
}

int solve(long long W, long long G, long long L) {
  if (W <= G + L) return W - G;
  long long max = min(W, G + L);
  long long memo[max + 1];
  memo[max] = 0;
  for (long long i = max - 1; i >= G; i--) {
    memo[i] = (1 + (memo[i + 1] + memo[i + min(i + 1, W)]) % MOD) % MOD;
    if (i + min(i + 1, W) + 1 <= G) memo[i] += memo[i + min(i + 1, W) + 1];
    memo[i] %= MOD;
  }
  long long result = memo[G];
  for (long long i = G; i < max; i++) result = (result + memo[i]) % MOD;
  return result * mod_inv(max - G, MOD) % MOD;
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
