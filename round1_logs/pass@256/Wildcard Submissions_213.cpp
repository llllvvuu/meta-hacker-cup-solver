
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
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int dp[1234567];

void compute_new(string& s) {
    int N = (int)s.size(), i;
    for (i = 0; i < N && s[i] == '?'; ++i) dp[1 << i] = 1;
    for ( ; i < N; ++i) {
        if (s[i] == '?') { 
            for (int j = 0; j < i; ++j) {
                dp[(1 << i) | (1 << j)] = dp[(1 << j)] + dp[(1 << i)];
                dp[(1 << i) | (1 << j)] %= MOD;
            }
            dp[(1 << i)] = 0;
            for (int j = 0; j < i; ++j) 
                dp[(1 << i) | (1 << j)] += dp[(1 << j)];
        }			
    }
    for (int mask = 0, path = 0; mask < (1 << N); ++mask) {
        path += dp[mask];
        path %= MOD;
        dp[mask] = path;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        fill(dp, dp + 1234567, 0);
        int N;
        cin >> N;
        vector<string> s(N);
        for (int i = 0; i < N; i++) cin >> s[i];
        for (string& str : s) compute_new(str);
        cout << "Case #" << t << ": " << dp[(1 << (int)s[0].size())-1] << endl;
    }     
}
