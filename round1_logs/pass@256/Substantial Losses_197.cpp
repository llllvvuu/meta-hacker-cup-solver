
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
#include <algorithm>
using namespace std;

const int MOD = 998244353;
const int MAXP = 300001; // this value should be adjusted regarding L when necessary.

vector<pair<long long, long long>> mresult[MAXP];

long long inv(long long q) {
    long long a = q, b = MOD, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        swap(a -= t * b, b);
        swap(u -= t * v, v);
    }
    return u < 0 ? u + MOD : u;
}

long long dp(int x, int remL) {
    // Terminal case where we hit the goal weight.
    if (x == 0) return 0;

    // Terminal case where we exceed limit.
    if (!remL && x > remL + 1) return 0;
    
    // If x reaches W, we reset it to W and reduce the remaining weight limit.
    if (x > remL + 1) return dp(remL + 1, remL - (remL + 1 - x));

    auto &ref = mresult[x];
    // If the result is not yet computed, calculate it
    if (ref[remL].second == 0) {
        ref[remL] = { 1 + (dp(x - 1, remL) + dp(min(x + 1, remL + 1), (x == remL + 1 ? 0 : min(remL - 1, remL + 1 - x - 1)))) / 2, 0 };
        ref[remL].second = ref[remL].first;
    }
    // Return the memoized value
    return ref[remL].first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int T; cin >> T; ) {
        long long W, G, L;
        cin >> W >> G >> L;
        int lim = min((W - G) * 2, MAXP - 1);
        
        for (int x = 0; x < MAXP; x++) {
            for (int remL = 0; remL <= lim; ++remL)
                mresult[x][remL] = { 0, 0 };
        }
        
        long long res = dp(W - G, L);
        cout << "Case #" << T << ": " << res * inv(2LL) % MOD << endl;
    }
    return 0;
}
