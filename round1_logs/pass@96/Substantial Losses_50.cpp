
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

// Finds modular inverse using Fermat's little theorem
int modInverse(long long x, long long mod) {
    long long mod0 = mod, t, q;
    long long x0 = 0, x1 = 1;
    if (mod == 1)
      return 0;
    // Use extended Euclid Algorithm to find the inverse
    while (x > 1) {
        q = x / mod;
        t = mod;
        mod = x % mod;
        x = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
      x1 += mod0;
    return x1;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long days = G > W + L ? 0 :
                         G == W ? 0 :
                         W - G > L ? W - G :
                         (W - G + (L - W - 1) *(L - W + 1));
        long long q = 2 * (L - G + 1 + (L - G) % 2);
        long long p = days * q;
        p %= MOD;
        q = modInverse(q, MOD);
        p = (p * q) % MOD;
        cout << "Case #" << i << ": " << p << "\n";
    }
    return 0;
}

