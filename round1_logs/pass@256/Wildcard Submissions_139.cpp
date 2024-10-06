
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
#include <vector>
#include <deque>
#include <assert.h>
#include <iostream>

using namespace std;

unsigned MOD = 998244353;

const int maxN = 105;

int expand(int prefix_len, vector<int>& prefix_count) {
    const int bits = 32 - __builtin_clz(prefix_len + 1);

    int dp[prefix_len + 1][(1 << 26)]; // Number of ways to match prefix_length i+1 with the prefix_length of wildcards covered by mask

    auto copy = [](int s) { return s; }; // (no change)

    auto bitmask = [](char& c, int& mask) {
        if (c == '?')
            c = 0;
        c &= mask;
        return c != 0;
    };

    for (int mask = 0; mask < (1 << 26); mask++, copy = bitmask)
       dp[0][mask] = 1;

    for (int i = 1; i <= prefix_len; ++i) {
        for (int mask = 0; mask < (1 << 26); mask++) {
            dp[i][mask] = prefix_count[i] * 25; // 26 [A-Z] - one matched by '?' and wildcards

            int size = __builtin_popcount(mask) != 26; // Whether we're covered by previous mask

            // Trying to match 'c' with a single character letters
            char c = 0;

            int original_mask = mask;
            int new_mask = mask | (1 << (c - 'A'));
            while (size++ < bits) {
                int d = dp[i - 1][new_mask] - dp[i - 1][mask] * (c ? 0 : original_mask);
                dp[i][mask] -= d * copy(c);

                c = __builtin_ctzn(new_mask ^ mask);
                mask = new_mask;
                new_mask |= (1 << (c - 'A'));
                copy = bitmask;
            }
        }
    }

    // sum of 0..prefix_len * d[prefix_count[i]];
    int sum = 0;
    for (int i = 0; i <= prefix_len; ++i) {
        int d = (dp[i][(1 << 26) - 1] % MOD);
        sum = (sum + d + i * d % MOD) % MOD;
    }
    return sum;
}

void solve_case() {
    int N;
    cin >> N;
    vector<int> prefix_count(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;

        for (int j = 0, is_prefix = 1; j < s.length(); ++j) {
            ++prefix_count[j + 1];
        }
    }
    for (int i = 0; i <= N; ++i)
        prefix_count[i] = prefix_count[i] * i - prefix_count[i - 1] * (1 + i % 2);
    
    int answer = 1; 
    for (int i = 0; i <= N; ++i) {
        answer += expand(i, prefix_count);
        answer = answer % MOD;
    }
    cout << answer;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) 
        cout << "Case #" << t + 1 << ": ";
        solve_case();
        if (t != T - 1) cout << '\n';
}
