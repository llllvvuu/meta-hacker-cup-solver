
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

constexpr int MOD = 998244353;

int inverse(int a) {
    return a == 1 ? a : int((((long long)MOD - MOD / a) * inverse(MOD % a)) % MOD);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long W, G, L;
        cin >> W >> G >> L;

        long long K = W - G - 1;
        long long M = G - 1;
        long long D = (W - G) * (L + 1) - 1;

        if (K <= M) {
            cout << "Case #" << T + 1 << ": " << 1 << endl;
        } else {
            // compute modulus efficiently to fit the problem requirements
            long long p = K - M, q = 1;
            p = (p * inverse(2)) % MOD;

            cout << "Case #" << T + 1 << ": " << p * inverse(q) % MOD << endl;
        }
    }
    return 0;
}
