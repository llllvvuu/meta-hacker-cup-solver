
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
#include <cstring>
using namespace std;

const int MOD = 998244353;

int dp[200][200]; // Dynamic programming table, dimensions are based on practical limits after modulo operations & constraint checks

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long res = 0;
        
        if (W <= G || W + L < G) {
            cout << "Case #" << t << ": -1\n";
        } else if (L == 0) {
            long long diff = W - G;
            res = (diff * diff) % MOD;
        } else {
            memset(dp, 0, sizeof(dp));
            long long n = (min(W, G + L) - max(G, 1)) + 1;
            dp[0][0] = 1;
            // Dynamic programming transitions
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= i; j++) {
                    long long w = max(G, 1) + i, next_states = (w != W) ? (w + 1 != W + L + 1 ? 2 : 1 : 1);
                    dp[i + 1][min(n-1, j + next_states) % n] = (dp[i][j] + dp[i + 1][min(n-1, j + next_states) % n]) % MOD;
                    dp[i][j] = (dp[i][j+1] + dp[i][j]) % MOD;
                }
            }
            // Final result
            res = (dp[n-1][0] - 1 + MOD) % MOD;
            for(int i = 0; i < n; i++) res = (res * 2) % MOD;
            res = (res + 1) % MOD;
            res = res * (int)pow(2, MOD - 2, MOD) % MOD;
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
