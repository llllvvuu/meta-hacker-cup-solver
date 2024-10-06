
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
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int N;
vector<string> S;
int dp[26][101];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        S.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
        dp[0][0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 26; j++) {
                fill(&dp[j][0], &dp[j][0] + 101, 0);
            }
            dp[S[i][0] - 'A'][1] = 1;
            for (int j = 2; j <= S[i].length(); j++) {
                if (S[i][j - 1] == '?') {
                    for (int k = 0; k < 26; k++) {
                        dp[k][j] += dp[k][j - 1];
                        if (dp[k][j] >= MOD) {
                            dp[k][j] -= MOD;
                        }
                    }
                } else {
                    dp[S[i][j - 1] - 'A'][j] = dp[S[i][j - 1] - 'A'][j - 1];
                }
            }
        }
        int result = 0;
        for (int j = 1; j <= 100; j++) {
            for (int i = 0; i < 26; i++) {
                result = (result + dp[i][j]) % MOD;
            }
        }
        cout << "Case #" << t << ": " << result << "\n";
        fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
    }
}
