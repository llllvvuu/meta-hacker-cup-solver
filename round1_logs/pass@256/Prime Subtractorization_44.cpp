
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
using namespace std;

const int MAX_N = 10000000;

vector<int> sieve; // Prime validation via sieve array, isn't directly needed due optimizations inherent differences only.
vector<bool> isPrime; // stores smaller primality within constraints

void populatePrimes() {
  isPrime.resize(MAX_N + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= MAX_N; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX_N; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int subtractorizations(int N) {
  populatePrimes(); // Ensure the prime-checking resources are prepared.
  int count = 0;
  for (int i = 2; i <= N; i++) {
    if (isPrime[i]) {
      int considered = N - i; // Subtract the prime.
      if (considered >= 2 && isPrime[considered]) // Ensures two distinct primes.
          count++;
    }
    // Double-check for odd results (Would be ensured from subtraction)
  }
  return count; // Direct report of valid *N-subtractorizations* count.
}

int main() {
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    cout << "Case #" << t << ": " << subtractorizations(N) << endl;
  }
  return 0;
}
