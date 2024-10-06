
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
#include <cmath>
#include <iostream>
using namespace std;

const int MOD = 998244353;

long long inverse_mod(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

long long solve(long long G, long long W, long long L) {
    long long n = W - G;
    long long E = (G - L) * (L * 2 + 1);

    if (n - L < 2) {
        E += (n * (n + 1));
    } else {
        long long delta = (n - L) * (n - L - 1) / 2 + (n - L);
        E += G * (n - L - (n - L) / 2);
        E += delta * 2;
        E -= (delta + G) * ((n - L) % 2);
    }
    return inverse_mod(n, MOD) * (E % MOD) % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long G, W, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(G, W, L) << endl;
    }
    return 0;
}
