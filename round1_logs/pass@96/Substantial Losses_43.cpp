
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
long long mod = 998244353;

long long power(long long a, long long n) {
    return (n == 0) ? 1 : (power((a * a) % mod, n / 2) * ((n % 2) ? a : 1)) % mod;
}

long long invert(long long a) { 
    return power(a, mod - 2); 
}

long long solve(long long W, long long G, long long L) {
    long long maxWeight = W + L;
    long long dp[maxWeight + 2]; // +1 for 0 base and +1 as extra buffer
    dp[G] = 0; // Base case
    for(long long i = G + 1; i <= maxWeight; ++i) {
        dp[i] = (dp[i - 1] + (i - G > L) ? (L + 1 + dp[i - L - 1]) : (i - G + dp[i - 1])) % mod;
        dp[i] = (dp[i] + mod) % mod;
    }
    long long requiredWeight = (dp[maxWeight] - (maxWeight - W >= L ? dp[maxWeight - L - 1] : dp[maxWeight - (maxWeight - W) - 1]) + mod) % mod;
    long long denominator = power(2, W - G > L ? L + 1 : W - G);
    return (requiredWeight * invert(denominator)) % mod;
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << (solve(W, G, L) + mod) % mod << endl; 
    }
    return 0;
}
