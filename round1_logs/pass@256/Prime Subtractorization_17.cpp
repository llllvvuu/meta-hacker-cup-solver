
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

int sieve(const int N) {
  vector<bool> prime(N+1, true);
  prime[0] = prime[1] = false;
  for (int p = 2; p * p <= N; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= N; i += p)
        prime[i] = false;
    }
  }
  vector<int> primes;
  for (int i = 2; i <= N; i++) {
    if (prime[i]) primes.push_back(i);
  }
  return primes;
}

int diff_primes(int N, const vector<int>& primes) {
  static vector<bool> dp;
  dp.resize(N+1, false);
  for (auto a : primes) {
    for (auto b : primes) {
      if (b-a <= N && b-a >= 2)
        dp[b-a] = true;
    }
  }
  int ans = 0;
  for (auto n : dp) ans += n;
  return ans;
}

int solve(int N) {
  auto primes = sieve(N);
  return diff_primes(N, primes);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long N;
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
