
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

long long modPow(long long a, long long exp, long long mod) {
  long long ret = 1;
  while (exp) {
    if (exp % 2) ret = ret * a % mod;
    a = a * a % mod;
    exp /= 2;
  }
  return ret;
}

long long solve(long long W, long long G, long long L) {
  long long d = W - G;
  long long res = (d * 2) % MOD;
  long long modInverses[d + L];
  modInverses[0] = 1;
  for (int i = 1; i <= d + L; i++) {
    modInverses[i] = modInverses[i - 1] * 2 % MOD;
    modInverses[i] = modPow(modInverses[i], MOD - 2, MOD);
  }
  if (d <= L) {
    for (int i = G + 1; i <= G + d; i++) {
      res += modInverses[W - i] - modInverses[i - G];
      res %= MOD;
    }
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    long long W, G, L;
    cin >> W >> G >> L;
    cout << "Case #" << i << ": " << solve(W, G, L) << endl;
  }
  return 0;
}
