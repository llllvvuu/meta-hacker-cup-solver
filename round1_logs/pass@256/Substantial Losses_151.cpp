
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

long long inverse(long long a, long long p) {
  long long m = p, y = 0, x = 1;
  if (p == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;

    m = a % m;
    a = t;
    t = y;

    y = x - q * y;
    x = t;
  }
  if (x < 0) x += p;
  return x;
}

long long solve(long long W, long long G, long long L, long long p) {
  if (L == 0) return (W - G) % p;
  if (W - L <= G) return (W - G) % p;

  long long left = G - 1;
  long long right = min(G + L, W);
  long long p1 = 1;
  long long q1 = 0;
  long long p2 = 1;
  long long q2 = G - W;
  while (left <= right) {
    long long d = right - left + 1;
    long long d2 = d;
    if (d > 1) d2 = (d * (d - 1)) / 2;
    long long t1 = (left - G) * p1;
    long long t2 = (right - G) * p2;
    long long numerator = (t2 - t1 + d) % p;
    long long denominator = (2 * (right - left + 1)) % p;
    long long result = (numerator * inverse(denominator, p)) % p;

    left += d;
    right -= d;
    p1 += q1;
    p2 += q2;
    if (q1 > 0) {
      q1 >>= 1;
      p1 >>= 1;
    }
    q2 += d2;
  }
  long long dp = (right - G + 1) * p2;
  dp %= p;
  long long dq = 1;
  int d = 2 * (right - G + 1);
  while (dp > 0)
    if (dp % 2 == 0) {
      dp /= 2;
      dq *= 2;
    } else {
      dp -= 1;
    }
  return (dp * inverse(dq, p)) % p;
}

int main() {
  int T;
  cin >> T;
  long long p = 998244353;
  for (int t = 1; t <= T; t++) {
    long long W, G, L;
    cin >> W >> G >> L;
    cout << "Case #" << t << ": " << solve(W, G, L, p) << '\n';
  }
  return 0;
}
