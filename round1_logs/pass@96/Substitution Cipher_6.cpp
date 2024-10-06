
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
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int MOD = 998244353;

int dp[100010];
int k;
string s;

int solve() {
    dp[s.size()] = 1;
    for (int l = s.size() - 1; l >= 0; l--) dp[l] = 0;
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i] == '?') s[i] = '2';
        else if (s[i] >= '3') return 0;
    }
    for (int i = 0; i < s.size() - 1; i++) {
        dp[i] = dp[i + 1];
        if (s[i] == '?' || s[i + 1] == '?') {
            dp[i] = (dp[i] + dp[i + 2]) % MOD;
        } else if (s[i] == '2' || s[i] == '1' && s[i + 1] < '7') {
            dp[i] = (dp[i] + dp[i + 2]) % MOD;
        }
    }
    string ans(s);
    for (int i = 0, end = min(k, s.size()); i < end; i++) {
        s[i] = '2';
        if (k > 1) k--;
        else s[i] = '1';
    }
    return k;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> s >> k;
        cout << "Case #" << t << ": " << solve() << ' ' << dp[0] << endl;
    }
}
