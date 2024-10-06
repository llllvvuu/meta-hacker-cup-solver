
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

const int MOD = 998244353;

long long inverse(long long a) {
    long long x = a, y = MOD, p = 1, q = 0;
    while (x) {
        long long t = y / x;
        y -= t * x;
        swap(x, y);
        p -= t * q;
        swap(p, q);
    }
    if (p < 0) p += MOD;
    return p;
}

long long solve(long long W, long long G, long long L) {
    if (W - L - 1 <= G) return (W - G) % MOD;  // L is small
    if (W == G + 1) return inverse(2) % MOD;   // L is infinite
    long long diff = W - G;
    if (L >= diff) return diff % MOD;

    long long dp[2100] = {0}; // Only 2100 entries are required since diff is large enough for other terms

    for(long long i = diff-1; i >= G; i--) {
        dp[i] = (dp[i+1] + dp[max(0LL, min(i+L, diff-1))]) % MOD;
        dp[i] = (((dp[i] * 2) % MOD) + 1) % MOD;
    }
    return (dp[G] * inverse(2)) % MOD;    
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": ";
        cout << solve(W, G, L) << endl;
    }
    return 0;
}
