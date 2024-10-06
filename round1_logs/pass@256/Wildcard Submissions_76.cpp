
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
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353; 

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) 
    {
        int N;
        cin >> N;
        vector<string> patterns(N);
        for (int j = 0; j < N; j++) cin >> patterns[j];
        
        int mxLen = 0;
        for (auto &str : patterns) mxLen = max(mxLen, (int)str.size());

        vector<vector<vector<long long>>> dp(mxLen + 1, vector<vector<long long>>(3, vector<long long>(3, 0)));
        
        dp[0][0][0] = 1; 
        for (auto &str : patterns) 
        {
            for (int len = 0; len < str.size(); ++len) 
            { 
                dp[len + 1][0][0] += dp[len][0][0]; 
                dp[len + 1][1][0] += dp[len][0][1] * (str[len] != '?'); 
                dp[len + 1][1][0] += dp[len][0][2];
                dp[len + 1][1][0] += (dp[len][0][0] + dp[len][0][1] + dp[len][0][2]) * (str[len] == '?' && len < str.size() - 1);
            }
        }
        
        long long ans = 0;
        for (auto &str : patterns) ans += (dp[str.size()][1][0]) % MOD, ans %= MOD;
        cout << "Case #" << i << ": " << ans << "\n";
    }
    return 0;
}
