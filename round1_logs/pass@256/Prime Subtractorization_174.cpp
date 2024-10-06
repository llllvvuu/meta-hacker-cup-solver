
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
#include <bitset>
#include <iostream>
using namespace std;

const int N = 10000000 + 5;

bitset<N> prime;
bitset<N> potential;

void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) prime[j] = 0;
        }
    }
}

int solve(int n) {
    if (n == 1) return 0;
    int cnt = 0;
    int candidate = 2;
    potential.set();
    // We can always express 2 = q - 3 (mod 2)
    potential[2] = 1;
    for (int i = 3; i <= n; i += 2) {
        if (prime[i]) {
            candidate = i; // Prime to potentially subtract from
            // Take out all odd primes up to candidate that are smaller
            for (int j = 3; j <= candidate; j += 2) {
                if (prime[j]) potential[candidate - j] = 0;
            }
            cnt += potential.count();
            potential[candidate] = 0; // Start fill for next candidate
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    sieve();
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        cout << solve(N) << endl;
    }
}
