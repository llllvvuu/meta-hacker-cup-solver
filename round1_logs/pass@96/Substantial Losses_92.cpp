
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
#include <utility>
using namespace std;

const int mod = 998244353;

int64_t solve(int64_t W, int64_t G, int64_t L) {
    L = min(W - G, L);
    int64_t maxW = W + L;
    int64_t dp[maxW + 1];
    dp[G] = 0;
    for (; W > G; W--) {
        if (W <= G + L) dp[W] = (2 * dp[W - 1] + 1) % mod;
        else dp[W] = (dp[G - 1] - dp[W - 1] + mod) % mod;
    }
    int64_t inv2 = (mod + 1) / 2;
    int64_t result = (dp[W] * inv2) % mod;
    return result;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int64_t W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L) << endl;
    }
    return 0;
}
