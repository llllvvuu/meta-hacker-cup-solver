
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

long long inv(long long a, long long mod) {
    return a < 2 ? a : mod - mod / a * inv(mod % a, mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long mod = 998244353, inv2 = 499122177, T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long diff = max((W - L - G), 0LL), ans = (2 * diff + 1) * inv2 % mod;
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
