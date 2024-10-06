
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
#include <map>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
ll fast_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    long long n, w, g, l;
    cin >> n;
    vector<pair<ll, ll>> queries;

    while (n--) {
        queries.push_back({g - w + 1, l});
        queries.push_back({-g + w - 1, 0});
        cin >> w >> g >> l;
    }

    sort(queries.begin(), queries.end());
    map<ll, ll> last, mx, dp;

    for (const auto &q : queries) {
        ll g = -q.first + w;
        ll l = q.second;

        if (g + l >= w)
            continue;

        last.clear();
        mx[g + w] = g;
        dp[g + w] = 0;
        
        for (int x = g + w - 1; x >= g + l; --x) {
            ll cur = (1 + dp[x + 1] + min(dp[x - 1] + 1, last[x + l] - x + 1)) % MOD;
            cur = (cur * fast_pow(2, MOD - 2)) % MOD;
            dp[x] = (dp[x - 1] + cur) % MOD;
            last[x] = mx[x + 1] = max(mx[x + 1], x + l);
        }
        dp[w] = (dp[w] * fast_pow(g - w + 1 + l, MOD - 2)) % MOD;
        cout << "Case #" << ++idx << ": " << dp[w] << "\n";
    }
    return 0;
}
