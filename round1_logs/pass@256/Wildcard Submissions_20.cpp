
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
#include <numeric>
using namespace std;
constexpr int MOD = 998244353;

vector<vector<long long>> evaluate_patterns(const vector<string> &ps) {
    int len = ps[0].size();
    vector<vector<long long>> dp(len + 1, vector<long long>(27));
    vector<int> criterias(len, -1);
    int axillary = 0;

    for (auto s : ps) {
        vector<int> new_criterias(s.size());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                new_criterias[i] = -1;
            } else {
                if (isalpha(s[i])) {
                    new_criterias[i] = toupper(s[i]) - 'A';
                    if (criterias[i] == -1) {
                        ++axillary;
                    }
                }
            }
        }

        for (int i = axillary; i < new_criterias.size(); ++i) {
            if (criterias[i] != -1) continue; // skipped b/c determined
            long long mult = dp[i][26];
            if (new_criterias[i] == -1) { // still contains '?'
                long long sum = (dp[i][26] * 26) % MOD;
                mult = (sum + ((sum < 26) ? 1 : MULT(sum, MOD - 2)) + MOD) % MOD;
            } else {
                criterias[i] = new_criterias[i];
                mult = 1;
            }
            dp[i+1][new_criterias[i]] += mult;
            for (int x = 0; x < 26; ++x) {
                dp[i+1][x] += (mult * dp[i][x]);
                if (dp[i+1][x] > MOD) dp[i+1][x] -= MOD;
            }
        }
    }

    return dp[len];
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int i = 1; i <= test_cases; ++i) {
        int N;
        cin >> N;
        vector<string> pattern_roots(N);
        for (int j = 0; j < N; ++j) {
            cin >> pattern_roots[j];
        }

        auto result = evaluate_patterns(pattern_roots);
        int ans = 0;
        for (int j = 0; j < 26; ++j) {
            ans = (ans + result[dp.size()-1][j]) % MOD;
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
