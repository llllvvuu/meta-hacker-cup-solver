
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
#include <unordered_map>

using namespace std;

const long long MOD = 998244353;

long long inv(long long a, long long mod) {
    long long res = 1, b = a;
    while (mod != 1) {
        if (mod % 2 == 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        mod /= 2;
    }
    return res;
}

long long dp[100010], L, W, G;

long long solve(long long w, long long peak) {
    if (w <= G) return 0;
    if (peak - L == w) return (w - G) * (w - G);
    if (dp[w - G]) return dp[w - G];
    long long a = (solve(w - 1, peak) + 1);
    if (w + 1 <= peak) a = (a + solve(w + 1, w + L)) % MOD;
    return dp[w - G] = inv(2, MOD) * a % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long T;
    cin >> T;

    for (long long t = 1; t <= T; t++) {
        cin >> W >> G >> L;
        cout << "Case #" << t << ": ";
        cout << solve(W, W) << endl;
    }
    return 0;
}
