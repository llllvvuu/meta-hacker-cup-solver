
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

const int MAXN = 105;
const int MOD = 998244353;
const int N = 25;

int n, trie[2 * MAXN][26];
int m, dp[N + 5][MAXN][MAXN];

string s;

int merge(int c1, int c2) { return (1LL * c1 * c2 + c2) % MOD; }

int dp_up(int u, int v, int l, int r) {
    if (l > r)
        return 1;
    int &ans = dp[l][r][u];

    if (ans != -1)
        return ans;

    ans = 0;
    if (s[u] == '?') {
        for (int c = 1; c <= 26; c++) {
            ans = (ans + dp_up(u + 1, v, l, r)) % MOD;
            if (u + 1 <= r && s[u + 1] == '?')
                ans = (ans + 26LL * dp_up(u + 2, v, l, r)) % MOD;
        }
        dp[l][r][u] = ans;
        return ans;
    }

    ans = dp_up(u + 1, v, l, r);
    if (s[v] == '?') {
        for (int c = 1; c <= 26; c++) {
            ans = (ans + dp_up(u + 1, v - 1, l, r)) % MOD;
            if (u <= r && s[u] == '?')
                ans = (ans + 26LL * dp_up(u, v - 2, l, r)) % MOD;
        }
    } else
        ans = merge(ans, dp_up(u + 1, v - 1, l, r));

    return dp[l][r][u] = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> m;
    int len = s.size();
    cout << dp_up(0, len - 1, 0, len - 1) << '\n';
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        s = "";
        while (n--) {
            string str;
            cin >> str;
            s += str;
            s += '#';
        }
        cout << "Case #" << q + 1 << ": ";
        solve();
    }
    return 0;
}
