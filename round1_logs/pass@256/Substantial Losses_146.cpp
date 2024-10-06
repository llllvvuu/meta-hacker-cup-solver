
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
using vi = vector<ll>;
ll MOD = 998244353;

ll modinv(ll a, ll m = MOD) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    return u < 0 ? u + m : u;
}

ll solve(ll now, ll goal) {
    static vi memo;
    if (memo.empty()) memo.resize(goal+2); // initialize memo if empty
    if (memo[now] != -1) return memo[now];
    if (now == goal) return 0; // reached goal
    ll next = now + 2 > goal ? goal : now + 2;
    return memo[now] = (modinv(2) * ((solve(now - 1, goal) % MOD) + (solve(next, goal) % MOD) + 2)) % MOD;
}

int main() {
    int T;
    cin >> T;
    vi memo(1); // we use 0th index otherwise, this can be avoided if we update above if-else
    for (int t = 1; t <= T; t++) {
        ll w, g, l;
        cin >> w >> g >> l;
        cout << "Case #" << t << ": ";
        if (w - l <= g) {
            cout << (w - g) % MOD << "\n";
        } else {
            cout << solve(w, w - l) % MOD << "\n";
        }
        // reset memo for each test case if multiple test cases handled in single instance
        memo.clear(); // reduces peak memory but re-initialize before each call to solve
    }
    return 0;
}
