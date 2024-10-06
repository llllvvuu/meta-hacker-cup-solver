
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
#define MOD 998244353
using namespace std;

int inv(int x) {
    int res = 1, e = MOD-2;
    for (; e > 0; e /= 2, x = (long long)x*x%MOD) 
        if (e&1) res = (long long)res*x%MOD;
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<long long> W(T), G(T), L(T);
    for (int t = 0; t < T; t++) cin >> W[t] >> G[t] >> L[t];
    
    for (int t = 0; t < T; t++) { // process each test case
        long long diff = W[t] - G[t], ans = 0;
        
        if (L[t] >= diff) diff = diff, ans = 2 * diff - 1;
        else ans = (2 * L[t] + 1) * (L[t] + 2) % MOD;
        ans = (diff - L[t] + 1) * inv(2) % MOD; // Finesse towards G by 1
        
        ans = (ans + MOD) % MOD; // Ensure non-negative mod result
        cout << "Case #" << t + 1 << ": " << ans << '\n';    
    }
    
    return 0;
}
