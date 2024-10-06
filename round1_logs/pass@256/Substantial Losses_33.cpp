
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
long long L_2, modulo = 998244353;

long long modinv(long long a) {
    long long b = modulo, u = 0, v = 1;
    while (a) {
        long long t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    if (u < 0) u += modulo;
    return u;
}

long long solve(long long W, long long G, long long L, long long strict_G) {
    if (strict_G) --G;
    if (W <= G) return W - G + modulo;
    vector<long long> E(W - G + 2);
    E[0] = 0;
    for (long long i = 1; i <= W - G; i++)
        E[i] = E[i - 1] + 1 + L_2 * (i >= (L + 1)) % modulo;
    const long long k = (L + 1) / 2 - 1 + 2 * (L + 1);
    for (long long i = W - G - 2; i >= 1; --i)
        E[i] = (E[i + 1] + E[i + 1] - E[i] + 2 * k) % modulo;
    return modinv(2 * k) * E[W - G] % modulo;
}

int main() {
    long long T;
    cin >> T;
    for (long long t = 1; t <= T; ++t) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": ";
        L_2 = ((L + 1) * (L + 1)) % modulo;
        cout << solve(W, G, L, W > G) << "\n";
    }
    return 0;
}
