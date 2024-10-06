
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
const int MAX_LENGTH = 105;
const int MAX_N = 25;

int dp[MAX_LENGTH + 1][1 << MAX_N]; // dp[len][mask] = number of ways to have a prefix of length `len` with node status given by `mask`
int n, m;
string s[MAX_N];

int mask_to_hamming(int mask) {
    int count = 0;
    while (mask > 0) {
        count += mask % 2;
        mask /= 2;
    }
    return count;
}

void solve() {
    cin >> n; m = 0;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int last = 0;
        
        for (char c : s[i]) {
            ++m;
            if (c == '?') {
                last = m;
            }
            int mask = 0;
            
            for (int j = 0; j < n; ++j) {
                if (s[j].substr(0, m) == s[i].substr(0, m)) {
                    mask |= 1 << j;
                }
            }
            
            for (int len = 0; len < last; ++len) {
                for (int prev_mask = 0; prev_mask < 1 << n; ++prev_mask) {
                    dp[len + 1][prev_mask | mask] += dp[len][prev_mask];
                    if (dp[len + 1][prev_mask | mask] >= MOD) {
                        dp[len + 1][prev_mask | mask] -= MOD;
                    }
                }
            }
        }
    }
    
    int result = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
        result += mask_to_hamming(mask);
        if (result >= MOD) result -= MOD;
    }
    for (int len = m + 1; len <= 100; ++len) {
        for (int mask = 0; mask < 1 << n; ++mask) {
            result += dp[len][mask];
            if (result >= MOD) result -= MOD;
        }
    }
    
    cout << "Case #" << ++n_case << ": " << result << endl;
}
