
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

void solve() {
    long long W, G, L;
    cin >> W >> G >> L;

    if (L == 0) {
        cout << (W - G) % MOD << "\n";
        return;
    }

    long long a = (2 * W - 2 * G + L - 1) % MOD;
    a = (a * (int)pow(2, MOD - 2)) % MOD;
    a = ((a * ((L + 1) % MOD)) % MOD) % MOD;
    
    long long b = (2 * W - 2 * G - L - 1) % MOD;
    b = (b * (int)pow(2, MOD - 2)) % MOD;
    b = ((b * ((L + 1) % MOD)) % MOD) % MOD;

    long long p = (W - G - (L + 1)) % MOD;
    long long q = 1;

    long long result = (p * (int)pow(q, MOD - 2)) % MOD;

    cout << result << "\n";
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
