
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

const int MOD = 998244353;

long long powmod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    long long W, G, L;
    for (int i = 1; i <= T; ++i) {
        cin >> W >> G >> L;
        if (W <= G + L) {
            cout << "Case #" << i << ": " << 0 << endl;
            continue;
        }
        cout << "Case #" << i << ": " << (long long)(G - W + L + 1 + (G - W + L + 1) * powmod(2, -1 + 2 * (L + 1) - 2 * (G - W + L + 1))) % MOD << endl;
    }
    return 0;
}
