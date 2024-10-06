
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

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        vector<vector<long long>> E(W - G + 2, vector<long long>(L + 2, -1));
        function<long long(long long, long long)> expected = [&](long long x, long long l) {
            if (x == G || l == 0) return 0;
            if (E[x - G][l] != -1) return E[x - G][l];
            if (x > G) return (x + l - G + expected(x - 1, l)) % MOD;
            E[x - G][l] = (1 + ((expected(x - 1, l) + expected(x + 1, l - 1)) % MOD) / 2) % MOD;
            return E[x - G][l];
        };
        cout << "Case #" << t << ": " << (expected(W, L) * 2 % MOD + MOD) % MOD << endl;
    }
    return 0;
}
