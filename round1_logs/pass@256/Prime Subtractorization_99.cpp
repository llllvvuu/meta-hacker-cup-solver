
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
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> primes;

// Generates all prime numbers up to sqrt(N) and uses it to determine primes up to N
vector<int> sieve(int maxN) {
    vector<bool> isPrime(maxN+1, true);
    vector<int> primes;
    isPrime[1] = false;
    for (int i = 2; i*i <= maxN; ++i) {
        if (isPrime[i]) {
            for (int j = i*i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= maxN; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int count_N_subtractorizations(int N) {
    primes = sieve(N);
    int count = 0;

    for (int p : primes) {
        if (p <= N) {
            for (int q : primes) {
                if (q <= p) {
                    if (p - q > 1 and binary_search(primes.begin(), primes.end(), p - q)) {
                        count++;
                    }
                }
            }
        }
    }
    
    if (binary_search(primes.begin(), primes.end(), 2)) {
        for (int p : primes) {
            if (p <= N and p - 2 > 1 and binary_search(primes.begin(), primes.end(), p - 2)) {
                count--;
            }
        }
    }
    
    return count / 2 + binary_search(primes.begin(), primes.end(), 2) + 1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        cout << "Case #" << t << ": " << count_N_subtractorizations(N) << endl;
    }
    return 0;
}
