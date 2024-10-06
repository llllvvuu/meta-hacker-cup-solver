
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

long long w, g, l;
vector<long long> dp;

long long compute(long long w){
    // Base cases
    if (w == g || w >= g + l + 1) return 0;
    if (dp[w] == -1){
        dp[w] = (w - g + 1 + compute(w - 1) + compute(w + 1)) % MOD;
    }
    return dp[w];
}

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        cin >> w >> g >> l;
        dp = vector<long long>(w + 1, -1);
        long long ans = compute(w);
        long long inv2 = 499122177; // 2^-1 mod 998244353
        ans = (ans * inv2) % MOD;
        cout << ans << endl;
    }
    return 0;
}
