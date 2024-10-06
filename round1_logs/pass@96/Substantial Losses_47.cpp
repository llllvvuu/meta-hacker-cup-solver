
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

long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

long long sum(long long n) {
    return (n * (n + 1)) / 2;
}

long long solve(long long W, long long G, long long L) {
    long long term_2 = (W - L - G) * (W - L - G);
    long long term_3 = (L * L) * modInverse(sum(L), 998244353);
    long long ans = (term_2 + term_3) % 998244353;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; i++) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << i << ": " << solve(W, G, L) << "\n";
    }
    return 0;
}
