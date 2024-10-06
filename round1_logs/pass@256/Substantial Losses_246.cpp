
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
#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MOD = 998244353;
vector<ll> memo(1e18 + 1, -1);
vector<ll> inverse(1e18 + 1);

ll D(ll w) {
    if (w <= 0) return 0;
    if (memo[w] != -1) return memo[w];
    return memo[w] = (1 + D(w - 1)) % MOD;
}

ll E(ll w, ll G, ll L) {
    if (w <= G) return 0;
    if (memo[w] != -1) return memo[w];
    if (w > G + L) return memo[w] = (1 + (E(w - 1, G, L) + E(w + 1, G, L)) / 2) % MOD;
    return memo[w] = 1 + D(w - G);
}

ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll r) {
    if (!inverse[r]) inverse[r] = modpow(r, MOD - 2, MOD);
    return inverse[r];
}

int main() {
    int T;
    cin >> T;
    inverse[1] = 1;
    for (int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": ";
        cout << (E(W, G, L) * modinv(2)) % MOD << endl;
    }
    return 0;
}
