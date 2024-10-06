
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
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> primes;
bool is_prime[10000001]; // Array up to 10^7 to hold prime status of primes

void sieve(int N) {
  fill(begin(is_prime), end(is_prime), true);
  for (int i = 2; i <= N; i++) {
    if (!is_prime[i]) continue;
    primes.push_back(i);
    for (long long j = 1LL * i * i; j <= N; j += i) {
      is_prime[j] = false;
    }
  }
}

unordered_set<int> subtractorizations;

int main() {
  sieve(10000000); // Precompute primes up to 10^7
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    if (N < 2) {
      cout << "Case #" << t << ": " << 0 << endl;
      continue;
    }
    if (N < 3) {
      cout << "Case #" << t << ": " << 1 << endl;
      continue;
    }
    subtractorizations.clear();
    for (int i = 0; i < primes.size() && primes[i] <= N; i++) {
      for (int j = i; j < primes.size() && primes[j] <= N; j++) {
        int diff = primes[j] - primes[i];
        if (diff < 2 || diff > N) continue;
        subtractorizations.insert(diff);
      }
    }
    cout << "Case #" << t << ": " << (int) subtractorizations.size() << endl;
  }
}
