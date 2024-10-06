
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
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

constexpr int NMAX = 10'000'000;
array<int, NMAX + 1> sieve;
vector<int> primes;

// Precompute all primes up to NMAX using the Sieve of Eratosthenes
void precompute() {
  sieve.fill(1);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i <= NMAX; ++i) {
    if(!sieve[i]) continue;
    primes.push_back(i);
    for (int j = i * i; j <= NMAX; j += i) sieve[j] = 0;
  }
}

// Solve the specific case for a given n
int solve(int n) {
  for (int i = 2; i * i <= n; ++i) sieve[i] = 0;
  for (int i = 2; i <= n; ++i) if (!sieve[i]) primes.push_back(i);
  vector<int> p(primes.size());
  iota(p.begin(), p.end(), 0);
  sort(p.rbegin(), p.rend(), [&](int i, int j) {return primes[i] < primes[j]; });
  int ans = 0;
  for (int i : p) {
    if (primes[i] >= n) continue;
    int diff = n - primes[i];
    if (sieve.find(diff) != sieve.end() && sieve[diff]) ans++;
  }
  return ans;
}

int main() {
  precompute(); // Precompute primes up to NMAX
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    cout << "Case #" << t << ": " << solve(n) << endl;
  }
  return 0;
}
