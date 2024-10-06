
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

// Sieve of Eratosthenes to mark all non-prime numbers
vector<bool> primes; // can assume primes[i] == true => i is prime
void sieve(long limit) {
  primes.assign(limit + 1, true);
  primes[0] = primes[1] = false;
  for (long i = 2; i * i <= limit; ++i) {
    if (primes[i]) {
      for (long j = i * i; j <= limit; j += i) {
        primes[j] = false;
      }
    }
  }
}

// Check how many primes k are "prime-subtractorization" of a number n
long subtractorizations(long n) {
  sieve(n);
  long resize = 2 * n - 1, count = 0;
  for (long i = 2; i <= n; ++i) {
    if (!primes[i]) continue;
    for (int j = 2; j < i; ++j) {
      if (primes[j] && primes[i - j]) ++count;
    }
  }
  return count;
}

int main() {
  long T;
  cin >> T;
  for (long t = 1; t <= T; ++t) {
    long N;
    cin >> N;
    cout << "Case #" << t << ": " << subtractorizations(N) << endl;
  }
  return 0;
}
