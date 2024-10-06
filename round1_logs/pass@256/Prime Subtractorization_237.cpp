
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

static constexpr int MAX_SIZE = 10000;

bitset<MAX_SIZE> is_prime;
vector<int> primes;

void sieve() {
  is_prime.set();
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < MAX_SIZE; i++) {
    if (is_prime[i]) {
      for (int j = i*i; j < MAX_SIZE; j += i) {
        is_prime[j] = false;
      }
      primes.push_back(i);
    }
  }
}

int main() {
  sieve();
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    int ans = 0;

    ans = 0;
    int L = 0, R = 0;
    if (primes.size()) {
      R = min(primes.back(), N/2);
      while (L < primes.size() && primes[L] <= min(R, (long long)N)) {
        L = R;
        while (L > 0) {
          --L;
          if (primes[R] - primes[L] <= N) {
            break;
          }
        }
        ans += R - L;
        ++R;
      }
    }

    if (L == 0) ++ans;

    // Check manually for primes larger than sqrt(n)
    vector<int> largePrimes;
    for (int i = primeUpperBound(); i <= N; ++i) {
      if (isPrime(i)) {
        largePrimes.push_back(i);
      }
    }
    for (int i : largePrimes) {
      for (int j : largePrimes) {
        if (i != j && abs(i - j) <= N) {
          ++ans;
        }
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
