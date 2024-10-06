
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

typedef long long int ll;

const ll INF = 1e18;
const ll MOD = 998244353;
const ll INV2MOD = 499122177; // because 2 * 499122177 == 998244354 == 1 (mod 998244353)

ll W, G, L, t, ans;
ll dp[(int)1e6 + 1];

// Calculate modular inverse using Extended Euclidean algorithm
ll inv_mod(ll a, ll m) {
    ll g = m, r = a, x = 0, y = 1;
    while (r != 0) {
        ll quotient = g / r;
        ll tmp = r;
        r = g % r;
        g = tmp;
        tmp = x;
        x = y - quotient * x;
        y = tmp;
    }
    if (x < 0) x += m;
    return x;
}

ll solve(ll w) {
    if (w <= G) return 0; // base case
    if (dp[w] != -1) return dp[w]; // return stored value in dp array if already computed
    // recursive call to compute expected days for weights w ± 1
    dp[w] = 1 + (solve(max(G, w - 1)) + solve(min(w + L, w + 1))) * INV2MOD;
    dp[w] %= MOD;
    return dp[w];
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> W >> G >> L;
        ans = 0;
        for (ll j = G + 1; j <= min(W, G + L); j++) {
            fill(dp + G + 1, dp + j + 1, -1); // initialize dp to -1
            ans = (ans + solve(j)) % MOD;
        }
        ans = ans * inv_mod(W - G, MOD);
        ans %= MOD;
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
