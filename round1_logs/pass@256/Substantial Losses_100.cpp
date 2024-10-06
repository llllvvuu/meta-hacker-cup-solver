
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
#include <unordered_map>
using namespace std;

const int MOD = 998244353;
long long W, G, L;

// Compute the modular multiplicative inverse using Fermat's Little Theorem
long long inv(long long a) {
    return power(a, MOD-2, MOD);
}

// Fast modular exponentiation
long long power(long long a, long long b, long long c) {
    long long res = 1;
    a = a % c;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % c;
        b = b >> 1;
        a = (a * a) % c;
    }
    return res;
}

long long solve(long long x, unordered_map<long long, long long> &memo) {
    if (x <= G) return 0;
    if (memo[x] != -1) return memo[x];
    long long extra_moves = min(max(x - G, G + L - G), x - G);
    long long res = 1 + (x - G - extra_moves + 1) +
                    ((inv(2)) * (solve(x-1, memo) + solve(min(x + L - G, x - 1), memo))) % MOD;
    memo[x] = res % MOD;
    return memo[x];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> W >> G >> L;
        unordered_map<long long, long long> memo;
        for (int i = 0; i < 100100; i++) memo[i] = -1;
        memo[0] = 0; memo[G] = 0;
        long long ans = solve(W, memo);
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
