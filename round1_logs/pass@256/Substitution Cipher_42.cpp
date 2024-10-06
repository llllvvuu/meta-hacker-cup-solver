
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
using namespace std;

long long dp[99999][10], mod = 998244353;

long long countDecodings(string s, int i = 0, int prev = 9) {
    if (i >= s.size()) return 1;
    if (dp[i][prev] != -1) return dp[i][prev];
    long long res = 0;

    if (s[i] != '?') {
        int num = s[i] - '0';
        if (num <= 2) {
            if (i + 1 < s.size() && (s[i + 1] - '0' <= 6 && s[i] == '2') || (s[i] == '1' && s[i + 1] <= '9')) {
                res = (res + countDecodings(s, i + 2, num)) % mod;
            }
        } else if (num <= 6 && prev == 2) {
            res = (res + countDecodings(s, i + 1, prev)) % mod;
        }
        res = (res + countDecodings(s, i + 1, num)) % mod;
    } else {
        for (int j = 1; j <= (prev == 2 ? 6 : 9); j++) {
            res = (res + countDecodings(s, i + ((j / 10) == 0), j)) % mod;
        }
    }

    dp[i][prev] = res;
    return res;
}

void solve() {
    string s;
    int k;
    cin >> s >> k;
    memset(dp, -1, sizeof(dp));

    long long maxcnt = 0;
    string ans = "";
    do {
        string tmp = s;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == '?') tmp[i] = '1';
        }

        long long cnt = countDecodings(tmp);
        if (cnt > maxcnt) {
            maxcnt = cnt;
            ans = tmp;
        }

    } while (next_permutation(s.begin(), s.end()));
    string options;
    for (int i = 0; i < s.size() && k > 0; i++) if (s[i] == '?') s[i] = '0';
    do {
        if (countDecodings(s) == maxcnt) {
            options += s;
            k--;
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << "Case #" << ++caseNumber << ": " << options[k] << ' ' << maxcnt << "\n";
}

int main() {
    int t = 0;
    cin >> t;
    while (t--) solve();
    return 0;
}
