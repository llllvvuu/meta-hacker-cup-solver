
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

// Calculating modular inverse
int inv(int x) {
    return pow(x, MOD - 2);
}

// main method that evaluates the expected days to reach weight G
int solve(int W, int G, int L, int inv_2, int delta) {
    if (delta > L) return (W - G) * inv_2 % MOD; // base case
    int dp[W - G + 1];
    for (int i = W - G; i >= G - delta; --i) {
        dp[i] = i;
        if (2 * i < L + G)
            dp[i] += inv_2 * (dp[i + 1] + 1);
        if (i + 2 >= G)
            dp[i] += -inv_2 * dp[i + 2];
    }
    return dp[G];
}

int main() {
    int T;
    cin >> T;
    int inv_a = inv(2);
    for (int t = 1; t <= T; t++) {
        int W, G, L;
        cin >> W >> G >> L;
        const int delta = (int)max(W - L - G - 1, 0);
        cout << "Case #" << t << ": " << solve(W, G, L, inv_a, delta) % MOD << endl;
    }
    return 0;
}
