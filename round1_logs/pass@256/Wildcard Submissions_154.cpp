
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
const int MOD = 998244353;
const int MXL = 101;

// DP on subsequences based prefix-derived patterns
int dp[1 << 25][MXL], mark[1 << 25];

// Evaluating node addition for extensions
long long modpow(long long a, long long b) {
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    long long m = modpow(a, b / 2);
    return (m * m % MOD) * modpow(a, b % 2) % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for (int j = 0; j < N; j++)
            cin >> S[j];
        int masks[1 << 25];
        for (int j = 0; j < (1 << N); j++) masks[j] = 0;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < S[j].size(); k++)
                if (S[j][k] == '?' && (!(masks[j] & (1 << k)))) {
                    masks[j] |= 1 << k;
                    int mask = masks[j];
                    long long len = S[j].size() - k;

                    // Default value counts nodes with no wildcard extensions
                    dp[mask][len] = 1 % MOD;
                    dp[mask][len] = (dp[mask][len] + MOD - dp[0][len - 1]) % MOD;

                    // Exploring all possible node extensions via wildcards
                    for (int color = 1; color < (1 << N); color++) 
                        if ((color & mask) == mask)
                            for (int l = 1; l <= len; l++)
                                dp[mask][len] = (dp[mask][len] + dp[color ^ mask][l - 1]) % MOD;
                }
        }

        // Calculating total node count under restrictions
        long long ans = 0;
        for (int mask = 1; mask < (1 << N); mask++) {
            int len = S[mask].size();
            ans = (ans + (dp[mask][len] - dp[mask ^ 1][len]) * modpow(26, len - 1 % MOD)) % MOD;
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
