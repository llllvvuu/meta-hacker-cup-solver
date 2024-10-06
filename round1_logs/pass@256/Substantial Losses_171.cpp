
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

int solve(long long W, long long G, long long L) {
    if (G <= W - L) { // Constrained case prevention
        return (W - G) % MOD;
    }

    long long commonRatio = 2, denominator = W - G, expectedDays = 0;
    for (long long i = 0; i <= W - G; i++) {
        expectedDays += commonRatio * i;
        expectedDays %= MOD;
        commonRatio = (2 * commonRatio) % MOD;
        denominator = (denominator * (2 - (i >= L ? 1 : 0))) % MOD;
    }
    return (expectedDays * pow_mod(denominator, MOD - 2)) % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L) << endl;
    }
    return 0;
}
