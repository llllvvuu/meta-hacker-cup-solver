
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353; 

ll dp[10001];
ll inv[10001];

ll modpow(ll a, ll p) {
    if (p == 0) return 1;
    if (p % 2 == 1) {
        return (a * modpow(a, p - 1)) % MOD;
    } else {
        ll subp = p / 2;
        ll part = modpow(a, subp);
        return (part * part) % MOD;
    }
}

ll modInv(ll a) {
    return modpow(a, MOD - 2);
}

ll calculate(ll w, ll g, ll l) {
    if (w <= g || dp[w] > -1) return dp[w];
    ll ans;
    if (w + l > g) {
        ans = (g - w + calculate(w + 1, g, l) + calculate(w - 1, g, l)) / 2;
    } else {
        ans = (l + calculate(w + 1, g, l) + calculate(w - 1, g, l)) / 2;
    }
    dp[w] = ans;
    return ans;
}

int main() {
    ll T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        fill(dp, dp + max(W + 1, G + 1), -1);
        dp[G] = 0;
        ll ans = calculate(W, G, L);
        cout << "Case #" << t << ": " << (ans * modInv(2)) % MOD << "\n";
    }
    return 0;
}
