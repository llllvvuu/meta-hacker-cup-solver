
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
#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
using namespace std;

const int MOD = 998244353;

set<pair<int, string>> prefixes; // stores unique prefixes

long long dp(string& s, int j, bool starting) {
    if (j == s.length()) return starting;
    auto x = make_pair(j, s);
    if (!prefixes.insert(x).second) return dp(s, j + 1, starting); // already processed
    
    long long ans = 0;
    if (s[j] == '?') {
        for (char c = 'A'; c <= 'Z'; c++) // calculate possibilities for each character choice
            ans += dp(s, j + 1, starting);
    } else {
        ans += dp(s, j + 1, starting); // continue with the same starting state
    }
    return ans;
}

int solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        dp(s, 0, true);
    }
    long long totalNodes = prefixes.size();
    return totalNodes % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
