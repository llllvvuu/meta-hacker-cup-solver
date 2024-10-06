
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
#include <numeric>
using namespace std;

long long mod = 998244353;
long long powered(long long base, long long exp) {
  if (exp == 0) return 1;
  long long res = powered(base * base % mod, exp / 2);
  return res * (exp % 2 ? base : 1) % mod;
}

long long solve(long long W, long long G, long long L) {
  if (L == 0) return (W - G) % mod;
  long long E = min(W, G + L);
  long long res = 0;
  for (long long e = G; e <= min(E, 2 * G); e++)
    res = (res + powered(2LL, e - G + min(E - e, e - G) + 1)) % mod;
  return powered(2LL, G + min(W - E, E - G) + 1) * powered(2, mod - 2) % mod * res % mod;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long W, G, L;
    cin >> W >> G >> L;
    assert(G < W);
    cout << "Case #" << t << ": " << solve(W, G, L) << endl;
  }
  return 0;
}
