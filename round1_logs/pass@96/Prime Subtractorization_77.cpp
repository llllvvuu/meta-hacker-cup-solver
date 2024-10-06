
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

vector<int> primes;
vector<vector<bool>> subtractor;

void sieve(int N) {
  vector<bool> isPrime(N + 1, true);
  for (int i = 2; i * i <= N; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= N; j += i) {
        isPrime[j] = false;
      }
    }
  }
  for (int i = 2; i <= N; ++i) {
    if (isPrime[i])
      primes.push_back(i);
  }
  for (int i = 0; i < N + 1; ++i)
    subtractor.push_back(vector<bool>(N + 1, false));

  for (int i = 0; i < primes.size(); ++i) {
    for (int j = i; j < primes.size() && primes[i] + primes[j] <= N; ++j) {
      subtractor[primes[j]][primes[i]] = true;
    }
  }
}

int solve(int N) {
  int result = 0;
  for (int i = 0; i < primes.size() && primes[i] <= N; ++i) {
    for (int j = 0; j < primes.size() && primes[j] <= N; ++j) {
      if (subtractor[primes[j]][primes[i]] && primes[j] - primes[i] > 0 && is_prime(primes[j] - primes[i])) {
        result++;
      }
    }
  }
  return result;
}

bool is_prime(int n) {
  if (n <= 1) return false;
  if (n < 4) return true; // 2 and 3 are primes
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  return true;
}

int main() {
  int T;
  cin >> T;
  sieve(10000000); // Precompute up to 10,000,000
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
