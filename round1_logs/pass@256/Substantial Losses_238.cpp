
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
#include <cassert>
#include <iostream>
using namespace std;

const int MOD = 998244353;

// Function to calculate (base^exponent) modulo MOD using
// Fast exponentiation
long long fast_power(long long base, long long exponent) {
    long long result = 1;
    base %= MOD;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}

// Extended Euclidean Algorithm to find multiplicative inverse
long long mod_inverse(long long a) {
    return fast_power(a, MOD - 2);
}

// Main logic to calculate expected number of days
long long solve(long long w, long long g, long long l) {
    if (w <= g) return 0;
    if (w - g <= l) return g - w;
    long long diff = w - g;
    long long days = (diff * mod_inverse(diff - l)) % MOD;
    return days;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long long w, g, l;
        cin >> w >> g >> l;
        long long result = solve(w, g, l);
        cout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}
