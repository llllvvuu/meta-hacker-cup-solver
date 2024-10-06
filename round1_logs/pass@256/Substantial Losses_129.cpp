
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
const int MOD = 998244353;

long long mod_inverse(long long a) {
    long long p = MOD;
    long long r = a, t = 1, m = p - 2, u = 0;

    while (m > 0) {
        if (m % 2 == 0) {
            r = ((r%(p)) * (r%(p))) % p;
            m /= 2;
        } else {
            u = ((u) * (t % p)) % p;
            t = ((t % p) * (r % p)) % p;
            r = ((r %(p)) * (a % p)) % p;
            m -= 1;
        }
    }
    t = (t + u) % p;
    return t;
}

long long expected_days(long long W, long long G, long long L) {
    if (W == G)
        return 0;
    if (L == 0)
        return W - G;

    vector<long long> dp(W + 1, -1);
    dp[G] = 0;  // Base case: Expected days from G is 0

    for (int x = G + 1; x <= W; x++) {
        if (x + L > W)
            dp[x] = dp[x - 1] + 1;  // Forced to lose weight if hitting x+L would exceed W
        else
            dp[x] = (1 + (dp[x - 1] + dp[x + 1]) / 2) % MOD;  // Average the possibilities
    }
    long long result = dp[W];
    return result;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long ans = expected_days(W, G, L);
        cout << "Case #" << t << ": " << (ans % MOD) << endl;
    }
    return 0;
}
