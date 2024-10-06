
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
#include <cstdio>
using namespace std;

const int MAX_N = 10000001; // Constraint provided by the problem + buffer
vector<int> primes;

// Sieve of Eratosthenes to find all primes under MAX_N
void sieve() {
    vector<bool> isPrime(MAX_N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j <= MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    sieve(); // Precompute all primes

    int hasValues[MAX_N + 1];
    for (int i = 0; i <= MAX_N; i++) {
        hasValues[i] = -1; // Initialize with -1 to indicate no data computed
    }

    for (int N : primes) {
        for (int p1 : primes) {
            if (p1 >= N) break; // No need to check further, as p1 should be less than N
            int p2 = N - p1;
            if (primes.end() != lower_bound(primes.begin(), primes.end(), p2)) { // Check if p2 is a prime
                int result = p2 - p1;
                if (result >= 1 && result <= MAX_N) hasValues[result]++; // Counting only within allowed range and incrementing
            }
        }
    }
    
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << hasValues[N] << "\n";
    }
    return 0;
}
