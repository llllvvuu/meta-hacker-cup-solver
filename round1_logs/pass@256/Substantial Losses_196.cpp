
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

int64_t inv(int64_t a, int64_t m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

int64_t moduloMul(int64_t x, int64_t y, int64_t mod) {
    int64_t result = 0;
    x %= mod;
    while (y > 0)
    {
        if (y & 1)
            result = (result + x) % mod;
        x = (2 * x) % mod;
        y >>= 1;
    }
    return result % mod;
}

int64_t moduloExp(int64_t x, int64_t y, int64_t mod) {
    int64_t res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = moduloMul(res, x, mod);
        y >>= 1;
        x = moduloMul(x, x, mod);
    }
    return res;
}

int main() {
    int64_t MOD = 998244353;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int64_t W, G, L, x, target, max_weight, days, tmp, result = 0;
        cin >> W >> G >> L;
        x = W - G;

        if (G >= L + W) {
            target = x;
        } else {
            max_weight = min(W, L + W);
            target = x - (L - (max_weight - G));
            days = inv(2, MOD);
            tmp = inv(1 - days, MOD);
            result = moduloMul(tmp - 1, moduloExp(days, target, MOD), MOD);
        }

        cout << "Case #" << t << ": " << moduloMul(result + target, tmp, MOD) << endl;
    }
}
