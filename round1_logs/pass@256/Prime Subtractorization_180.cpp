
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
#include <bitset>
#include <iostream>
using namespace std;

constexpr int NMAX = 10000000;
bitset<NMAX + 1> is_prime;

void prime_sieve() {
  for (long long i = 2; i <= NMAX; i++) {
    if (!is_prime[i]) {
      for (long long j = i; j * i <= NMAX; j++) {
        is_prime[i * j] = 1;
      }
    }
  }
}

int prime_count(int lim) {
  int count = 0;
  for (int i = 2; i <= lim; i++) {
    if (!is_prime[i]) count++;
  }
  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  prime_sieve();
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << prime_count(N) - (N <= 2) << endl;
  }
  return 0;
}
