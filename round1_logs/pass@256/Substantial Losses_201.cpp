
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
#include <cmath>
using namespace std;

const int MOD = 998244353;
int inv[32];  // To store (2^i)^{-1} mod MOD

// Precomputation for modular inverses
void precompute() {
    inv[0] = 1;
    for (int i = 1; i < 32; i++) {
        inv[i] = (long long)inv[i - 1] * (MOD + 1) / 2 % MOD; // (2^i)^{-1} = (2^(i-1))^{-1} * 4^{-1}
    }
}

int gen(int g, int w, int L) {
    int ans = (w - g);  // Immediate expected steps
    int low = max(w - L, g);
    long long sum = 0;
    for (int i = 31; i >= 0; i--) {
        if (((w - low) / (1LL << i)) & 1) {  // Detect bit between low and w
            long long j = 1LL << i;
            int jj = j / 2;
            int add = ((w - low) / j) * (jj - 1) * inv[i];
            ans = (ans + add) % MOD;
            sum += (1LL << (2 * i)) * inv[i]; // Sum of (2k)^{-2} terms
        }
    }
    int fin = (sum * (sum + 2) / 2) % MOD;  // Sum inversion
    return (ans + fin) % MOD;
}

int main() {
    precompute();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        int ans = gen(G, W, L);
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}
