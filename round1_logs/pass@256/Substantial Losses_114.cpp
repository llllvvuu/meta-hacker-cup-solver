
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

#define MOD 998244353
const long long inverse2 = 499122177; // 2^-1 mod MOD

long long solve(long long W, long long G, long long L) {
    long long max_weight = max(W - L, G);
    return (2 * (W - max_weight)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long expected_days = solve(W, G, L);
        cout << "Case #" << i << ": " << (expected_days * inverse2) % MOD << "\n";
    }
    return 0;
}
