
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
#include <bitset>
#include <cassert>
#include <iostream>
using namespace std;
typedef long long ll;
constexpr ll pmod = 998244353;
constexpr int nBase = 26;
constexpr int nMaxMask = (1 << nBase);

bitset<101 * nMaxMask> dp[2]; // dp[i][len][mask] = # string of length 'len' ending in 'mask' if first 'i' characters in S_y are considered

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nTest;
    cin >> nTest;
    for (int t = 1; t <= nTest; t++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for (int k = 0; k < N; k++) {
            cin >> S[k];
        }
        for (int i = 0; i < nMaxMask; i++) {
            dp[t % 2][0][i] = (i == 0);
        }
        for (const string &s : S) {
            dp[(t+1)%2] = dp[t % 2]; // use previous step
            assert(s.size() <= 100);
            for (int len = 1; len <=s.size(); len++) {
                for (int mask = 0; mask < nMaxMask; mask++) {
                    dp[(t+1)%2][len][mask] = 0; // to avoid memory leak
                    // c: char at pos 'len-1' of every st
                    // isCharFixed: true if 's[len-1]' is fixed (not '?')
                    // isCharMatch : true if c == s[len-1]
                    for (int c = 0; c < nBase; c++) {
                        const bool isCharFixed = (mask >> c) & 1;
                        const bool isCharMatch = (isCharFixed && s[len-1] - 'A' == c) || !isCharFixed;
                        if (isCharMatch) {
                            const int newMask = isCharFixed ? mask : mask | (1 << c);
                            dp[(t+1)%2][len][newMask] = (dp[(t+1)%2][len][newMask] + dp[t%2][len-1][mask]) % pmod;
                        }
                    }
                }
            }
        }
        // add all the sum of dp[len][mask]
        ll ret = 0;
        for (int len = 0; len <=s.size(); len++) {
            for (int mask = 0; mask < nMaxMask; mask++) {
                ret = (ret + (ll) dp[t % 2][len][mask]) % pmod;
            }
        }
        cout << "Case #" << t << ": " << ret << endl;
        t++;
    }
    return 0;
}
