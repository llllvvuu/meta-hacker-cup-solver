
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

const int mod = 998244353;

long long e[100005];
long long solve(long long w, long long g, long long l) { // assumes w > g and w < w + l
    if (e[w - g] != -1) return e[w - g];
    if (w == g + 1) return e[w - g] = 1;
    return e[w - g] = (2 * solve(w - 2, g, l) - solve(w - 3, g, l) - 2 + mod + 2 * (w - g)) % mod;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long l = min(W - G, L); // l' <= W - G
        vector<long long> e1(l + 1, -1); // clear for memoization
        e1[0] = 0; // base case
        if (W <= G) {
            cout << "Case #" << t << ": 0" << endl;
        } else if (W <= G + l) {
            cout << "Case #" << t << ': ' << (solve(W - 1, G, l - 1) + mod - 1) % mod << endl;
        } else {
            cout << "Case #" << t << ': ' << (W + mod - G - l) % mod << endl;
        }
    }
    return 0;
}
