
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

const int MAX_N = 10'000'000;

int main() {
  // Sieve for prime generation
  vector<bool> prime(MAX_N + 1, true);
  vector<int> primes;
  prime[0] = prime[1] = false;
  for (int i = 2; prime[i]; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (long long j = (1LL * i * i); j <= MAX_N; j += i) {
        prime[j] = false;
      }
    }
  }

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << (N == 2) << " ";
    for (int p : primes) {
      if (p >= N) break;
      if (N - p > N) continue;
      if (prime[N - p]) {
        cout << p << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
