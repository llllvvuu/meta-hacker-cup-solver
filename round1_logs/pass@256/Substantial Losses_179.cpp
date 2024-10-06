
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
typedef long long ll;

const ll MOD = 998244353;
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
}

ll inv(ll a) {
    ll x, y;
    extgcd(a, MOD, x, y);
    return (x + MOD) % MOD;
}

ll dp[100100]; // In practice, roughly the max of C, L+1, W-G

ll simulate(int w, int g, int l) {
    dp[g] = 0;
    for (int i = g + 1; i <= w; ++i) {
        dp[i] = dp[i - 1] + 1;
        ll p = i + 1, nx = p;
        while (nx < i + l && nx <= w) {
            dp[i] = (dp[i] * p + dp[nx]) % MOD;
            nx++;
            p++;
        }
        dp[i] = (dp[i] * inv(p) + MOD) % MOD;
    }
    return dp[w];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << simulate(W, G, L) << endl;
    }
    return 0;
}
