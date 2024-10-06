
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

long long mod = 998244353;
long long inv(long long a) {
    long long t = 0, newt = 1, r = mod, newr = a;
    while(newr != 0) {
        long long quotient = r / newr;
        t = t - quotient * newt;
        r = r - quotient * newr;
        swap(t, newt);
        swap(r, newr);
    }
    if (t < 0) t += mod;
    return t;
}

vector<long long> solve(long long W, long long G, long long L) {
    long long bound = G + L;
    vector<long long> E(bound + 1, 0);
    for (long long i = G - 1; i >= G - L && i >= 0 && i < W; i--) {
        E[i] = 1 + (E[i + 1] + E[min(i + 2, bound)]) / 2;
    }
    long long res = E[W];
    if (L == 0) {
        res = inv(W - G);
    }
    return {res, 1};
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        auto ans = solve(W, G, L);
        cout << "Case #" << t << ": " << (ans[0] * inv(ans[1])) % mod << endl;
    }
    return 0;
}
