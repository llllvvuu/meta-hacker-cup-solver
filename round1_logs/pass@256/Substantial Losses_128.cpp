
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
#define MOD 998244353

using namespace std;

long long comb(long long n, long long k) {
    long long res = 1;
    for (long long i = 1; i <= k; ++i) {
        res = (res * (n - i + 1) % MOD) * (modinv(i, MOD)) % MOD;
    }
    return res;
}

long long modinv(long long a, long long m) {
    long long am = a, nm = 1;
    while (m != 0) {
        long long q = am / m;
        am -= q * m;
        swap(am, m);
        nm -= q * nm;
        if (nm < 0) nm += 998244353;
    }
    return nm;
}

long long solve(long long W, long long G, long long L, long long modinv2L) {
    long long delta = W - G, inv_steps = (L + delta) * modinv2L % MOD;
    return (inv_steps * (min(delta, L) + 1LL) % MOD) * modinv2L % MOD;
}

int main() {
    for (int tc=1,n; cin>>n && n>0; tc++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long modinv2L = modinv(2 * L + 1, MOD);
        cout << "Case #" << tc << ": " << solve(W, G, L, modinv2L) << "\n";
    }
    return 0;
}
