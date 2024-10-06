
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

const int MAXN = 10000001;

bool is_prime[MAXN];
vector<int> primes;

void sieve() {
  fill(is_prime, is_prime + MAXN, true);
  for (long long i = 2; i < MAXN; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (long long j = i*i; j < MAXN; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void preprocess() {
  for (auto p : primes) {
    if (p >= MAXN) break;
    bool valid = true;
    for (auto q : primes) {
      if (p - q >= 0 && !is_prime[p - q]) {
        valid = false;
        break;
      }
    }
    if (valid) is_prime[p] = false;
  }
}

int main() {
  sieve();
  preprocess();
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": ";
    int count = 0;
    for (int p = 0; primes[p] <= N; p++) {
      if (is_prime[primes[p]]) count++;
    }
    cout << count << "\n";
  }
  return 0;
}
