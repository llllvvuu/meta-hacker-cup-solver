
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
int N;

long multiply(int a, int b) {
    return (long)a * b % MOD;
}

int solve() {
    cin >> N;
    vector<string> wildcards(N);
    for (int j = 0; j < N; ++j) {
        cin >> wildcards[j];
    }
    vector<vector<int>> dp(101, vector<int>(N + 1));
    for (int j = 0; j < N; ++j) dp[0][j + 1] = 1;
    for (int i = 1; i < 101; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j + 1] = dp[i - 1][j + 1];
            if (i > wildcards[j].size()) {
                continue;
            }
            if (wildcards[j][i - 1] != '?') {
                if (wildcards[j][i - 1] != wildcards[0][i - 1]) {
                    dp[i][j + 1] = multiply(dp[i][j + 1], (int)1);
                    dp[i][j + 1] = (dp[i][j + 1] + 1) % MOD;
                }
            } else {
                dp[i][j + 1] = multiply(dp[i][j + 1], (int)2);
            }
        }
    }
  
    int sum = 0;
    for (int i = 0; i < 101; ++i) {
        dp[i][0] = sum = (sum + dp[i][0]) % MOD;
        for (int j = 1; j < N + 1; ++j) {
            dp[i][0] = (dp[i][0] + dp[i][j]) % MOD;
            dp[i][j] = dp[i][0];
        }
    }
    return dp[100][0];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }
    return 0;
}
