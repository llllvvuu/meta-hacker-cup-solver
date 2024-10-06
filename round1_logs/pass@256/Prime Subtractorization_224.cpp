
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
using namespace std;

const int LIMIT = 1e7 + 1;
bool is_prime[LIMIT];
int sieve[N];

void generatePrimes(int N) {
  fill(is_prime, is_prime + LIMIT, true);
  is_prime[0] = is_prime[1] = false;
  for (long long p = 2; p < LIMIT; p++) {
    if (is_prime[p]) {
      sieve[p] = 1;
      for (long long i = p * p; i < LIMIT; i += p) {
        is_prime[i] = false;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  generatePrimes(LIMIT);
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int count = 0;
    for (int p = 2; p <= N; p++) {
      if (is_prime[p]) {
        for (int q = 2; q <= p; q++) {
          if (is_prime[q] && is_prime[p - q]) {
            count++;
            break;
          }
        }
      }
    }
    cout << "Case #" << t << ": " << count << "\n";
  }
}
