
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

// Pratt's Main Function
int main() {
    int T; cin >> T;

    for(int t = 1; t <= T; ++t) {
        long long W, G, L; cin >> W >> G >> L;
        
        long long lower, higher;
        // Case to get bounds
        if(W - L <= G)
            lower = W - L;
        else
            lower = G;
        higher = W;

        // Base Case Reaches G
        if(W == G) {
            cout << "Case #" << t << ": 0" << endl;
            continue;
        }

        // Standard DP Array for Expected Days computations
        vector<long long> dp(G - lower + 1, 0);

        if(lower < G) {
            dp[G - lower] = 0;
            for(int i = G - lower - 1; i >= 0; i--) {
                dp[i] = (2 * (i + 1 + dp[i + 1]) - 1 + 
                        (i + 1 >= 2*(G - lower)? 0: dp[i + 2]))%998244353;
            }
        }

        if((W - G <= L)) {
            cout << "Case #" << t << ": " << (dp[0] + 998244353) % 998244353 << endl;
            continue;
        }

        long long val = 1;
        for(int i = (L + G - lower); i > 0; i--)
            val = (val * 2) % 998244353;

        // Finding Modular Inverse
        long long x, y, gcd = extended_gcd(val, 998244353, x, y);
        if(gcd == 1)
            x = (x + 998244353) % 998244353;
        
        dp[0] = (dp[0]* x) % 998244353;
        cout << "Case #" << t << ": " << (dp[0] + 998244353)%998244353 << endl;
  }
  return 0;
}

long long extended_gcd(long long a, long long b, long long& x, long long& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
