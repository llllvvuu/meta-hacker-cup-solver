
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
#include <algorithm>

using namespace std;

long long modInverse(long long n);
long long modMultiply(long long x, long long y, long long mod);

long long modInverse(long long n) {
    long long MOD = 998244353;
    n %= MOD;
    return modMultiply(n, modPow(n, MOD - 2, MOD), MOD);
}

long long modMultiply(long long x, long long y, long long mod) {
    return (x * y) % mod;
}

long long modPow(long long x, long long y, long long mod) {
    x %= mod;
    long long result = 1;
    while (y > 0) {
        if (y & 1) result = result * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long mod = 998244353;
        if (L == 0) {
            long long res = (W - G);
            cout << "Case #" << t << ": " << modMultiply(res, modInverse(2), mod) << endl;
        } else {
            long long res = (W - G) + (L / 2);
            res *= modInverse(2);
            cout << "Case #" << t << ": " << modMultiply(res, modInverse(2), mod) << endl;
        }
    }
    return 0;
}
