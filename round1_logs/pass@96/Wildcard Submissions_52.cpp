
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
const int MOD = 998244353;

const int SIGMA = 26 + 1; // 26 letters + 1 wildcard
int dp[101][1 << SIGMA][101]{0}; // dp[i][state][j] is number of substrings
// ending at index j from pattern i with state value state

void add(int& a, int b) {
    a = (a + b) % MOD;
}

int solve(int n, vector<string> &patterns) {
    int conv[256];
    for (char i = 'A'; i <= 'Z'; i++) {
        conv[i] = i - 'A';
    }
    for (char w : "?") {
        conv[w] = SIGMA - 1;
    }

    // dp[i][state][j] is the number of patterns of length i
    // that can be represented by state compressed to index j
    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int p = 0; p <= (int)patterns[i].size(); p++) {
            for (int state = 0; state < 1 << SIGMA; state++) {
                add(dp[p + 1][state][p + 1], dp[p][state][p]);
            }
            for (int p = 0; p < (int)patterns[i].size(); p++) {
                int next_state = ((state << 1) | (conv[patterns[i][p]]));
                for (int j = 0; j <= p; j++) {
                    add(dp[p + 1][next_state][p + 1], dp[p][state][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= (int)patterns[0].size(); i++) {
        for (int state = 0; state < 1 << SIGMA; state++) {
            add(ans, dp[i][state][i]);
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        vector<string> patterns(N);
        for (int j = 0; j < N; j++) {
            cin >> patterns[j];
        }
        cout << "Case #" << i << ": " << solve(N, patterns) << endl;
    }
    return 0;
}
