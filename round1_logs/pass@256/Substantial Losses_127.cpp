
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
using namespace std;

const int MOD = 998244353;

int fast_pow(long long x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

int mod_inv(long long x) {
    return fast_pow(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long diff = max(W - G, 0LL);
        long long step = 1, days = 0;
        
        if (L == 0) cout << "Case #" << t << ": " << diff << '\n';
        else {
            while (diff > 0) {
                if (diff < step) {
                    step = fast_pow(2, L) - 1;
                    days = (days + step * fast_pow(2, step)) % MOD;
                    diff = 0;
                } else {
                    days = (days + (step * (2 * step + 1)) / 2) % MOD;
                    diff -= step;
                    step = step * 2;
                }
            }
            cout << "Case #" << t << ": " << days * mod_inv(step) % MOD << '\n';
        }
    }
    return 0;
}
