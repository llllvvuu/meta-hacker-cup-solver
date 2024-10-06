
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
#include <unordered_map>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

unordered_map<ll, unordered_map<ll, ll>> memo;

ll dp(ll w, ll g, ll l) {
    if (memo.count(w) && memo[w].count(g)) return memo[w][g];
    if (w <= g) return 0;
    if (g + l >= w) return w - g;
    
    ll gain = dp(w + 1, g, l);
    ll lose = (2 * dp(w - 1, g, l) + 1);
    ll sum = (gain + lose) % MOD;
    ll inv = pow(2, MOD - 2, MOD); // Compute the modular inverse of 2
    memo[w][g] = (sum * inv) % MOD;
    return memo[w][g];
}

ll pow_mod(ll a, ll b, ll m) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": ";
        ll ans = dp(W, max(G, W - L), L);
        cout << ans << endl;
    }
    return 0;
}
