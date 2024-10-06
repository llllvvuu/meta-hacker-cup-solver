
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

const int MOD = 998244353;
vector<string> best;
vector<int> best_counts;

bool is_valid_decode(const string &s) {
    int n = s.length();
    vector<int> dp(n+1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        if (i > 0 && s.substr(i-1, 2) <= "26") dp[i + 1] += dp[i - 1];
        dp[i + 1] %= MOD;
    }
    return dp[n];
}

void enumerate(int index, string &s, vector<string> &pos) {
    if (index == s.length()) {
        if (is_valid_decode(s.substr(0, index))) {
            pos.push_back(s);
        }
        return;
    }
    if (s[index] == '?') {
        for (char c = '0'; c <= '9'; c++) {
            if (index == 0 || c > '0' || index == 1 || s.substr(index-1, 2) <= "26") {
                s[index] = c;
                enumerate(index + 1, s, pos);
            }
        }
    } else {
        enumerate(index + 1, s, pos);
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        best.clear();
        best_counts.assign(1, 0);
        string encoded;
        int K;
        cin >> encoded >> K;
        vector<string> pos;
        enumerate(0, encoded, pos);
        for (const string &e : pos) {
            int count = is_valid_decode(e);
            while (best_counts.back() < count) {
                best_counts.push_back(count);
            }
            if (best_counts.back() == count) {
                best.push_back(e);
            }
        }
        vector<string> sorted = best;
        sort(sorted.begin(), sorted.end());
        cout << "Case #" << t << ": " << sorted[K-1] << " " << best_counts.back() << endl;
    }
    return 0;
}
