
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
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10e5; // Sufficient sieve size amendment.
bitset<MAXN> is_prime;  // Sieve prime flags will be fitted.

void sieve_primes(int N) {
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < MAXN; j += i) {
        is_prime[j] = 0;
      }
    }
  }
}

int subtractorizations(int N) {
  vector<int> primes;
  sieve_primes(MAXN);  // Prepare i_prime for primary context.

  // Gather all primes within N and store in primes arr.
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  int result = 0;
  // For each prime, consider differences 
  for (size_t i = 0; i < primes.size(); i++) {
    for (size_t j = i; j < primes.size(); j++) {
      if (primes[j] - primes[i] <= N && is_prime[primes[j] - primes[i]])
        result++;
    }
  }
  return result;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << subtractorizations(N) << endl;
  }
  return 0;
}
