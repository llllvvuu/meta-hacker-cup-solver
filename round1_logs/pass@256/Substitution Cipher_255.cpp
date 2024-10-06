
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

int decode_cnt(string str) {
    int dp[100022] = {0};
    dp[0] = 1;
    for (int i = 0; i < str.size(); i++) {
        dp[i+1] += dp[i];
        dp[i+1] %= MOD;
        if (i >= 1 && (str[i-1] != '0' || i-2 >= 0 && str[i-2] != '0')) {
            int val = (str[i-1] - '0') * 10 + str[i] - '0' - 1;
            dp[i+1] += val < 26 && i-1 >= 0 ? dp[i-1] : 0;
            dp[i+1] %= MOD;
        }
    }
    return dp[str.size()];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string E;
        int K;
        cin >> E >> K;
        int N = E.size();
        string ans{"9"*N + '0'};
        int ans_cnt = 0;
        for (int i = 1; i <= N; i++) {
            E[i-1] = '1';
            int cnt;
            for (int j = 0; j < N; j++) {
                if (i > N-j-N%2 && N-j-N%2 > 0) continue;
                cnt = decode_cnt(E);
                if (cnt >= ans_cnt) {
                    string tmp;
                    for (int k = 0; k < N; k++)
                        tmp.push_back(E[k] == '?' ? '9' : E[k]);
                    if (cnt == ans_cnt)
                        ans = min(ans, tmp);
                    else
                        ans = tmp;
                    ans_cnt = cnt;
                }
                E[(N-j-N%2+1)/2-1] = '1';
                E[(N-j-N%2+1)/2] = '0';
            }
            if (N-i == 0) break;
            int mask = 1;
            for (int j = i-1; j >= 0; j--) {
                E[j] = ((E[j] == '?' ? mask : E[j]-'0') + ((mask+9)%10))%10+'0';
                if (mask == 1) {
                    E[j] = '0';
                    break;
                }
                mask *= 10;
            }
        }
        cout << "Case #" << t << ": " << ans << ' ' << ans_cnt << endl;
    }
    return 0;
}
