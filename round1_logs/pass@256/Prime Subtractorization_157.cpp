
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

const int MAX_N = 10000001;  // Sufficient for all N up to 10^7

// Sieve of Eratosthenes to generate all primes up to MAX_N.
vector<bool> sieve(MAX_N + 1, true);
vector<int> primes;

void generate_primes() {
    sieve[0] = sieve[1] = false;
    for (int p = 2; p * p <= MAX_N; ++p) {
        if (sieve[p]) {
            for (int i = p * p; i <= MAX_N; i += p) {
                sieve[i] = false;
            }
        }
    }
    for (int p = 2; p <= MAX_N; ++p) {
        if (sieve[p]) primes.push_back(p);
    }
}

bool is_prime(int n) {
    for (int p : primes) {
        if (p >= n) break;
        if (n % p == 0) return false;
    }
    return true;
}

int main() {
    generate_primes();

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        int count = 0;

        // Count $N$-subtractorizations
        for (int p : primes) {
            if (p > N) break;
            if (p >= N) continue;  // Skip too large primes.
            if (is_prime(N - p)) count++;
        }

        cout << count << endl;
    }
    return 0;
}
