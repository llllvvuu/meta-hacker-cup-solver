
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
using namespace std;

constexpr long long MOD = 998244353;
long long dp[101][26];
vector<vector<long long>> par(101, vector<long long>(26, -1));

long long dfs(int depth, int parent) {
    if (dp[depth][parent] != -1) 
        return dp[depth][parent];
    if (depth == 0) 
        return 1;
    
    long long res = 0;
    for (int i = 0; i < 26; ++i) {
        if (par[depth][parent] == i) 
            continue;
        if (par[depth][i] == parent) 
            res += dfs(depth-1, i);
        else 
            res += dfs(depth, i);
    }
    dp[depth][parent] = res % MOD;
    return res % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        fill(dp[0], dp[101], -1);
        char c;
        while (N--) {
            int depth = 0;
            while (cin >> c) {
                if (c == '|') 
                    break;
                if (par[depth][c - 'A'] == -1) 
                    par[depth][c - 'A'] = par[depth-1][c == '?' ? 10 : c - 'A'];
                depth++;
            }
        }
        cout << "Case #" << t << ": ";
        cout << dfs(depth, 10) << "\n";
    }
    return 0;
}
