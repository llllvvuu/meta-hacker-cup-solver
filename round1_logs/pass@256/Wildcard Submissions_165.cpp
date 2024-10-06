
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
#include <string>
#include <vector>
using namespace std;

int dp[26][1 << 26];
int mod = 998244353;

int dfs(vector<string> &dict, int i, int bitmask) {
    if (~dp[i][bitmask]) return dp[i][bitmask];
    dp[i][bitmask] = 0;
    for (int k = 0; k < dict[i].length(); k++) {
        dp[i][bitmask] = (dp[i][bitmask] + dfs(dict, i, bitmask | (1 << dict[i][k] - 'A')) + 1) % mod;
    }
    return dp[i][bitmask];
}

int solve(vector<string> &dict) {
    int res = 1;
    for (auto &s : dict) {
        int b = 0;
        for (auto c : s) b |= (1 << (c - 'A'));
        res = (res + dfs(dict, 0, b)) % mod;
        memset(dp, ~0, sizeof dp);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> dict(N);
        for (int i = 0; i < N; i++) cin >> dict[i];
        cout << "Case #" << t << ": " << solve(dict) << endl;
    }
    return 0;
}
