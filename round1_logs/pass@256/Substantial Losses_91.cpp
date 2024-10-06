
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
#include <cmath>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        
        long long w, g, l;
        cin >> w >> g >> l;
        long long W = w + l; int max_steps = 0;
        
        vector<long long> dp(W - g + 2, 0);
        
        // Set initial conditions for goal weight and just beyond
        dp[1] = 0; 
        if (g + 1 <= W) dp[2] = 1;  // W = G+1
        else max_steps = 1; // Ensure we do not exceed W+L
        
        // Solve for remaining weights
        for (int i = 3; i <= W - g + 1; ++i) {
            dp[i] = 1;
            if (i == W - g + 1 || max_steps < i-2) {
                dp[i] += dp[i-1]; // Adjust for over-limit condition or remaining steps constraint
            } else { 
                dp[i] += (dp[i-1] + dp[i+1]) % MOD; 
                dp[i] = (dp[i] * 2) % MOD;
            }
            dp[i] = (dp[i] + MOD) % MOD;  // maintain positive value
            dp[i] = dp[i] * 265722189;  // multiplicative inverse of 2 in modulo 998244353
            if (i == W - g + 1)
                dp[i] = (dp[i] + max_steps) % MOD;
            else
                dp[i] = (dp[i] - max_steps) % MOD;
        }
        
        cout << dp[W - g + 1] << "\n";
    }
    return 0;
}
