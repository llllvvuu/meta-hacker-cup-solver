
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
#include <sstream>
#include <vector>
using namespace std;

const int MOD = 998244353;
int N;
vector<string> patterns;
vector<vector<int>> memo;

int dfs(int patternIdx, int charIdx, string &current) {
    if (patternIdx == patterns.size() || charIdx == patterns[patternIdx].size()) {
        return 1; // Reached end. Represents a valid path.
    }
    if (charIdx > 0 && memo[patternIdx][charIdx] != -1)
        return memo[patternIdx][charIdx];
    int ans = 0;
    for (int c = 0; c < 26; ++c) {
        string next = current;
        bool avoidsRedundant = true; 
        for (int i = charIdx; i < patterns[patternIdx].size() && avoidsRedundant; ++i) {
            if (patterns[patternIdx][i] != '?' && patterns[patternIdx][i] - 'A' == c) {
                ans += dfs(patternIdx + 1, charIdx == 0 ? 0 : charIdx - 1, next) % MOD;
                ans %= MOD;
                avoidsRedundant = false;
            } else if (patterns[patternIdx][i] == '?') {
                next += char('A' + c);
            }
        }
        if (avoidsRedundant) 
            ans = ans + dfs(patternIdx, charIdx + 1, next) % MOD;
    }
    if (charIdx > 0) 
        memo[patternIdx][charIdx] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        memo.assign(25, vector<int>(101, -1));
        cin >> N; 
        patterns.clear();
        patterns.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> patterns[i];
        }
        int totalNodes = dfs(0, 0, ""); 
        cout << "Case #" << t << ": " << totalNodes << endl;
    }
    return 0;
}
