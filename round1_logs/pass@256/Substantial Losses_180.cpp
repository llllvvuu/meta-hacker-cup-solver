
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

int64_t mod = 998244353; // modulo value

int64_t exp(int64_t a, int64_t b) { // Calculate a^b % mod
    int64_t res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int64_t inv(int64_t a) { // Calculate multiplicative inverse a^-1 % mod
    return exp(a, mod - 2);
}

int64_t calc(int64_t w, int64_t g, int64_t L) {
    if (w == g) return 0; // if you are already at the goal, no more days required
    if (w + L <= g) return (w - g); // If you can't go above g

    int64_t n = w - g;
    return (2 * n % mod - 1 + mod) % mod * inv(3) % mod; // expected value equation
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int64_t W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << calc(W, G, L) << endl;
    }
    return 0;
}
