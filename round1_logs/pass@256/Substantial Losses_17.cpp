
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

const long long MOD = 998244353;

long long powmod (long long b, long long e) {
    if (e == 0) return 1;
    long long p = powmod (b, e / 2);
    p = p * p % MOD;
    return ((e % 2) ? (p * b) % MOD : p);
}

long long inv (long long a) { return powmod (a, MOD-2); }

long long solve (long long W, long long G, long long L) {
    long long dW = W - G;
    long long n = dW + (L * (dW <= L));
    long long p = powmod (2, n) - n - 1;
    return (p * inv(powmod (2, dW))) % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        long long W, G, L;
        cin >> W >> G >> L;

        // Calculate result efficiently
        cout << solve(W, G, L) << endl;
    }
    return 0;
}
