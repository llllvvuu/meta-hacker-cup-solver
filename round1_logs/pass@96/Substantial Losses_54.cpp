
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

constexpr long long MOD = 998244353;

long long add(long long a, long long b) {
    return (a + b) % MOD;
}

long long multiply(long long a, long long b) {
    return a * b % MOD;
}

long long inv_mod(long long a, long long mod) {
    long long res = 1, exp = mod - 2, b = a;
    while (exp > 0) {
        if (exp & 1) res = multiply(res, b);
        b = multiply(b, b);
        exp >>= 1;
    }
    return res;
}

long long solve(long long W, long long G, long long L) {
    if (W == G) return 0;

    long long B = L, E[B + 2];
    fill(E, E + B + 2, 0);
    for (long long i = G + 1; i <= W; ++i) E[i % (B + 2)] = i - G;
    for (long long i = W - 1; i >= G; --i) {
        E[i % (B + 2)] = add(1, multiply(inv_mod(2, MOD), add(E[(i + 1) % (B + 2)], E[(i - 1) % (B + 2)])));
    }
    return E[G % (B + 2)];
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
