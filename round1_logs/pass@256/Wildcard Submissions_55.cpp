
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
#include <array>
using namespace std;

const int MOD = 998244353;
const int MAX_LEN = 100;

int dp[MAX_LEN + 1][26]; // dp[i][0] -> number of prefixes of length i that have terminated
                         // dp[i][1] -> number of prefixes of length i that are open-ended
array<vector<int>, 26> next = {}; // next[i] -> list of next nodes given the current is i
                                   // used to track which character transitions to which
string S;

void addWildcards(int depth, int last) {
    // every transition from last to any letter possible increases "open" count for deeper level
    dp[depth + 1][1] += 25;
    dp[depth + 1][1] %= MOD;
    dp[depth][0] += 1;
    dp[depth][0] %= MOD;
    
    if (S[depth] == '?') {
        for (int i = 0; i < 26; i++) addWildcards(depth + 1, i);
        // every letter can follow any non-terminator, hence the modulo
        dp[depth][1] = 26;
        dp[depth][1] %= MOD;
        for (int i = 0; i < 26; i++) {
            next[i].push_back(last + 1);
        }
    } else {
        dp[depth + 1][1] += dp[depth][1] - dp[depth][0];
        dp[depth + 1][1] %= MOD;
        dp[depth][0] += dp[depth][1];
        dp[depth][0] %= MOD;
        next[S[depth] - 'A'].push_back(last + 1);
    }
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> terminal(MAX_LEN, 0);
        while (N--) {
            cin >> S;
            addWildcards(0, -1);
        }
        long long answer = 1;
        for (int i = 0; i < MAX_LEN; i++) {
            answer += (dp[i][0] + dp[i][1]) % MOD;
            answer %= MOD;
        }
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}
