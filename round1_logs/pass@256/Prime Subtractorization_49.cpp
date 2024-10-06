
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
#include <algorithm>
#include <cmath>
using namespace std;

void sieve(int N, vector<bool> &isPrime) {
  isPrime[0] = isPrime[1] = false;
  isPrime[2] = true;
  for (int i = 3; i <= N; i += 2) isPrime[i] = true;
  for (long long i = 3; i <= N; i += 2)
    if (isPrime[i])
      for (int j = i * i; j <= N; j += i) isPrime[j] = false;
}

vector<int> generatePrimes(int N) {
  vector<bool> isPrime(N + 1, true);
  sieve(N, isPrime);
  vector<int> primes = {2};
  for (int i = 3; i <= N; i += 2)
    if (isPrime[i]) primes.push_back(i);
  return primes;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<int> primes = generatePrimes(N);
    vector<int> subtractorizations;
    for (size_t i = 0; i < primes.size(); i++)
      for (size_t j = i + 1; j < primes.size(); j++) {
        int diff = primes[j] - primes[i];
        if (diff <= N) subtractorizations.push_back(diff);
      }
    sort(subtractorizations.begin(), subtractorizations.end());
    subtractorizations.erase(unique(subtractorizations.begin(), subtractorizations.end()), subtractorizations.end());
    int primeCount = 0;
    vector<bool> isPrime(N + 1, true);
    sieve(N, isPrime);
    for (int num : subtractorizations) if (isPrime[num]) primeCount++;
    cout << "Case #" << t << ": " << primeCount << endl;
  }
  return 0;
}
