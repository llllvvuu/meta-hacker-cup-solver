
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

const int MAXN = 10000100;
bool sieve[MAXN]; // Sieve for marking non-prime numbers
vector<int> primes; // Stores primes

void generatePrimes(int n) {
  fill(sieve, sieve + n, true);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i < n; ++i) {
    if (sieve[i]) {
      primes.push_back(i);
      for (int j = i * 2; j < n; j += i) {
        sieve[j] = false;
      }
    }
  }
}

vector<int> subtractorizationCounts; // Stores count for each N

void precomputeSubtractorizations() {
  generatePrimes(MAXN);
  subtractorizationCounts.resize(MAXN, 0);
  for (auto p : primes) {
    for (auto q : primes) {
      int diff = p - q;
      if (q >= p) break; // Since we only need one direction of difference
      if (diff < 2) continue; // diff must be greater than 1 and a prime
      if (sieve[diff]) {
        subtractorizationCounts[p]++;
      }
    }
  }
  // Normalize counts, ignoring negatives and 2 for simplicity
  for (int i = 2; i < MAXN; i++) {
    subtractorizationCounts[i] += subtractorizationCounts[i - 1];
  }
}

int main() {
  int T;
  cin >> T;
  precomputeSubtractorizations();
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << subtractorizationCounts[N] - subtractorizationCounts[2] << endl;
  }
  return 0;
}
