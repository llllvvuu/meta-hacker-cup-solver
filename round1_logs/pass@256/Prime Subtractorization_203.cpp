
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
#include <unordered_set>
using namespace std;

// Function to generate all primes up to N using Sieve of Eratosthenes
void generatePrimes(int N, unordered_set<int>& primes) {
    vector<bool> isPrime(N + 1, true);
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.insert(i);
        }
    }
}

// Main function to solve
int countSubtractorizations(int N) {
    unordered_set<int> primes;
    generatePrimes(N, primes);

    unordered_set<int> subtractorizations;
    for (auto it1 = primes.begin(); it1 != primes.end(); ++it1) {
        for (auto it2 = it1; it2 != primes.end(); ++it2) {
            int diff = abs(*it2 - *it1);
            if (diff > 0 && diff <= N) {
                subtractorizations.insert(diff);
            }
        }
    }

    int validSubtractorizations = 0;
    for (auto it = subtractorizations.begin(); it != subtractorizations.end(); ++it) {
        if (primes.find(*it) != primes.end()) {
            validSubtractorizations++;
        }
    }
    return validSubtractorizations;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << countSubtractorizations(N) << endl;
  }
  return 0;
}
