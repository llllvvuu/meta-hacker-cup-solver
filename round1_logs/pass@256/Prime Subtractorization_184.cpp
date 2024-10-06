
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
#include <set>
#include <iostream>
using namespace std;

// function to implement Sieve of Eratosthenes and mark primes less than N
void sieve(int n, set<int>& primes) {
  bool is_prime[n + 1];
  fill(begin(is_prime), end(is_prime), true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.insert(i);
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
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
    set<int> primes;
    sieve(N, primes); // generate primes
    int subtractorizations = 0;
    for (auto it1 = next(primes.begin()); it1 != primes.end(); ++it1) {
      int diff = *it1 - *primes.begin();
      if (primes.find(diff) != primes.end()) subtractorizations++;
    }
    cout << "Case #" << t << ": " << subtractorizations << endl;
  }
  // optimization approach keeps the performance, around each test case pre-generation of primes.
  return 0;
}
