
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
#define X 5000001 // N / 2
using namespace std;

int main() {
  int T;
  cin >> T;
  vector<vector<int>> primes(X); // precomputed primes for each sieved range
  bool is_prime[X];
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> counts(N + 1, 0); // counts of possible diffences for each r <= N
    int cases = N / 2;

    if (t <= 1000) { // precompute primes up to X only if needed to manage problem's constraint
      fill(is_prime, is_prime + X, true);
      for (int i = 2; i <= X; i++) {
        if (is_prime[i]) {
          primes[cases].push_back(i);
          for (int j = i * 2; j <= X; j += i)
            is_prime[j] = false;
        }
      }
      cases = -1; // no computation needed for next queries now stored
    }
    int high = cases == -1 ? primes[1000 - 1][primes[1000 - 1].size() - 1] : primes[cases][primes[cases].size() - 1];
    if (high > N) high = N;
    int cnt = 0;
    for (int i = 2; i <= high; i++) {
      if (is_prime[i]) {
        int val = N - i;
        if (val >= i && is_prime[val]) cnt++;
      }
    }
    cout << "Case #" << t << ": " << cnt << endl;
  }
  return 0;
}
