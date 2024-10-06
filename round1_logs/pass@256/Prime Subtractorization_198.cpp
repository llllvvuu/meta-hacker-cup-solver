
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

const int MAX_N = 20000000;

bool is_prime[MAX_N];

void sieve() {
  fill_n(is_prime, MAX_N, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i < MAX_N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int count_primes(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (is_prime[i]) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  sieve();
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    cout << "Case #" << t << ": " << count_primes(N) << "\n";
  }
  return 0;
}
