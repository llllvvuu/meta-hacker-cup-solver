
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
using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll w, g, l, t;
vector<vector<ll>> dp;
ll solve(ll curw) {
    if (curw <= g) return 0;
    if (dp[curw - g].size() == 1) return dp[curw - g][0];
    auto& curx = dp[curw - g][1];
    if (curx != -1) return curx;
    
    ll next = (curw - 1 > g + l ? solve(curw - 1) : 0);
    ll prev = (curw + 1 <= g + l ? solve(curw + 1) : 0);
    
    ll up = (curw + 1 <= g + l ? 1 : 0);
    ll down = (curw - 1 > g ? 0 : 1);
    return dp[curw - g][0] = curx = (next + prev + up + down + MOD - 1) / 2 % MOD * (curw - g + MOD - 1) % MOD + MOD - 1;
}

int main() {
    cin >> t;
    for (ll cas = 1; cas <= t; cas++) {
        cin >> w >> g >> l;
        dp = vector<vector<ll>>(l + 1, vector<ll>(2, -1));
        cout << "Case #" << cas << ": ";
        if (l == 0) {
            ll ans = (w - g);
            ll inv = (MOD - (MOD / ans)) % MOD;
            cout << (ans * inv) % MOD << endl;
        } else {
            ll ans = (1 + (w - g) % MOD * solve(w) % MOD) % MOD;
            cout << ans << endl;
        }
    }
    return 0;
}
