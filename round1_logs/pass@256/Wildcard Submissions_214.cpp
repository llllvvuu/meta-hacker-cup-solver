
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
const int MOD = 998244353;

int dp[101][26*26*26]; // Up to 4 positions of question marks

for each wildcard string S in S1...SN:
    int pos[101] = {0}; // Track positions of question marks for each index in S
    initialize dp for S
    
    for idx in 0..length(S)-1:
        if S[idx] == '?': pos[idx]++
    
    for idx in 0..length(S)-1:
        for prevprefix in 0..length(S)-1:
            for curr in 'A'..'Z':
                for next in 0..25:
                    if S[idx] == '?' or S[idx] == curr:
                        if pos[idx] >= 2:
                            dp[idx + 1][prevprefix*26 + next] += dp[idx][prevprefix] // Wildcard characters

                        dp[idx + 1][(prevprefix << 1) + next] += dp[idx][prevprefix] // Known character
                            
dp[length(S)][mask] += 1 (this step increments the last prefix)
finalans = dp[length(S)], i.e. final prefix count

accumulate value from each wildcard string modulo MOD

return finalans % MOD
