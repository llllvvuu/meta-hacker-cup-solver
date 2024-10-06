
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

const int MAXN = 10000000;

bitset<MAXN + 1> sieve;

void generate_primes(int N) {
  // Sieve of Eratosthenes to generate all primes <= N.
  sieve.set();
  sieve.reset(0);
  sieve.reset(1);
  for (int i = 2; i <= N; ++i) {
    if (sieve[i]) { // i is prime
      for (int j = i * i; j <= N; j += i) { sieve[j] = false; }
    }
  }
}

int subtractorizations(int N) {
  if (N < 5) {
    return (N + 1) / 2;
  }

  // Count how many valid *$N$-subtractorizations* exist.
  vector<int> primes;
  for (int i = 2; i <= N; ++i) {
    if (sieve[i]) { primes.push_back(i); }
  }

  int count = 0;
  for (int j : primes) {
    for (int i : primes) {
      if (i >= j) break;
      if (sieve[j - i]) { count++; }
    }
  }
  return count / 2 + 1;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": ";
    if (N < 5) {
      cout << (N + 1) / 2 << endl;
      continue;
    }
    generate_primes(N);
    cout << subtractorizations(N) << endl;
  }
}
