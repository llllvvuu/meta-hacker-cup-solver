
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

const long mod = 998244353;

// Extended Euclidean Algorithm to find multiplicative inverse
long modInvert(long a, long n) {
    long t = 0, newt = 1;
    long r = n, newr = a;
    while (newr != 0) {
        long q = r / newr;
        t -= newt * q;
        swap(t, newt);
        r -= newr * q;
        swap(r, newr);
    }
    if (r > 1) return -1;  // n is not invertible
    if (t < 0) t += n;
    return t;
}

long solve(long W, long G, long L) {
    if (G >= W || W > (G + L)) return -1; // if target is unreachable
    
    long term1 = G - W + L + 1;
    long term2 = 2 * (W - G) * (W - G);
    long term3 = (W - G) * (W - G) + term1;

    long q = term1;
    long p = term3;
    long res = (p * modInvert(q, mod)) % mod;
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L) << endl;
    }
    return 0;
}
