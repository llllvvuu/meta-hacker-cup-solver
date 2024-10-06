
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
#include <vector>
#include <string>
using namespace std;
const int MOD = 998244353;

typedef long long ll;
vector<vector<int>> memo;

int dp(const string& s, int idx) {
    if (idx == s.size()) return 1;
    if (memo[idx][s[idx] - 'A'] != -1) return memo[idx][s[idx] - 'A'];
    int res = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c == '?' || c == s[idx]) {
            res = (res + dp(c == '?' ? s : string(1, c) + s.substr(idx + 1), idx + 1)) % MOD;
        }
    }
    return memo[idx][s[idx] - 'A'] = res;
}

int countNodes(const string& pattern) {
    memo.clear();
    memo.resize(pattern.size(), vector<int>(26, -1));
    int distinctPrefixes = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        distinctPrefixes = (distinctPrefixes + dp(c + pattern, 0)) % MOD;
    }
    if (pattern[0] == '?') {
        distinctPrefixes = (distinctPrefixes + MOD - dp(pattern, 0)) % MOD;
    }
    return distinctPrefixes;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> patterns(N);
        for(int i = 0; i < N; i++) {
            cin >> patterns[i];
        }
        int ans = 1; // account for the root node
        for(int i = 0; i < N; i++) {
            ans = (ans + countNodes(patterns[i])) % MOD;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
