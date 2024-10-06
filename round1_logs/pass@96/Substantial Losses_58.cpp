
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
#define MAXW 1000
const long long MOD = 998244353;
long long dp[MAXW];

long long fast_pow(long long x, long long n, long long m) {
    if (n == 0) return 1;
    long long res = fast_pow(x, n / 2, m);
    res = res * res % m;
    if (n % 2 == 1) res = res * x % m;
    return res;
}

long long inv(long long x) {
    return fast_pow(x, MOD-2, MOD);
}

int main() {
    long long T, W, G, L;

    // Edge Case: Can't reach within the limit.
    if (G == W) {
        T = 100; // Providing T directly as an example.
        for (int i = 0; i < T; i++) cout << "Case #" << i + 1 << ": " << -1 << "\n";
        return 0;
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> W >> G >> L;
        long long diff = W - G;

        if (diff <= L) {
            cout << "Case #" << i + 1 << ": " << -1 << "\n";
            continue;
        } else if (diff <= MAXW) {
            long long limit = min(diff, L);
            dp[limit] = (limit * 2 + 1) % MOD;
            for (long long x = limit - 1; x > 0; x--) {
                dp[x] = (dp[x + 1] + dp[x - 1] + 2) * inv(2) % MOD;
            }
            cout << "Case #" << i + 1 << ": " << dp[diff] << "\n";
        } else {
            long long ans = (diff * diff + diff) * inv(2) % MOD * inv(diff - L) % MOD;
            cout << "Case #" << i + 1 << ": " << ans << "\n";
        }
    }

    return 0;
}
