
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

const long long mod = 998244353;

using namespace std;

int main() {
    // Read number of test cases
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long N;
        cin >> N;
        
        // Initialize DP Table
        vector<vector<long long>> dp(100 * N + 1, vector<long long>(1 << 26, 0));
        dp[0][0] = 1;
        
        // Process each wildcard string
        for (int i = 0; i < N; i++) {
            string S;
            cin >> S;
            
            vector<vector<long long>> temp = dp;
            dp.clear();
            dp.resize(100 * N + 1, vector<long long>(1 << 26, 0));

            for (int j = 0; j < min((int)S.length(), 100); j++) {
                char c = S[j];
                for (int k = 0; k < (1 << 26); k++) {
                    long long acc = temp[j][k];
                    if (acc == 0) continue;

                    if (c == '?') {
                        for (int l = 0; l < 26; l++) {
                            dp[j + 1][k | (1 << l)] += acc;
                            dp[j + 1][k | (1 << l)] %= mod;
                        }
                    } else {
                        dp[j + 1][k | (1 << (c - 'A'))] += acc;
                        dp[j + 1][k | (1 << (c - 'A'))] %= mod;
                    }
                }
            }
        }
        
        // Sum all partial paths count to get total nodes
        long long answer = 0;
        for (int i = 0; i < (1 << 26); i++) {
            answer += dp[(int)S.length()][i];
            answer %= mod;
        }
        
        // Output result
        cout << "Case #" << t << ": " << answer << endl;
    }

    return 0;
}
