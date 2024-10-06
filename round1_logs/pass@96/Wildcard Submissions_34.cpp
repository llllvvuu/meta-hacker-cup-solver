
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
const int mod = 998244353;

int solve(const string& s) {
    int dp[101], ans = 1;
    dp[0] = 1;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            int dpp[101];
            for (int j = 0; j <= i; j++) {
                dpp[j] = dp[j];
                dp[j] = 0;
            }
            for (int j = 1; j <= i + 1; j++) {
                dp[j] = dpp[j - 1];
            }
        } else {
            for (int j = 1; j <= i + 1; j++) {
                dp[j] = (dp[j - 1] + dp[j]) % mod;
            }
        }
        ans = (ans + dp[i + 1]) % mod;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        string S[N];
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = (ans + solve(S[i])) % mod;
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}
