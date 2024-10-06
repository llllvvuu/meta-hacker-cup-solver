
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
#include <cmath>
using namespace std;

const int MAXN = 10000000;
bool is_prime[MAXN];

void sieve(int N) {
  for (int i = 2; i <= N; i++) is_prime[i] = true;
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) is_prime[j] = false;
    }
  }
}

bool find_prime_difference(int num, vector<int> &primes) {
  int l = 0, r = primes.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (primes[mid] == num) return true;
    else if (primes[mid] < num) l = mid + 1;
    else r = mid - 1;
  }
  return false;
}

int main() {
  int T;
  cin >> T;
  sieve(MAXN);

  vector<int> primes;

  for (int cas = 1; cas <= T; cas++) {
    int N;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
      if (is_prime[i]) primes.push_back(i);
    }
    int sub_count = 0;
    for (size_t p = 1; p < primes.size(); ++p) {
      int target = primes[p] - primes[p - 1];
      if (find_prime_difference(target, primes)) {
        sub_count += 1;
      }
    }
    cout << "Case #" << cas << ": " << sub_count << "\n";
    primes.clear();
  }
  return 0;
}
