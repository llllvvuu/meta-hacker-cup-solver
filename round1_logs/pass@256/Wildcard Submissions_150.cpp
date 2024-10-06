
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
using namespace std;

const int MOD = 998244353;
const int CHARSET = 26; // Number of uppercase Latin letters

// Convert a character to a bitmask representing its presence
int charToBit(char c) {
    return 1 << (c - 'A');
}

// Compute the total number of nodes created in the trie modulo MOD
int solve(string& s) {
    int N = s.length();
    vector<vector<int>> dp(N, vector<int>(1 << CHARSET, 0));
    
    // Base case, the root node (empty string)
    dp[0][0] = 1;
    
    for(int i = 1; i <= N; ++i) {        
        // We consider two cases: s[i-1] is a character or a wildcard
        for(int mask = 0; mask < (1 << CHARSET); ++mask) {            
            if(s[i - 1] != '?') {
                // Case 1: s[i-1] is a character
                dp[i][mask] = (dp[i][mask] + dp[i - 1][mask & ~charToBit(s[i - 1])]) % MOD;  
            } else {
                // Case 2: s[i-1] is a wildcard (?)
                for(int j = 0; j < CHARSET; ++j)
                    dp[i][mask] = (dp[i][mask] + dp[i - 1][mask | (1 << j)]) % MOD;
            }
        }
    }
    // Calculate the total number of unique nodes
    int total_nodes = 0; 
    for(int mask = 0; mask < (1 << CHARSET); ++mask)
        total_nodes = (total_nodes + dp[N][mask]) % MOD;
    return total_nodes;
}

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        int N; cin >> N;
        vector<string> S(N);
        for(auto& s: S) cin >> s;

        long long total_nodes = 1; // Start with root node, whose value is `000000000000000000000000`
        for(const auto& s: S)
            total_nodes = (total_nodes + solve(s) - 1) % MOD;
        
        cout << "Case #" << t << ": " << total_nodes << "\n";
    }
    
    return 0;
}
