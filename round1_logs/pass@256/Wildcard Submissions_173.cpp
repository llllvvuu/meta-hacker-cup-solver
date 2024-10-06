
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

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        vector<vector<int>> dp(S[0].size() + 1, vector<int>(26, 0));
        vector<int> count(26, 0);
        
        // Initialize DP table
        int current_mask = 0;
        for (char ch : S[0]) {
            if (ch == '?') {
                current_mask |= (1 << 26);
            } else {
                count[ch - 'A'] = 1;
            }
        }
        dp[0] = count;
        
        for (int i = 1; i < S[0].size(); i++) {
            for (char ch = 'A'; ch <= 'Z'; ch++) {
                int new_mask = current_mask;
                if (S[0][i] == '?') {
                    new_mask |= (1 << 26);
                } else {
                    new_mask &= ~(1 << (ch - 'A'));
                }
                for (char ch2 = 'A'; ch2 <= 'Z'; ch2++) {
                    dp[i][ch - 'A'] += dp[i - 1][ch2 - 'A'] * (new_mask >> (ch2 - 'A') & 1 ? 1 : 0);
                    dp[i][ch - 'A'] %= MOD;
                }
            }
        }

        int ans = dp[S[0].size() - 1][0];
        for (int i = 1; i < 26; i++) {
            ans += dp[S[0].size() - 1][i];
            ans %= MOD;
        }
        cout << "Case #" << t << ": " << ans + 1 << endl;  // Adding 1 for the root node
    }
    return 0;
}
