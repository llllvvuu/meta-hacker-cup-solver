
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

const int MAXN = 10000005;

vector<bool> is_prime(MAXN + 1, true);
vector<int> primes;

void sieve(int n) {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) primes.push_back(i);
    for (int j : primes) {
      if (i * j > n) break;
      is_prime[i * j] = false;
      if (i % j == 0) break;
    }
  }
}

int main() {
  int t;
  cin >> t;
  sieve(MAXN);

  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    int c = 0;
    for (int p : primes) {
      if (p <= n && p != 2)
        c++;
      if (p > n)
        break;
    }
    if (n >= 3) c++;
    cout << "Case #" << i << ": " << c << endl;
  }
  return 0;
}
