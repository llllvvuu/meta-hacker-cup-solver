
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

const int MOD = 998244353;

// Modular inverse using binary exponentiation
long long modInverse(long long a, long long m = MOD) {
  long long m0 = m, t, q;
  long long x0 = 0, x1 = 1;

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

long long solve(long long W, long long G, long long L) {
    long long expected_days = (L == 0) ? (W - G) : 2 * (W - G);
    expected_days %= MOD;
    return expected_days * modInverse(2ll);
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
