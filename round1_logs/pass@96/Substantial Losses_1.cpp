
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
typedef long long ll;

ll modexp(ll base, ll exp, ll mod) {
    ll result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) result = (result * base) % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

ll solve(ll W, ll G, ll L, ll mod) {
    if(W - G >= L + 1) G = W - (L + 1);
    ll ans = (W + L)*(W + L) - G*G;
    ans = (ans - L - 2) * modexp(2, mod-2, mod) % mod;
    return ans;
}

int main() {
    int T;
    ll W, G, L, mod = 998244353;
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        std::cin >> W >> G >> L;
        std::cout << "Case #" << t << ": " << solve(W, G, L, mod) << "\n";
    }
    return 0;
}
