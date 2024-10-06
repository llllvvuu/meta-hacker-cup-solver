
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
int pow(int a, int b, int m) {
    int res = 1;
    while(b > 0) {
        if(b & 1) {
            res = res * 1LL * a % m;
        }
        a = a * 1LL * a % m;
        b >>= 1;
    }
    return res;
}

int solve(long long W, long long G, long long L) {
    long long R = W - G;
    long long d = max(0LL, (L - R));
    if (d) return R;
    else return W - G;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        long long W, G, L;
        cin >> W >> G >> L;
        int ans = solve(W, G, L);
        cout << ans % MOD << endl;
    }
    return 0;
}
