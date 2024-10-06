
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

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

long long mod_inverse(long long x) {
    return power(x, MOD - 2);
}

long long solve(long long w, long long g, long long l) {
    if (w - g <= l) return w - g;

    long long n = w - g, A = (n + l - 1) * 2;
    long long d = 1, B = mod_inverse(A - 2 * (1 + l)) * d;

    return (A * w + B - A * g) * mod_inverse(A) % MOD;
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
