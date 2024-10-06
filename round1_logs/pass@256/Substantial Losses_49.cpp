
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

ll G, W, L, memo[100100];

ll modInverse(ll a, ll m) {
    ll x = 1, y = m - 2, p = 1;
    while(y > 0) {
        if (y % 2) p = p * a % m;
        x = x * x % m;
        y /= 2;
        a = a * a % m;
    }
    return p;
}

ll process(ll i) {
    if (memo[i] != -1) return memo[i];
    if (i <= G) return memo[i] = 0;
    if (G > i - L) return memo[i] = 1 + ((process(i - 1) * 2 + 1) % MOD * modInverse(3, MOD) % MOD);
    return memo[i] = (1 + (process(i - 1) * 2 + process(i + 1)) % MOD * modInverse(3, MOD) % MOD) % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> W >> G >> L;
        memo[0] = 1;
        memset(memo + 1, -1, 10010 * (sizeof(memo[0])));
        
        ll ans = ((-process(W) + 2 * (G - W - L)) % MOD * (-modInverse(L + 1, MOD))) % MOD;
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
