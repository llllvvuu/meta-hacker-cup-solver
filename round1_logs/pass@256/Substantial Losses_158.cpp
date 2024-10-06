
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
constexpr long long MOD = 998244353;
long long powmod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    long long T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long res = powmod(2, W - G, MOD);
        if (W - G <= L)
            res = (res - 1) * powmod(powmod(2, L + 1, MOD) - 2, MOD - 2, MOD) % MOD;
        cout << "Case #" << t << ": " << (res + MOD) % MOD << endl;
    }
    return 0;
}
