
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
#include <cstring>
using namespace std;

const int MOD = 998244353;

vector<int> dp[(int)110][(int)110];

int get_wildcards(const string &s, int cursor) {
    if (cursor == s.size()) return 1;
    if (dp[cursor][s.size() - cursor].empty()) {
        dp[cursor][s.size() - cursor] = {1};
        for (int i = cursor; i < s.size(); i++) {
            if (s[i] != '?') dp[cursor][s.size() - cursor].push_back(dp[cursor][s.size() - cursor].back());
            else dp[cursor][s.size() - cursor].push_back(25ll * dp[cursor][s.size() - cursor].back() % MOD);
        }
    }
    return dp[cursor][s.size() - cursor][s.size() - cursor];  
}

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int n; cin >> n;
        string s[(int)26];
        long long ans = 1; // There's always one node for the empty path
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < s[i].size(); j++) ans = (ans + get_wildcards(s[i], j)) % MOD;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
