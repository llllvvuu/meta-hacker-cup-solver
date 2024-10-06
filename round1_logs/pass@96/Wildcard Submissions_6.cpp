
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
#define MOD 998244353
using namespace std;

int dp[100][1<<26], masks[100], T, N, S, type[100];

int add(int a, int b) {
    return (a + b) % MOD;
}

int multiply(int a, int b) {
    return (1LL * a * b) % MOD;
}

bool valid(int i) {
    for(int j = 0; j < S; j++) {
        if(masks[i][j] != 1 && masks[i][j] == 0)
            return 0;
    }
    return 1;
}

int main() {
    cin >> T;
    for(int caseNum = 1; caseNum <= T; caseNum++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            char c;
            string s; cin >> s;
            S = ((int)s.size());
            masks[i] = 0;
            type[i] = 0;
            for(int j = 0; j < S; j++) {
                c = s[j];
                if(c == '?') {
                    type[i] = 1;
                    masks[i] |= (1 << j);
                } else masks[i] |= (1 << c - 'A');
            }
        }
        dp[0][0] = 1;
        for(int n = 0; n < S; n++) {
            for(int mask = 0; mask < (1<<S); mask++) {
                if(!valid(mask)) continue;
                dp[n + 1][mask] = add(dp[n + 1][mask], dp[n][mask]);
                if(type[i] && (mask & masks[i]) == masks[i])
                    dp[n + 1][mask ^ masks[i]] = add(dp[n + 1][mask ^ masks[i]], dp[n][mask]);
            }
        }
        int ans = 1;
        for(int mask = 1; mask < (1<<S); mask++)
            ans = add(ans, dp[S][mask]);
        cout << "Case #" << caseNum << ": " << ans << '\n';
    }
    return 0;
}
