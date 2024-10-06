
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
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000010;
bool dp[MAX_N];
bitset<MAX_N> is_prime;
vector<int> primes;

void fillPrimes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!is_prime[i]) {
      primes.push_back(i);
      for (int j = i * 2; j <= n; j += i) {
        is_prime[j] = true;
      }
    }
  }
}

int solve(int n) {
  fill(dp, dp + n + 1, 0);
  dp[0] = dp[2] = 1;
  for (int p : primes) dp[p] = 1;
  for (int i = 2; i <= n; i++) {
    if (dp[i]) {
      while (i * 2 <= n) {
        dp[i * 2] = false;
        i *= 2;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) if (dp[i]) ans++;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  is_prime.set();
  is_prime[0] = is_prime[1] = false;
  fillPrimes(MAX_N - 1);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    cout << "Case #" << t << ": " << solve(n) << '\n';
  }
  return 0;
}
