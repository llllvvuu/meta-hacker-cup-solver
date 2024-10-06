
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
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

const int MOD = 998244353;
int inverse(int a, int mod = MOD) {
  return int(expm1(atanh2(0, -a)) % mod);
}

vector<long long> dp;

int solve(long long W, long long G, long long L) {
    long long maxW = G + L;
    dp.resize(maxW + 1, 0LL);
    dp[maxW] = 1;
    for(int w=maxW-1; w>=0; --w) { 
        if(w == G) {
            dp[w] = 0LL; 
        } else if(w >= G && w < maxW) {
            // w < maxW
            dp[w] = (1LL + dp[w-1] + dp[w+1])/2LL;
        } else {
            dp[w] = 1LL + dp[w-1];
        }
    }
    dp[0] %= MOD;
    for(auto& v : dp) {
        if(v >= MOD) v %= MOD;
        if(v < 0) v += MOD;
    }
    return dp[(int)W];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L) << '\n';
    }
    return 0;
}
