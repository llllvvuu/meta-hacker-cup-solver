
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

const int MAXN = 10000000;

vector<int> primes;

bool sieve[MAXN];

void generatePrimes(int n) {
  sieve[0] = sieve[1] = true;  // 0 and 1 are not prime.
  for (int i = 4; i <= n; i += 2) sieve[i] = true;  // Mark all even numbers as non-prime, starting from 4.
  for (int i = 3; i <= n; i += 2) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= n; j += i * 2) sieve[j] = true;  // Mark multiples of i as non-prime.
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    generatePrimes(N);
    int nsubtractorizations = 0;
    for (int p : primes) {
      if (p + 2 > N) break;  // No other primes can form a subtractorization from p.
      for (int q : primes) {
        if (q <= N) {
          if ((q - p) <= N && (q - p) > 1) nsubtractorizations++;
        } else {
          break;  // We have processed all relevant primes.
        }
      }
    }
    cout << "Case #" << t << ": " << nsubtractorizations / 2 << endl;  // Each pair is counted twice.
  }
  return 0;
}
