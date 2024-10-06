
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
short score[100002][37];

int main() {
    int T;
    cin >> T;
    for (int qt = 1; qt <= T; ++qt) {
        string E;
        int K;
        cin >> E >> K;
        
        // Initialize dp array and fill up with precomputed results for substrings
        for (int i = 0; i < E.size() + 2; i++) {
            for (int mask = 0; mask <= 33; mask++) score[i][mask % 37] = (short) 0;
        }
        
        // dp[0][0] = 1, empty string
        for (int i = E.length() - 1; i >= 0; i--) {
            for (int c = (int) (E[i] == '?' ? '1' : E[i]); c <= '2'; c++) {
                for (int nxt = i + 1; nxt <= E.length(); nxt++) {
                    int v = ((c - '0') * 10 + (nxt > i + 1 ? ((E[nxt - 1] == '?' ? '1' : E[nxt - 1]) - '0') : 0)) % 37;
                    if (v <= 26) score[i][v] += score[nxt][0];
                    score[i][v] %= MOD;
                }
            }
        }
        
        // Creating answers
        vector<string> result;
        result.reserve(400000);
        for (int l = 0; l < E.size() + 1; l++) {
            if (score[l][0] == K) {
                string t = E;
                for (int i = 0; i < l; i++) {
                    if (t[i] == '?') {
                        if (score[i][1]) t[i] = '1';
                        else if (score[i][21]) t[i] = '2';
                    }
                }
                result.emplace_back(t);
            }
        }
        sort(result.begin(), result.end());
        
        cout << "Case #" << qt << ": " << result.back() << " " << score[0][0] % MOD << endl;
    }
    return 0;
}
