
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> wildcards(N);
        for (auto &w: wildcards) cin >> w;

        vector<int> dp(101, 0);
        dp[0] = 1; // base condition
        for (int l = 1; l <= 100; l++) {
            vector<int> nextDp(l+1, 0);
            for (int w = 0; w < N; w++) {
                string &s = wildcards[w];
                int j = 0;
                for (int i = 0; (j < l) && (i < s.size()); i++) {
                    if (s[i] == '?' || s[i] == s[j]) {
                        nextDp[j+1] = (nextDp[j+1] + dp[j]) % MOD;
                        j++;
                    }
                }
            }
            nextDp.swap(dp);
        }
        long long ans = 0;
        for (auto i: dp) ans += i % MOD; ans %= MOD;

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
