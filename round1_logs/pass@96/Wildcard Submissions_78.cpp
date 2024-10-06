
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
using namespace std;

const int MOD = 998244353;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        string pattern[N];
        for (int i = 0; i < N; i++) {
            cin >> pattern[i];
        }

        long long dp[101][1 << 27] = {0};  // max length is 100
        dp[0][0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = pattern[i].size() - 1; j >= 0; j--) {  // Fill in reverse order
                for (int mask = 0; mask < 1 << 26; mask++) { 
                    dp[j][mask] += dp[j + 1][mask]; 
                    if (pattern[i][j] == '?') {
                        for (int c = 0; c < 26; c++) {
                            if ((mask & (1 << c)) == 0) {
                                dp[j][mask + (1 << c)] = (dp[j][mask + (1 << c)] + dp[j][mask]) % MOD;
                            }
                        }
                    } else { 
                        int c = pattern[i][j] - 'A'; 
                        if ((mask & (1 << c)) == 0) { 
                            dp[j][mask + (1 << c)] = (dp[j][mask + (1 << c)] + dp[j][mask]) % MOD;
                        }
                    }
                }
            }
        }

        long long result = 0;
        for (int mask = 0; mask < 1 << 26; mask++) {
            result = (result + dp[0][mask]) % MOD;
        }

        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
