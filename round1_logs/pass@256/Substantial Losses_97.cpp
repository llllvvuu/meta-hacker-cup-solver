
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

const long long MOD = 998244353;

long long modInverse(long long a) {
    long long m = MOD;
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

long long solve(long long W, long long G, long long L) {
    if (W - G > L) {
        long long a = W - G;
        long long b = 4 * a;
        b %= MOD;
        return b;
    } else {
        return (W - G) * modInverse(2 * (W - G - L)) % MOD;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        long long W, G, L;
        cin >> W >> G >> L;
        cout << solve(W, G, L) << endl;
    }
    return 0;
}
