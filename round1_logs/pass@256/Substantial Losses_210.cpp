
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
long long pow(long long a, long long exponent) {
    long long ans = 1;
    while (exponent) {
        if (exponent & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        exponent >>= 1;
    }
    return ans;
}

long long inverse(long long a) {
    return pow(a, mod - 2);
}

long long solve(long long w, long long g, long long l, long long mem[100][100][100][100]) {
    if (w < g)
        return 0;
    if (mem[w % 55][g % 55][l % 55][(w - g) % 55] >= 0)
        return mem[w % 55][g % 55][l % 55][(w - g) % 55];
    long long ans1, ans2;
    if (w - l <= g) // If upper limit L is 0, eventually we will drift down to G.
        ans1 = (w - g); // Only one way to go is downwards, so the days are exactly the difference.
    else // Otherwise the answer is the average of increased and decreased answers + 1.
        ans1 = (solve(w - 1, g, l, mem) + 1 + mod) / 2;
    if (w - l <= g - 1)
        ans2 = INF; // The maximum possible days occurs when there is an adjacent limit at G-1
    else
        ans2 = (solve(w - 1, g - 1, l - 1, mem) + 1 + mod) / 2;
    // mem matrix stores computed values to avoid recalculation.
    return mem[w % 55][g % 55][l % 55][(w - g) % 55] = min(ans1, ans2);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        long long mem[55][55][55][55];
        for (int i = 0; i < 55; i++)
            for (int j = 0; j < 55; j++)
                for (int k = 0; k < 55; k++)
                    for (int h = 0; h < 55; h++)
                        mem[i][j][k][h] = -1;
        long long answer = solve(W, G, L, mem);
        std::cout << "Case #" << t << ": " << answer * inverse(2) % mod << "\n";
    }
    return 0;
}
