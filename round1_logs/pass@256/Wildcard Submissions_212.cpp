
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

typedef long long ll;
const ll MOD = 998244353;

int t;
ll dp[26 + 10][100 + 3];
vector<string> strs;
bool is_qmark(char ch) { return (ch == '?'); }

ll powmod(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    while(y > 0) {
        if (y & 1)
            res = ((res % MOD) * (x % MOD)) % MOD;
        y >>= 1;
        x = ((x % MOD) * (x % MOD)) % MOD;
    }
    return res;
}

void insert_at_depth(string & s, int d, int pos) {
    ll res = (dp[d][pos] * powmod(26, d - pos, MOD)) % MOD;
    if (is_qmark(s[d]))
        dp[d + 1][pos] = (res + dp[d][pos]) % MOD;
    else
        dp[d + 1][pos] = res;
}

void traverse(string & s) {
    for (int e = 0; e < (int)s.size(); ++e) {
        for (int st = 0; st < e; ++st)
            insert_at_depth(s, e, st);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 105; ++i)
        for (int j = 0; j < 103; ++j)
            dp[i][j] = 0;
    for (int e = 0; e < 1; ++e)
        dp[0][e] = 1;

    cin >> t;
    for (int ti = 0; ti < t; ++ti) {
        strs.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            strs.push_back(s);
        }

        for (int i = 0; i < strs.size(); ++i) {
            traverse(strs[i]);
        }

        ll ans = (dp[n][strs[0].size()] - 1 + MOD) % MOD;
        cout << "Case #" << ti + 1 << ": " << ans << endl;

        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 103; ++j) {
                dp[i][j] = 0;
                dp[0][j] = 1;
            }
    }
}
