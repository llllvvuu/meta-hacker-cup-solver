
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

long long inverse(long long a, long long M) {
    long long r1 = a, r2 = M, t1 = 0, t2 = 1;
    while (r2 > 0) {
        long long q = r1 / r2;
        long long r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        long long t = t1 + q * t2;
        t1 = t2;
        t2 = t;
    }
    if (r1 > 1) return -1; // In case there is no inverse
    if (r1 == 0) return 0; // a is a multiple of M, no inverse
    return (t1 % M + M) % M; // Ensure the result is positive
}

int main() {
    long long T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long diff = W - G, max_height = W + L;
        long long days = (2 * diff + max_height - G - 1) / 2;
        long long mod = 998244353;
        long long inv2 = inverse(2, mod);
        long long expected_days = (days * inv2) % mod;
        cout << "Case #" << t << ": " << expected_days << endl;
    }
    return 0;
}
