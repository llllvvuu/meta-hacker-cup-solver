
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
const int ALPH = 26;

void add(int &x, int y) { x = (x + y) % MOD; }

int dp[27][1 << ALPH];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        vector<string> S(N);
        for(auto &s : S) {
            cin >> s;
        }

        int len = max_element(S.begin(), S.end()) - min_element(S.begin(), S.end()) + 1;
        for(int i = 0; i < N; i++) S[i] += string(len - S[i].size(), '?'); 

        for(int i = 0; i < N; i++) {
            int mask = 0;
            dp[0][mask] = 1;
            for(int j = 0; j < len; j++) mask = (mask << 1) + (S[i][j] == '?');
            for(int j = 1; j <= len; j++) dp[j][mask] += 1; // Initialize each S_i with its mask

            vector<int> next(1 << ALPH); 
            for(int j = 0; j < (1 << ALPH); j++) next[j] = 6001; // Inf

            int msk = mask;
            for(int j = len - 1; j >= 0; j--) {
                int bit_mask = S[i][j] == '?' ? (1 << ALPH) - 1 : 1 << (S[i][j] - 'A');
                msk = (msk << 1) | (S[i][j] == '?');
                for(int k = 0; k < (1 << ALPH); k++)
                    if((k & bit_mask) != 0) 
                        add(next[k & msk], dp[j][k]); // Transition from dp[j][k] to dp[j+1][msk]
                for(int k = 0; k < (1 << ALPH); k++)
                    dp[j+1][k & msk] = next[k & msk]; // Store transition results

                fill(next.begin(), next.end(), 6001); // Reset to infinity
            }
        }

        long long ans = 0;
        for(int i = 0; i < (1 << ALPH); i++)
            for(int j = 1; j <= len; j++)
                add(ans, dp[j][i]);

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
