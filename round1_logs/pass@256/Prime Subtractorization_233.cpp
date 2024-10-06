
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
#include <set>
using namespace std;

vector<int> sieve(int n) {
  vector<int> primes(n + 1, 1);
  primes[0] = primes[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (primes[i]) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = 0;
      }
    }
  }
  vector<int> ret;
  for (int i = 0; i <= n; i++) {
    if (primes[i]) ret.push_back(i);
  }
  return ret;
}

bool is_prime(int n, const vector<int>& primes) {
  for (int p: primes) {
    if (p * p > n) return true;
    if (p > n) return false;
    if (n % p == 0) return false;
  }
}

vector<int> calculate(int N) {
  vector<int> primes = sieve(N);
  set<int> subtractorizations;
  for (int i = 0; i < primes.size(); i++) {
    for (int j = 0; j < primes.size(); j++) {
      int diff = primes[i] - primes[j];
      if (diff > 0 && is_prime(diff, primes)) {
        subtractorizations.insert(diff);
      }
    }
  }
  return vector<int>(subtractorizations.begin(), subtractorizations.end());
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> ans = calculate(N);
    cout << "Case #" << t << ": " << ans.size() << endl;
  }
  return 0;
}
