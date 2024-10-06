
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

const int mod = 998244353;
const long long lg = 1000 * 1000 * 1000;

int t;
long long w, g, l;

// Fast exponentiation for modular powers
long long modpow(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

// Find modular inverse using Fermat's little theorem
long long invmod(long long x) {
    return modpow(x, mod - 2);
}

int main() {
    cin >> t;
    for(int cas = 1; cas <= t; cas++) {
        cin >> w >> g >> l;
        if (g + l < w) {
            cout << "Case #" << cas << ": " << 0 << endl;
            continue;
        }
        if (w - (l + g) <= 0) {
            cout << "Case #" << cas << ": " << w - g << endl;
            continue;
        }
        vector<long long> dev(l + (w - g) + 2);
        dev[l + g - g] = 0, dev[l + g - g + 1] = 1;
        for(long long i = l + g - g + 1; i < (l + (w - g)); i++) {
            dev[i + 1] = (2 * dev[i] + 1 - dev[i - 1]) % mod;
            if (dev[i + 1] < 0) dev[i + 1] += mod;
        }
        long long mul = (w - g - l - 1);
        long long res = invmod(2) * (dev[mul + l + (w - g)] - dev[mul + l + (w - g) - 1]);
        cout << "Case #" << cas << ": " << (res % mod)  << endl;
    }
    return 0;
}
