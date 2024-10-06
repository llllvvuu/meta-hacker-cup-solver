
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
#include <cassert>
#include <iostream>
using namespace std;

const int MOD = 998244353;

long long expmod(long long x, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD; 
        n >>= 1;
    }
    return res;
}

long long modinv(long long x) {
    return expmod(x, MOD - 2);
}

long long solve(long long W, long long G, long long L) {
    const long long N = 3000;
    long long dp[N];
    dp[0] = 0;
    
    for (long long x = 1; x < N; x++) {
        dp[x] = (dp[x - 1] * 4 % MOD + MOD + 1 - (L >= x ? (dp[L - (long long)x] * 2 + 1) : 0)) % MOD;
    }

    return (dp[W - G + L - 1] * modinv(2) % MOD) * 2 % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long res = solve(W, G, L);
        printf("Case #%d: %lld\n", t, res);
    }
    return 0;
}
