
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
using namespace std;
const long long MOD = 998244353;
long long binPow(long long a, long long b, long long mod) {
    long long res = 1; a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
long long W, G, L;
long long inv(long long a) {
    return binPow(a, MOD - 2, MOD);
}
void solve() {
    cin >> W >> G >> L;
    long long exp_days = (W - G) * 2;
    // Account for the buffer L and weight differences
    if(W - L < G) exp_days = (W - G); // If the highest possible weight is already below or at G
    cout << ((2 * (W - G)) * inv(2)) % MOD << endl; // Simplified, assuming uniform distribution
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
