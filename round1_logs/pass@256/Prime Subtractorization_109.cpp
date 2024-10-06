
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
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Sieve of Eratosthenes to generate all primes up to n
void sieve(int n, vector<bool>& is_prime) {
  is_prime.resize(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p * p <= n; p++) {
    if (is_prime[p]) {
      for (int i = p * p; i <= n; i += p) {
        is_prime[i] = false;
      }
    }
  }
}

// Helper function to get unique elements from vector
vector<int> get_unique(const vector<int>& vec) {
  set<int> unique_vals(begin(vec), end(vec));
  return vector<int>(begin(unique_vals), end(unique_vals));
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<bool> is_prime;
    sieve(N, is_prime);
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
      if (is_prime[i]) {
        primes.push_back(i);
      }
    }
    vector<int> subtractorizations;
    for (size_t i = 0; i < primes.size(); i++) {
      for (size_t j = 0; j <= i; j++) {
        int diff = primes[i] - primes[j];
        if (diff >= 2 && is_prime[diff]) {
          subtractorizations.push_back(diff);
        }
      }
    }
    vector<int> unique_subtractorizations = get_unique(subtractorizations);
    cout << "Case #" << t << ": " << unique_subtractorizations.size() << endl;
  }
  return 0;
}
