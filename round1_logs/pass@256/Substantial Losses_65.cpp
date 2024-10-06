
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
#include <cmath>
using namespace std;

const long long MOD = 998244353;
const long long INV_2 = 499122177;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b = b / 2;
    }
    return res;
}

long long P[200005];

long long dp(long long W, long long G, long long L) {
    long long diff = W - G;
    long long gc = (G + diff - 1) / (L + 1) * (L + 1);
    long long i = min(W, gc);

    if (G >= gc) {
        return (W - G) % MOD;
    }

    P[i] = 0;
    while (i > G) {
        P[i] = (1 + P[min(gc, i + L)] + P[i - 1]) * INV_2 % MOD;
        i--;
    }

    return P[W];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    long long T;
    cin >> T;
    for (long long t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << dp(W, G, L) << endl;
    }
    return 0;
}
