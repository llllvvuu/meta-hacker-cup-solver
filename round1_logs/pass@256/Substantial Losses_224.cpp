
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

// Precomputation of modular inverses
vector<long long> mod_inv(1000000000);
long long mod_pow(long long a, long long m, long long md) {
    a %= md;
    long long ret = 1;
    while(m) {
        if (m & 1) ret = ret * a % md;
        a = a * a % md;
        m >>= 1;
    }
    return ret;
}
void precompute_inv(int n) {
    for (int i = 1; i < n; i++) {
        mod_inv[i] = mod_pow(i, 998244353 - 2, 998244353);
    }
}

long long expect(long long cur, long long g, long long w, long long l, vector<long long> &dp) {
    if (dp[cur] != -1) return dp[cur];
    if (cur == g || cur >= w) return dp[cur] = 0;
    if (cur >= w - 1) return dp[cur] = w - cur;
    return dp[cur] = (2 * (1 + (cur == w - 1 ? 0 : expect(cur + 1, g, w, l, dp)) + expect(cur + l, g, w, l, dp)) % 998244353 * mod_inv[2] % 998244353) - 1;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int T;
    cin >> T;
    precompute_inv(1000000000);
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        long long w, g, l;
        cin >> w >> g >> l;
        vector<long long> dp(w + l + 1, -1);
        cout << expect(g, g, w, l, dp) << endl;
    }
    return 0;
}
