
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
#include <map>
#include <iostream>
using namespace std;

// Sieve of Eratosthenes
void sieve(int N, vector<int>& primes) {
  vector<bool> is_prime(N + 1, true);
  for (long long int p = 2; p * p <= N; p++) {
    if (is_prime[p]) {
      for (int i = p * p; i <= N; i += p)
        is_prime[i] = false;
    }
  }
  for (int p = 2; p <= N; p++)
    if (is_prime[p]) primes.push_back(p);
}

int solve(int N) {
  vector<int> primes;
  sieve(N, primes);
  
  map<int, int> subtractorizations;
  for (int i = 0; i < primes.size(); ++i)
    for (int j = i; j < primes.size(); ++j) {
      int diff = primes[i] - primes[j];
      if (diff > 0 && diff <= N) {
        subtractorizations[diff]++;
      }
    }
  
  int count = 0;
  for (auto& p : primes) {
    count += (subtractorizations[p] > 0);
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
