
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
#include <unordered_map>
using namespace std;

const int MOD = 998244353;
typedef long long ll;

// Compute modular inverse using Fermat's little theorem
int modInverse(int a) {
    return pow(a, MOD-2, MOD);
}
unordered_map<ll, int> dp;

// Return expected number of days to reach G from weight w
int dfs(ll w, ll G, ll L) {
    if (w <= G) return 0;
    if (w - G <= L) return (int)(w - G);
    auto it = dp.find(w);
    if (it != dp.end()) return it->second;
    ll maxAllowed = min(w + L, w + 1);
    int res = (dfs(w-1, G, L) + dfs(maxAllowed-1, G, L) + 2) / 2;
    dp[w] = res;
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        dp.clear();
        int p = dfs(W, G, L);
        int q = 1; // always 1 because above steps simplify single recursion without denominator
        int result = (p * modInverse(q)) % MOD;
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
