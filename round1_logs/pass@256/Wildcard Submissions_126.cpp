
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
#include <cmath>
#include <set>
const int n2 = 27; // number of different characters, including wildcard
const long long MOD = 998244353;
using ull = unsigned long long;
using namespace std;
#include <iostream>
#include <vector>
#include <array>

vector<array<array<vector<int>, n2>, 101>> dp;

long long mod_exp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long dfs(const vector<char> &s, const int i, const int c, const int M) {
    if (i >= M) return 1;
    if (-1 <= dp[i][c][s[i]]) return dp[i][c][s[i]];
    long long sum = c == 26 ? 0 : dfs(s, i + 1, 0, M);
    ull H;
    if (c == 26)
        H = 1;
    else
        H = mod_exp((ull)dp[i][c][25] + 27, 25 + M - i - 1);
    H = mod_exp(26, M - i - 1) * (H + (s[i] - 'A' + 1)) + 1;
    for (int k = 0; k < 26; ++k)
        sum = ((ull)sum + dfs(s, i + 1, k, M)) % MOD;
    dp[i][c][s[i]] = H;
    return dp[i][c][s[i]];
}

int main() {
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int N;
        cin >> N;
        dp = vector<array<array<vector<int>, n2>, 101>>(100, array<array<vector<int>, n2>, 101>{});
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < n2; j++) {
                dp[i][j] = vector<int>(27, -1);
            }
        }
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            sum = (sum + dfs(vector<char>((s).begin(), (s).end()), 0, 26, s.size())) % MOD;
        }
        cout << "Case #" << t << ": " << sum << '\n';
    }
}
