
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

const int MOD = 998244353;

int64_t modpow(int64_t a, int64_t b)
{
    int64_t result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int64_t W, G, L;
        cin >> W >> G >> L;
        if (W == G)
        {
            cout << "Case #" << t << ": " << 0 << "\n";
            continue;
        }
        if (L == 0)
        {
            cout << "Case #" << t << ": " << (W - G) % MOD << "\n";
            continue;
        }
        vector<int64_t> dp(W + 1), pow(W + 1);
        pow[0] = 1;
        dp[W] = 0;
        for (int w = W - 1; w >= G - 1; w--)
        {
            int64_t high = max(G, min((int64_t)w + L, W - 1));
            int p = pow[high - w];
            dp[w] = (2LL * (w + 1LL) * p - dp[high] + MOD - dp[w + 1]) % MOD;
            pow[w] = (2 * pow[w + 1] - pow[high + 1]) % MOD;
            if (dp[w] < 0) dp[w] += MOD;
        }
        cout << "Case #" << t << ": " << dp[G] * modpow(pow[G], MOD - 2) % MOD << "\n";
    }
    return 0;
}
