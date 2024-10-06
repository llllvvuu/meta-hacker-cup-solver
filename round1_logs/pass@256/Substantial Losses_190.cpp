
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

ll pow_mod(ll b, ll p) {
    if(p == 1) return b;
    ll half = pow_mod(b, p / 2);
    half = half * half % MOD;
    return (p & 1 ? b * half % MOD : half);
}

ll modinv(ll a) {
    return pow_mod(a, MOD-2);
}

ll solve(int W, int G, int L) {
    ll diff = W - G;
    ll n = (W - G) + L + G; //+ L adjustments for safety
    ll inv2 = modinv(2), e[n + 1];
    e[G] = 0;
    for (ll i = G + 1; i <= W + L; ++i) {
        e[i] = (1 + e[i - 1] + e[max(i + 1, W + L)]) * inv2 % MOD;
        if (i <= W && i + L <= W + L) e[i] = (e[i] * L + 1 + L) * inv2 % MOD;
    }
    ll cand1 = e[W];
    ll denomination = diff * inv2 % MOD;
    for (ll i = W + 1; i <= W + L; ++i) {
        ll bottom = 1 + diff - (i - W - 1) + e[i];
        ll mul = diff - (i - W - 1);
        ll ans = bottom * mul % MOD;
        cand1 = (cand1 * bottom + ans * modinv(denomination)) % MOD;
        denom = 2 * denomination;
    }
    return cand1 * modinv(denomination) % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L) << endl;
    }
    return 0;
}
