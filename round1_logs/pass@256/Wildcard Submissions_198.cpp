
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
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 998244353;
const int MAX = 105;
const int MAXC = 26;  // 26 uppercase Latin letters

vector<int> toidx(char c) {
    return c == '?' ? vector<int>(MAXC, 1) : vector<int>(MAXC, 0);
}

int dp[MAX][1 << 25];  // Number of ways to reach each subtrie state with each cnt use
int last[MAX][1 << 25];  // Pointer to previous subtrie state for path reconstruction

int dfs(int cur, int cnt, const vector<vector<int>>& chars) {
    if (cnt >= chars.size()) return 1;  // Base case: passed all characters
    if (dp[cnt][cur] != -1) return dp[cnt][cur];

    int& ans = dp[cnt][cur];
    ans = 0;

    for (int c = 0; c < MAXC; ++c) {
        if (chars[cnt][c]) {
            for (int subtrie = 0; subtrie < (1 << chars.size()); ++subtrie) {
                if (cur & (1 << c)) continue;  // Skip if bit is set
                int newstate = (cur | (1 << c));
                ans += dfs(cnt + 1, newstate, chars);
                ans %= MOD;
            }
        }
    }
    return ans;
}

int makeTrie(string& s) {
    vector<vector<int>> chars;
    for (char c : s) {
        chars.push_back(toidx(c));
    }
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, chars);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        string S[N];
        for (int i = 0; i < N; ++i) cin >> S[i];

        int result = 0;
        for (int i = 0; i < N; ++i) {
            result += makeTrie(S[i]);
            result %= MOD;
        }

        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}
