
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
#include <cmath>
using namespace std;

bool isPrime(const vector<bool>& sieve, int n) { return sieve[n]; }
set<int> subtractorizations(int N) {
  vector<bool> sieve(N+1, true);
  sieve[0] = sieve[1] = false; // 0 and 1 are not prime.
  for (int i = 2; i <= N; ++i) { // Sieve of Eratosthenes.
    if (isPrime(sieve, i)) {
      for (int j = i*i; j <= N; j += i) { sieve[j] = false; }
    }
  }
  
  set<int> diffs;
  for (int i = 2; i <= N; ++i) {
    if (isPrime(sieve, i)) {
      for (int j = i+2; j <= N; j += 2) {
        if (isPrime(sieve, j) && isPrime(sieve, j-i)) {
          diffs.insert(j-i);
        }
      }
    }
  }
  return diffs;
}

int main() {
  int T, N, sz;
  cin >> T;
  
  for (int t = 1; t <= T; t++) {
    cin >> N;
    auto diffs = subtractorizations(N);
    cout << "Case #" << t << ": " << diffs.size() << endl;
  }
  return 0;
}
