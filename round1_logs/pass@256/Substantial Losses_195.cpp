
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
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

const int MOD = 998244353;

int rec(int d, int g, int l) {
    if (d <= l) return d * g;
    if (l + g <= d) return g * ((l + 1) * g % MOD + d) % MOD;
    
    vector<int> a([](int x) {return x;}, g + 1), b({g == 0});
    for (int i = 1; i < g + 1; i++) {
        b.push_back((b.back() + a[g - i] * 2 % MOD) % MOD);
        a.push_back((a.back() + MOD - b.back()) % MOD);
    }
    return ((b.back() - b[g]) + a[g]) % MOD * pow2(g + 1, MOD - 2);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int W, G, L;
        scanf("%d%d%d", &W, &G, &L);
        int d = W - G;
        printf("Case #%d: %d\n", t, rec(d, min(d, L + 1), L));
    }
    return 0;
}
