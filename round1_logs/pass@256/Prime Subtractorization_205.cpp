
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

vector<int> primes;

void sieve(int N) {
  vector<bool> is_prime(N + 1, true);
  for (int p = 2; p*p <= N; p++) {
    if (is_prime[p]) {
      for (int i = p*p; i <= N; i += p) {
        is_prime[i] = false;
      }
    }
  }
  primes.push_back(2);
  for (int p = 3; p <= N; p += 2) {
    if (is_prime[p]) primes.push_back(p);
  }
}

int solve(int N) {
  sieve(N);

  int count = 0;
  for (int i = 0; i < primes.size(); i++) {
    for (int j = i + 1; j < primes.size(); j++) {
      int diff = primes[j] - primes[i];
      if (primes[i] > N - diff || diff < 0) break;
      if (primes[i] + diff > N) break;
      if (diff > 0 && is_prime[diff]) {
        count++;
        if (primes[i] == diff)break;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  int count=0;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
