
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
#include <algorithm> 
#include <bitset>  
#include <iostream> 
using namespace std; 

const int BASE = 26;
const int MOD = 998244353;

int N;
vector<string> S;

bitset<105> dp[1 << 26];

void dfs(int i, int j, int bit, bool f) {
    while (i < S[j].size() && (S[j][i] == '?' || (bit >> (S[j][i] - 'A')) & 1))
        ++i;
    
    if (i == S[j].size()) {
        if (f) dp[bit][__builtin_popcount(bit)] = 1;
        return;
    }

    int piv = bit | (1 << (S[j][i] - 'A'));
    if (dp[piv][__builtin_popcount(bit)]) return;
    dp[piv][__builtin_popcount(bit)] = 1;
    
    dfs(i + 1, j, piv, f);
    
    if (f) dfs(i, j, bit, 1);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N, S.clear();
        S.resize(N);
        for (auto &s : S) cin >> s;

        fill(dp[0].begin(), dp[0].end(), 0);
        dp[0][0] = 1;
        dfs(0, 0, 0, 0);
        
        int64_t ans = dp[0][0];
        
        for (int i = 0; i < N; ++i) dfs(0, i, 0, 1);
        
        for (int len = 1; len < 101; ++len)
            for (int bit = 0; bit < (1 << BASE); ++bit)
                if (dp[bit][len])
                    for (int s = 1; s < (1 << BASE); ++s)
                        if (s & bit)
                            (ans += dp[s][len]) %= MOD;
        
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}
