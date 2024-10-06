
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
#include <algorithm>
using namespace std;

const int MAX_N = 10000005;
vector<int> primes;

void sieve() {
  int len = MAX_N;
  vector<bool> isPrime(len, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < len; ++i) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = i * 2; j < len; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  sieve();

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;

    vector<int> nums(2, 0);
    int ans = 0;
    for (const int &p : primes) {
      if (p > N + 1) break;
      if (p <= N) ++nums[(p - 1) % 2];
      if (p - 2 > 0 && p - 2 <= N) ans += nums[(p % 2)];
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
