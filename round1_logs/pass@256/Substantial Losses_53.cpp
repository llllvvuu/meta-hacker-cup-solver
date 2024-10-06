
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

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long modInv(long long n) { // using Fermat's Little Theorem
    return power(n, MOD - 2);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long difference = W - G;
        long long days;

        // Case when no hitting the cap, simple linear decrease
        if (difference <= L) {
            days = difference * 2;
        } else {
            difference -= L;
            days = (difference * (difference + 1)) % MOD; // sum of differences reduced
            days = (days * modInv(2)) % MOD; // inverse of 2
            days = (days + (power(2, difference) - 1 + MOD) % MOD * modInv(power(2, difference) - 1 + MOD) % MOD) % MOD; // account for bottleneck effect
            days = (days * (L * 2 + 1)) % MOD; // capped paths
        }

        cout << "Case #" << t << ": " << days << endl;
    }
    return 0;
}
