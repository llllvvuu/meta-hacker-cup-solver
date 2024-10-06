
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

const int MAX = 10000005;

bool is_prime[MAX];
vector<int> primes;

void sieve(int N) {
  fill(is_prime, is_prime + N + 1, true);
  for (int p = 4; p <= N; p += 2) is_prime[p] = false;
  for (int p = 3; p * p <= N; p += 2) {
    if (is_prime[p]) {
      for (int i = p * p; i <= N; i += 2 * p) is_prime[i] = false;
    }
  }
  for (int p = 2; p <= N; p++) {
    if (is_prime[p]) primes.push_back(p);
  }
}

int solve(int N) {
  sieve(N);
  fill(is_prime, is_prime + N + 1, false);
  for (int p = 0; p < primes.size(); p++) {
    for (int q = p; primes[p] + primes[q] <= N; q++) {
      if (is_prime[primes[p] - primes[q]]) {
        is_prime[primes[p] - primes[q]] = false; // Remove non-subtractorizations
      }
    }
  }
  int ans = 0;
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) ans++;
  }
  return ans;
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
