
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
#define MOD 998244353
using namespace std;

int T, N, A;

vector<vector<int>> dp;

int main() {
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        dp = vector<vector<int>>(N + 1, vector<int>(101, 0));
        int d = 0;
        dp[0][0] = 27; dp[0][100] = 1;
        for (int j = 0; j < N; ++j) {
            cin >> A;
            d = 0;
            for (int k = 0; k < A; ++k) {
                char c;
                cin >> c;
                d += c == '?';
            }
            for (int l = 0; l <= 100; ++l) {
                dp[j + 1][d - 1] = (dp[j + 1][d - 1] + 26LL * dp[j][l]) % MOD;
                dp[j + 1][l - 1] = (dp[j + 1][l - 1] + dp[j][l]) % MOD;
                dp[j + 1][l - 1] = (dp[j + 1][l - 1] + 25LL * dp[j][l]) % MOD;
            }
        }
        cout << "Case #" << i << ": " << (dp[N][0] - dp[N][100] + MOD) % MOD << endl;
    }
    return 0;
}
