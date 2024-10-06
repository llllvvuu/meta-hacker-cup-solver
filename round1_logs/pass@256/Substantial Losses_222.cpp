
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

long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

long long mod_inv(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long diff = W - G;
        long long p = mod_pow(2, diff, MOD);
        p = (p - (G - W + 1 + MOD)) % MOD;
        long long q = mod_pow(2, L + 1, MOD);
        cout << "Case #" << i << ": " << p * mod_inv(q, MOD) % MOD << endl;
    }
    return 0;
}
