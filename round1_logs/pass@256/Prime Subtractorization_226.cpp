
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
using namespace std;

const int MAXN = 10000000 + 1;
array<int, MAXN> is_prime;

void sieve() {
  fill(is_prime.begin(), is_prime.end(), 1);
  is_prime[0] = is_prime[1] = 0;
  for (int p = 2; p * p <= MAXN; p++) {
    if (is_prime[p]) {
      for (int i = p * p; i <= MAXN; i += p) {
        is_prime[i] = 0;
      }
    }
  }
}

int main() {
  int T;
  sieve();

  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;

    int ans = 0;
    vector<int> primes;
    for (int i = 1; i <= N; i++) {
      if (is_prime[i]) {
        primes.push_back(i);
      }
    }
    int sz = (int)primes.size();
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        if (i != j && primes[i] - primes[j] > 0 && primes[i] - primes[j] <= N && is_prime[primes[i] - primes[j]]) {
          ans++;
        }
      }
    }
    cout << ans / 2 << endl; // Each pair counted twice.
  }
  return 0;
}
