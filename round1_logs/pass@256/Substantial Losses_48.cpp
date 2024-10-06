
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

const int MOD = 998244353;

// Function to calculate modular inverse using Fermat's Little Theorem
int modinv(int a) {
    return power(a, MOD - 2, MOD);
}

// Function to calculate (a^b) mod m
int power(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long max_possible_weight = G + L;
        long long expected_days = (1LL << (max_possible_weight - G)) % MOD;
        long long numerator = (expected_days + max_possible_weight - W) % MOD;
        long long denominator = (expected_days - max_possible_weight + G) % MOD;
        long long result = (numerator * modinv(denominator)) % MOD;
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
