
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

const int MOD = 998244353;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        vector<vector<long long>> dp(101, vector<long long>(26, 0));
        dp[0][0] = 1;

        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            vector<vector<long long>> tmp = dp;
            for (char ch : s) {
                vector<vector<long long>> nxt = tmp;
                if (ch == '?') for (int j = 0; j < 26; j++) for (int l = 0; l < 101; l++) nxt[l][j] += tmp[l][j];
                else for (int l = 0; l < 100; l++) nxt[l + 1][ch - 'A'] = tmp[l][ch - 'A'];
                tmp = nxt;
            }
            dp = move(tmp);
        }

        long long result = 0;
        for (int i = 0; i < 101; i++) for (int j = 0; j < 26; j++) result = (dp[i][j] * (i + 1) + result) % MOD;
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
