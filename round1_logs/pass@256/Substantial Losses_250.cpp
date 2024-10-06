
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

long long T, W, G, L, MOD, inv[10000000], F[10000000];

long long binpow(long long b, long long p) {
  if (p == 0) return 1;
  long long res = binpow(b, p / 2);
  res = (res * res) % MOD;
  if (p % 2 == 1) res = (res * b) % MOD;
  return res;
}

long long calc(long long W, long long G, long long L) {
  if(W - G < 0) {
    return 0;
  }
  if(W - G > L) {
    return (W - G) % MOD;
  }
  L = W + L - G;
  return (L - F[L + 1]) % MOD;
}

int main() {
  cin >> T;
  MOD = 998244353;
  inv[1] = F[0] = 1;
  for (int i = 2; i < 10000000; i++) {
    inv[i] = (-MOD / i) * inv[MOD % i] % MOD;
  }
  for (int i = 1; i < 10000000; i++) {
    F[i] = (2 * F[i - 1] + inv[i]) % MOD;
  }
  for (int t = 1; t <= T; t++) {
    cin >> W >> G >> L;
    long long p = (calc(W, G, L) + MOD) % MOD;
    long long q = binpow(2, L + 1);
    long long r = (p * binpow(q, MOD - 2)) % MOD;
    cout << "Case #" << t << ": " << r << endl;
  }
  return 0;
}
