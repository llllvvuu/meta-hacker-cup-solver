
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

const int MOD = 998244353; // given modulus

// Compute the modular inverse using Fermat's little theorem
int modInverse(int a, int p) {
    int res = 1;
    int power = p - 2;
    while (power) {
        if (power & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        power >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long W, G, L;
        cin >> W >> G;
        cin >> L;
        
        // Calculate the recurrence relation to find X[W]
        long long days = 2 * L - 1 + G - W;
        if(W - G > L)
            days += 2 * (W - G - L - 1);
        
        // The answer is days * 2^{-1} mod MOD
        int answer = (days * modInverse(2, MOD)) % MOD;
        
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}
