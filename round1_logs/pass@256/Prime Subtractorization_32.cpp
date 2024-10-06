
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
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> sieve(int N) {  // Sieve of Eratosthenes
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p * p <= N; p++) {
    if (is_prime[p]) {
      for (int i = p * p; i <= N; i += p)
        is_prime[i] = false;
    }
  }
  vector<int> primes;
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": ";
    auto primes = sieve(N);
    set<int> subtractorizations;
    for (int i = 0; i < primes.size(); i++) {
      for (int j = i + 1; j < primes.size(); j++) {
        int diff = primes[j] - primes[i];
        if (diff > N || diff <= 1 || subtractorizations.count(diff))
          break;
        subtractorizations.insert(diff);
      }
    }
    cout << subtractorizations.size() << endl;
  }
  return 0;
}
