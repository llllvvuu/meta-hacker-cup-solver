
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

const int MAX_N = 1e7 + 5;
bool is_prime[MAX_N] = {};

void sieve(int n) {
  fill(is_prime, is_prime + n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p <= n; p++) {
    if (is_prime[p]) {
      for (int k = p * p; k <= n; k += p) {
        is_prime[k] = false;
      }
    }
  }
}

int count_subtractorizations(int n) {
  sieve(n);
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  int count = 0;
  int sz = primes.size();
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < i; j++) {
      if (is_prime[primes[i] - primes[j]]) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
  }
  return 0;
}
