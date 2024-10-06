
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
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 10000001;

bool is_prime[MAXN]; // to hold prime sieve information

// Sieve of Eratosthenes.
void generate_primes(int n) {
  fill(is_prime + 2, is_prime + n + 1, true);
  for (int i = 2; i * i <= n; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

vector<int> primes;

void precompute_primes(int n) {
  generate_primes(n);
  primes.reserve(n / log(n));
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int solve(int n) {
  precompute_primes(n);
  const int sz = primes.size();
  int count = 0;
  for (int i = 0; i < sz; ++i) {
    // Check if prime[i] is a subtractorization with respect to the largest prime smaller than or equal to N.
    int potential = n - primes[i];
    if (pre)
