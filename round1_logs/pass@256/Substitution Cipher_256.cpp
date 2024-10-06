
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
#include <algorithm>
#include <cmath>
using namespace std;

const int MOD = 998244353;

long long dp[100001] = {}; // DP array for decoding counts
int K;

// Precompute decodings
vector<pair<int, string>> precompute(const string& str, int index = 0) {
    int n = str.size();
    vector<pair<int, string>> splits(n * 2);
    dp[n] = 1;
    splits[2 * (n - 1)] = {1, ""};

    // Compute DP values and splits from end to start
    for (int i = n - 1; i >= 0; --i) {
        char ch = str[i];
        if (ch == '?' || '1' <= ch && ch <= '9') {
            dp[i] = (dp[i + 1] + ch == '0' || (i + 1 < n && (ch == '2' && str[i + 1] >= '7'))) ? 0 : 1;
        } else dp[i] = 0;

        if (index < K && splits[i * 2] == splits[i * 2 + 1]) {
            splits[i * 2] = {splits[i * 2].first + dp[i], splits[i * 2].second};
        } else if (index < K) {
            splits[i * 2 + 1].first += dp[i];
            if (splits[i * 2 + 1].first > splits[i * 2].first)
                swap(splits[i * 2], splits[i * 2 + 1]);
            index++;
        }

        ch = '0';
        int val = ((ch - '0') * 10 + (int)(i + 1 < n ? (str[i + 1] - '0') : 0)) % MOD;
        splits[i * 2].second = string(ch + ((i + 1 < n && val <= 26) ? str[i + 1] : '0'));
    }
    splits[0].second = str;
    return splits;
}

// Main function to solve each test case
void solve() {
    string E;
    cin >> E >> K;
    K = min(K, (int)pow(2, E.size())) - 1;
    vector<pair<int, string>> splits = precompute(E, K);
    cout << "Case #" << ++test_case << ": " << splits[K].second << " " << splits[K].first << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        solve();
}
