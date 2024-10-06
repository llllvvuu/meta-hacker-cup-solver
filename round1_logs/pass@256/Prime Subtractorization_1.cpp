
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
#include <bitset>
using namespace std;

const int MAX_N = 10000000;

bitset<MAX_N + 1> is_prime;
vector<int> primes;

void sieve() {
  fill(begin(is_prime), end(is_prime), true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int count_subtractorizations(int N) {
  vector<bool> is_subtractorization(N + 1, false);
  for (int i = 0; i < primes.size(); ++i) {
    for (int j = i + 1; j < primes.size() && primes[j] <= N; ++j) {
      int diff = primes[j] - primes[i];
      if (diff <= N && is_prime[diff]) {
        is_subtractorization[diff] = true;
      }
    }
  }
  return count(begin(is_subtractorization), end(is_subtractorization), true);
}

int main() {
  // Precompute primes up to MAX_N
  sieve();
  
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N;
    cin >> N;
    cout << "Case #" << i << ": " << count_subtractorizations(N) << endl;
  }
  
  return 0;
}
