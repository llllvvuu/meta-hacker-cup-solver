
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
#include <unordered_set>
using namespace std;

constexpr int MAX_N = 10000001; // Upperbound to find primes up to

vector<bool> sieve;  

// Precompute primes using Sieve of Eratosthenes
void preprocess() {
  sieve.resize(MAX_N, true);
  sieve[0] = sieve[1] = false;
  for (int p = 2; p * p < MAX_N; p++) {
    if (sieve[p]) {
      for (int k = p * p; k < MAX_N; k += p) {
        sieve[k] = false;
      }
    }
  }
}

unordered_set<int> primes_up_to(int N) {
  vector<int> primes;
  unordered_set<int> diffs;
  for (int p = 2; p <= MAX_N; p++) {
    if (sieve[p]) {
      bool added = false;
      for (int prev : primes) {
        int prime_diff = p - prev;
        if (prime_diff > N || !sieve[prime_diff]) continue;
        diffs.insert(prime_diff);
        if (!added) primes.push_back(p); 
        added = true;
      }
      if (!added) {
        if (p - 2 <= N) diffs.insert(2);
        primes.push_back(p);
      }
    }
  }
  return diffs;
}

int main() {
  int T;
  cin >> T;
  preprocess();
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << primes_up_to(N).size() << endl;
  }
  return 0;
}
