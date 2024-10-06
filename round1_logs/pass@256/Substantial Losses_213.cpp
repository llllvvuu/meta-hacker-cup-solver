
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

int64_t Mod = 998244353;

// Helper to find mod inverse of a
int64_t inv_mod(int64_t a) {
    int64_t m = Mod, x = 0, y = 1, r, quot, term;
    if (m == 1) return 0;
    while (a > 1) {
        quot = a / m; r = a % m; a = m; m = r;
        term = x; x = y; y = (-quot * y + term) % Mod;
    }
    return x < 0 ? x + Mod : x;
}

// Computes the expected number of days
int compute_days(int64_t W, int64_t G, int64_t L) {
    if (W <= G || L == 0) return W - G;
    int64_t dp[2*L + 2] = {}, N = W - G, P = inv_mod(2); 
    dp[W - G] = 1;
    for (int i = W - G + 1; i <= G + L - G; i++) {
        dp[i] = (1 + (dp[i - 1] + dp[min(W, G + L + 1 - i) - G]) * P) % Mod;
    }
    return (N * P + dp[G + L - G]) % Mod;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int64_t W, G, L; cin >> W >> G >> L;
        cout << "Case #" << t << ": " << compute_days(W, G, L) << endl;
    }
}
