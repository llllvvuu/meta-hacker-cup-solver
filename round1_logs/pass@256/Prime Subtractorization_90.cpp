
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
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 10000000;
bool is_prime[MAXN + 1] = {};

// Sieve of Eratosthenes
void generate_primes() {
  fill(is_prime, is_prime + MAXN + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= MAXN; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

vector<int> primes;

// Collect all primes up to N into vector primes
void collect_primes(int N) {
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int main() {
  generate_primes();  // Generate prime flags up to MAXN
  
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    collect_primes(N);  // Collect all primes up to N
    set<int> maxPrimes(primes.begin(), primes.end()); // Set for efficient lookup
    int subtractorization_count = 0;

    // Check each prime if it's a subtractorization
    for (int p : primes) {
      for (int q : primes) {
        int diff = q - p;
        if (diff == p && maxPrimes.find(q) != maxPrimes.end()) {
          subtractorization_count++;
          break; // Check next prime
        }
      }
    }
    
    cout << "Case #" << t << ": " << subtractorization_count / 2 << endl; // Each pair is counted twice
  }
  
  return 0;
}
