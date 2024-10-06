
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
const long long MOD = 998244353;

long long dp[55][55];  // dp[i][j]: Ways to add edges to node [j characters from i]

vector<string> unwind;

long long dfs(long long i, long long j) {
    // Number of characters, prefix positions
    if (i == j) return 1;
    if (dp[i][j] != 0) return dp[i][j];
    long long ans = 0;
    for (long long k = 1; k <= i - j; k++) {
        ans = (ans + ((dfs(i, k) * dfs(k, j + 1))) % MOD);
    }
    return dp[i][j] = ans;
}

int main() {
    long long T;
    cin >> T;
    for (long long t = 1; t <= T; t++) {
        long long N;
        cin >> N;
        unwind.clear();
        for (long long i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (long long i = 0; i <= (int)s.size(); i++) {
                for (long long j = 0; j <= (int)s.size() - i; j++) {
                    string cur = s.substr(0, i) + s.substr(i + j, (int)s.size() - i - j);
                    unwind.push_back(cur);
                }
            }
        }
        long long ans = 1;
        for (auto s : unwind) {
            long long sum = 0;
            for (char c : s) {
                if (c == '?') sum++;
            }
            ans = (ans + (dfs((long long)s.size(), (long long)sum))) % MOD;
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}
