
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

vector<bool> sieve;
vector<int> primes;

// Compute all primes up to N
void primes_upto(int N) {
  sieve.resize(N + 1, true);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i * i <= N; ++i)
    if (sieve[i])
      for (int j = i * i; j <= N; j += i)
        sieve[j] = false;
  for (int i = 2; i <= N; ++i) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }
}

// Check if a prime can be a subtractorization
void check_subtractorizations(int N) {
  unordered_set<int> can_be_subtractorization;
  for (int prime : primes) {
    if (2 * prime <= N) {
      can_be_subtractorization.insert(2 * prime - 2);
    }
  }
  for (int i = 1; i < primes.size(); ++i) {
    for (int j = i; j < primes.size(); ++j) {
      int diff = primes[j] - primes[i];
      if (diff >= 2 && diff <= N) {
        can_be_subtractorization.insert(diff);
      }
    }
  }
  cout << can_be_subtractorization.size() << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    primes.resize(0);
    sieve.resize(0);
    primes_upto(N);
    cout << "Case #" << t << ": ";
    check_subtractorizations(N);
  }
  return 0;
}
