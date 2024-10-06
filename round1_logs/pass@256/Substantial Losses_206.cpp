
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

// Function and values to solve modular inverse as per contest constraints
const long long MOD = 998244353;
long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}
long long mod_inverse(long long num) {
    return mod_pow(num, MOD - 2, MOD);
}

long long solve(long long w, long long g, long long l) {
    if (w < g || l == 0) return -1;
    long long x = min(w - g, l), tx = x + 1;
    long long c = 2 * ((tx * tx - 1) % MOD) * mod_inverse(2 * (tx * (tx + 1) % MOD) - tx * tx - x * x - 1) % MOD;
    long long d = 2 * tx * c % MOD - 2;
    return ((w - g) * c % MOD + d) % MOD;
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
