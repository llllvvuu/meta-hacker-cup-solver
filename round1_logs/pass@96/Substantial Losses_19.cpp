
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

const long long MOD = 998244353;

long long mod_exp(long long base, long long exp, long long mod) {
  long long res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1) {
      res = (res * base) % mod;
    }
    exp /= 2;
    base = (base * base) % mod;
  }
  return res;
}

long long inv(long long n) {
  return mod_exp(n, MOD - 2, MOD);
}

long long compute_days(long long W, long long G, long long L) {
  long long limit = min(W + L, G + L + 1);
  vector<long long> E(limit - G + 1);
  E[limit - 1] = 1;
  for (int i = limit - 2; i >= G; --i) {
    E[i] = 2 + E[i + 1];
    if (i <= W) {
      if (i + 1 <= limit - 1) 
        E[i] += 2 * E[i + 1];
      if (i + 1 > W || i < W)
        E[i] -= 2 * E[i + 1];
    }
    E[i] /= 2;
    E[i] %= MOD;
  }
  return E[G];
}

int main() {
  long long T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long W, G, L;
    cin >> W >> G >> L;
    long long days = compute_days(W, G, L);
    cout << "Case #" << t << ": " << days * inv(2) % MOD << endl;
  }
  return 0;
}
