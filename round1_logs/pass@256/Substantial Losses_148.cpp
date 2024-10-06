
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

#define MOD 998244353
typedef long long int ll;

ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans*a) % MOD;
        }
        b /= 2;
        a = (a*a) % MOD;
    }
    return ans;
}

ll modinv(ll a) {
    return power(a, MOD-2);
}

ll solve(ll W, ll G, ll L) {
    if (W - G == 0) return 0;
    if (L == 0) return W - G;
    ll diff = W - G;
    ll exp = power(2, W - G - 1);
    ll ans = (exp * diff - diff + MOD) % MOD;
    ans = (ans * modinv(2)) % MOD;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; ++t) {
        ll W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L) << endl;
    }
    return 0;
}
