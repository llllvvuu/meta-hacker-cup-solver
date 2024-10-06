
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

bool sieve[10000001] = {false}; // primes markers
vector<int> primes; // prime numbers

// Sieve of Eratosthenes
void generatePrimes(int N) {
    for (int i = 2; i < N; i++) {
        if (!sieve[i]) { // i is prime
            primes.push_back(i);
            for (int j = i * 2; j < N; j += i) {
                sieve[j] = true; // mark non-primes
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
        generatePrimes(N + 1); // primes up to N

        vector<int> subtractorizations(N + 1, 0); // track primes that can be subtractorizations
        vector<int> prefixSum(N + 2, 0); // prefix sum of subtractorizations

        for (int i = 0; i < primes.size(); i++) {
            for (int j = i; j < primes.size(); j++) { // nested loop - O(prime count squared)
                int diff = primes[j] - primes[i];
                if (diff < 2) break; // valid prime diff must be greater than 1
                if (diff > N) break; // valid prime diff must be <= N
                subtractorizations[diff]++; // count possibility
            }
        }
        for (int i = 1; i <= N; i++) {
            prefixSum[i] = prefixSum[i - 1] + subtractorizations[i]; // generate prefix sum array
        }

        int cnt = 0;
        for (int p : primes) { // count primes which appear in subtractorizations
            if (p <= 2) continue; // valid prime subtractorization must be > 2
            cnt += (prefixSum[N] - prefixSum[p - 1]); // count using prefix sum
        }
        cout << "Case #" << t << ": " << cnt << endl;
    }
    return 0;
}
