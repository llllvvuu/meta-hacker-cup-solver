
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
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int ALPHABET_SIZE = 26;

long long dp[101][ALPHABET_SIZE]; // dp[i][j] stores results till length i, ending with character j

long long solve(const vector<string>& patterns) {
    int max_len = 0;
    auto generatePattern = [](const string& pattern) -> vector<int> {
        vector<int> patternInts(pattern.size());
        for(int i = 0; i < pattern.size(); i++)
            patternInts[i] = pattern[i] == '?' ? -1 : pattern[i] - 'A';
        return patternInts;
    };
    
    for(int i = 0; i < patterns.size(); i++) {
        max_len = max(max_len, (int)patterns[i].size());
        dp[0][26] = i == 0 ? 1 : dp[0][26] + 1; // 26 is a placeholder for patterns.size()
    }

    for(int i = 1; i <= max_len; i++) { // Iterate over all possible lengths
        int patternIndex = 0;
        dp[i % 2][26] = dp[(i-1) % 2][26]; // Track how many patterns
        for(int j = 0; j < patterns.size(); j++) {
            if(i <= patterns[j].size()) { // Only generate if the index is valid
                int charPos = patterns[j][i-1] == '?' ? -1 : patterns[j][i-1] - 'A';
                dp[i % 2][charPos] = (dp[(i-1) % 2][26] - 1 + MOD + 
                                      (charPos == -1 ? dp[(i-1) % 2][26] : dp[(i-1) % 2][charPos])) % MOD;
            }
            if(charPos != -1)
                dp[i % 2][26] = (dp[i % 2][26] + MOD - dp[(i-1) % 2][charPos] + MOD + dp[i % 2][charPos]) % MOD;
            else
                dp[i % 2][26]++;
            
            patternIndex++;
        }
    }
    
    long long totalNodes = dp[max_len % 2][26];
    return (totalNodes * (totalNodes+1) / 2) % MOD;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        vector<string> patterns(n);
        for (int j = 0; j < n; j++)
            cin >> patterns[j];

        cout << "Case #" << i << ": " << solve(patterns) << endl;
    }
    return 0;
}
