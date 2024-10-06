
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
using ll = long long;

const int MOD = 998244353;
ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
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

ll dp[90][20010];
int main() {
    int TT;
    cin >> TT;
    for (int tc = 1; tc <= TT; tc++) {
        ll W, G, L;
        cin >> W >> G >> L;
        for (int i = 0; i <= 2*L; i++)
            dp[0][i] = 1;
        for (int d = 1; d <= L+1; d++) {
            for (int w = 0; w <= 2*L; w++) {
                dp[d][w] = 0;
                if (w > 0) dp[d][w] = (dp[d][w] + dp[d-1][w-1]) % MOD;
                if (w < 2*L) dp[d][w] = (dp[d][w] + dp[d-1][w+1]) % MOD;
            }
        }
        ll days = 0;
        ll sum = 0;
        for (int d = 0; d <= L+1; d++) {
            ll curr = modInverse(nCr(d + W - G, W - G), MOD);
            days += (d * curr) % MOD;
            sum += curr;
            days %= MOD;
            sum %= MOD;
        }
        cout << "Case #" << tc << ": " << (days * modInverse(sum, MOD)) % MOD << "\n";
    }
    return 0;
}
