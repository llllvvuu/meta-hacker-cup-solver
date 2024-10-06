
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

const int MOD = 998244353;
int inverse_mod(long long a, int mod) {
    a %= mod;
    int g = mod, r = a, x = 0, y = 1;
    while (r) {
        int q = g / r;
        g %= r;
        swap(g,r);
        x -= q * y;
        swap(x,y);
    }
    return x < 0 ? x + mod : x;
}

long long solve(long long w, long long g, long long l, long long p, long long q) {
    if (w == g) return p * inverse_mod(q, MOD) % MOD;
    long long k = w - g < l ? 0 : w - g - l;
    return solve(k, k, 0, (p + k * q), q) + solve(w - k, g, 0, q, q);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L, 0, 1) << "\n";
    }
    return 0;
}
