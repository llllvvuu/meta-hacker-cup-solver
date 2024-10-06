
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

vector<bool> sieve(int N) {
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int p = 2; p * p <= N; ++p) {
    if (is_prime[p]) {
      for (int i = p * p; i <= N; i += p) {
        is_prime[i] = false;
      }
    }
  }
  return is_prime;
}

int solve(int N) {
  vector<bool> primes = sieve(N);
  int count = 0;
  vector<int> prime_nums;
  for (int i = 2; i <= N; ++i) {
    if (primes[i])
      prime_nums.push_back(i);
  }

  for (size_t i = 0; i < prime_nums.size(); ++i) {
    for (size_t j = i; j < prime_nums.size(); ++j) {
      int diff = prime_nums[j] - prime_nums[i];
      if (diff > 0 && primes[diff])
        count++;
    }
  }

  return count;
}

int main() {
  int T;
  cin >> T;
  vector<int> Ns(T);
  for (int t = 0; t < T; t++) {
    cin >> Ns[t];
  }

  for (int t = 0; t < T; t++) {
    cout << "Case #" << (t + 1) << ": " << solve(Ns[t]) << '\n';
  }
  return 0;
}
