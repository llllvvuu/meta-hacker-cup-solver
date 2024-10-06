
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
#include <array>
#include <iostream>
#include <vector>
using namespace std;

void sieve(bool* primes, int N) {
    fill(begin(primes), end(primes), true);
    primes[0] = primes[1] = false;
    for (int p = 2; p * p < N; p++) {
        if (primes[p]) {
                for (int candidate = p * p; candidate < N; candidate += p) {
                    primes[candidate] = false;
                }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        array<int, 2> dp = {0, 1}; // 0 and 1 not prime

        bool is_prime[N + 1];
        sieve(is_prime, N + 1);
        for (int p_j = 2; p_j <= N; p_j++) {
            if (is_prime[p_j]) {
                for (int p_i = p_j; p_i <= N; p_i += p_j) {
                dp[0] += is_prime[p_i] && (p_i - p_j > 0 && is_prime[p_i - p_j] || p_j - p_i > 0 && is_prime[p_j - p_i]);
                }
                dp[0] /= 2; // over double counted for duplicates
            }
            dp[1] = dp[0];
        }
        cout << "Case #" << t << ": " << dp[1];
    }
}
