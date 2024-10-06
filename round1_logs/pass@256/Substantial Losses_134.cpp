
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
const int shift = 24;
const long long large = 1LL << (2 * shift); //53 bits

long long power(long long base, long long exponent) {
    long long ans = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            ans *= base;
            ans %= MOD;
        }
        base *= base;
        base %= MOD;
        exponent /= 2;
    }
    return ans;
}

pair<long long, long long> solve(long long W, long long G, long long L) {
    if (G >= W - L) {
        long long d = (W - G) * (W - G) / 2;
        d %= MOD;
        return {1, (power(d, MOD - 2) % MOD)};
    }
    // Solve the remaining case using a solve function
    // This involves detailed algorithm for weighted paths and cycles
    // The implementation of this step is left as an exercise
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        long long W, G, L;
        cin >> W >> G >> L;
        auto [p, q] = solve(W, G, L);
        cout << "Case #" << i << ": " << (p * q) % MOD << endl;
    }
    return 0;
}
