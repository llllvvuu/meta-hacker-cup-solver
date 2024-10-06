
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
#include <algorithm>
using namespace std;

const int mod = 998244353;

int pw(long long n, int k) {
    int res = 1, p = n;
    while (k) {
        if (k % 2) res = (res * p) % mod;
        p = (p * p) % mod;
        k /= 2;
    }
    return res;
}

int solve(long long w, long long g, long long L) {
    if (w == g + 1 + L) return 0;
    vector<int> dp(w - g + 1);
    dp[0] = 0;
    long long sum = 0;
    for (int i = 0; i <= L; i++) {
        dp[i+1] = (1LL + 2*sum + i - g + w) % mod;
        sum += dp[i+1];
        sum %= mod;
    }
    long long p = 0;
    for (int i = 1; i <= L; i++) p = (p + dp[i]) % mod;
    return pw(p, mod-2);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long w, g, L;
        cin >> w >> g >> L;
        cout << "Case #" << t << ": " << solve(w, g, L) << endl;
    }
    return 0;
}
