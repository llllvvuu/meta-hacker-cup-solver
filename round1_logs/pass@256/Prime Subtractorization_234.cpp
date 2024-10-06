
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
#include <array>
using namespace std;

bool isPrime[10000007] = {false};

void sieve(int N) {
  fill_n(isPrime, N + 1, true);
  int lim = sqrt(N);
  for (int i = 2; i <= lim; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= N; j += i)
        isPrime[j] = false;
    }
  }
  // Not marking isPrime[1] is intended to mark 1 as non-prime
}

vector<int> generatePrimes(int N) {
  vector<int> primes;
  for (int i = 2; i <= N; ++i) if (isPrime[i]) primes.push_back(i);
  return primes;
}

int countNSubtractorizations(int N) {
  sieve(N);
  int primeCount = 0;
  vector<int> primes = generatePrimes(N);

  int diffCounter[20000000] = {};
  for (int i = 0; i < primes.size(); ++i)
    for (int j = i + 1; j < primes.size(); ++j) 
      // Primes can only differ by a natural number >= 2, checks if natural number.
      if (primes[j] - primes[i] < 20000000 && ((primes[j] - primes[i] == 2 && i == 0) || i > 0)) 
        diffCounter[primes[j] - primes[i]]++;
  
  for (int i = 2; i < 20000000; ++i)
    if (isPrime[i]) primeCount += diffCounter[i];

  return primeCount;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << countNSubtractorizations(N) << endl;
  }
  return 0;
}
