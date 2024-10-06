
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

const long long mod = 998244353;

long long inv(long long a) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    return u < 0 ? u + mod : u;
}

int T; long long W, G, L;

long long solve(long long x, long long g, long long l) {
    if(x <= g) return x - g;
    long long y = min(x + l, g + l);
    if(x == y) return g - y + 1;
    return solve(x - 1, g, l) + inv(1 - inv(2));
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> W >> G >> L;
        long long ans = solve(W, G, L);
        cout << "Case #" << t << ": " << (ans % mod + mod) % mod << endl;
    }
    return 0;
}

