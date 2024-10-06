
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
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000000;

bitset<MAX_N + 1> is_prime;
vector<int> primes;

void sieve(int max) {
  is_prime.reset();
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= max; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= max; j += i) {
        is_prime[j] = 0;
      }
    }
  }
}

int count_subtractorizations(int N) {
  sieve(N);
  int count = 0;
  for (int i = 0; i < primes.size(); ++i) {
    for (int j = i + 1; j < primes.size() && primes[j] - primes[i] <= N; ++j) {
      if (is_prime[primes[j] - primes[i]]) {
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
    cout << "Case #" << t << ": " << count_subtractorizations(N) << "\n";
  }
  return 0;
}
