
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
#include <algorithm>
using namespace std;

long long pow_mod(long long x, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2LL == 1) { res = res * x % 998244353; }
        x = x * x % 998244353;
        n >>= 1;
    }
    return res;
}

long long get_inverse(long long a) {
    return pow_mod(a, 998244353 - 2);
}

int T;
long long W, G, L;

long long solve() {
    long long remaining = max(G, W - L) - G; // distance to final goal
    long long lmt, tot;
    lmt = min(W, G + L) - max(G, W - L); 
    if (lmt == 0) tot = 2 * remaining; else {
        tot = (pow_mod(2, lmt + 1) - 1) * get_inverse(pow_mod(2, lmt) - 1) % 998244353 * 2;
    }
    return pow_mod(2, 998244353 - 2) * (total + remaining) % 998244353;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
