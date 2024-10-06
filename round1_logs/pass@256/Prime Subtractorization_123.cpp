
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

bitset<10000005> is_prime; // Array to store whether a number is prime

void sieve(int n) {
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = 0;
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    int n, res = 0;
    cin >> n;
    sieve(n);
    bitset<10000005> prime_nums;
    for (int i = 2; i <= n; ++i) {
      if (is_prime[i]) prime_nums[i] = 1;
    }

    bitset<10000005> counts;
    for (int i = 2; i <= n; ++i) {
      if (prime_nums[i]) {
        for (int j = 2; j < i && j <= n; ++j) {
          if (prime_nums[i - j]) {
            if (j < i) ++counts[i - j];
          }
        }
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (counts[i]) res++;
    }
    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
