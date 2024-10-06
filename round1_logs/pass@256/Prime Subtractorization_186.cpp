
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

bool is_prime[10000001];
vector<int> primes;
vector<bool> can_be_subtractorized(10000001);

void sieve(int N) {
  fill(begin(is_prime), end(is_prime), true);
  for (int p = 2; p * p <= N; p++) {
    if (is_prime[p]) {
      for (int q = p * p; q <= N; q += p) {
        is_prime[q] = false;
      }
    }
  }
  for (int p = 2; p <= N; p++) {
    if (is_prime[p]) {
      primes.push_back(p);
      can_be_subtractorized[p] = true;
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    sieve(N);
    memset(can_be_subtractorized, 0, sizeof(can_be_subtractorized));
    int result = 0;
    for (int i = 0; i < primes.size(); i++) {
      for (int j = i + 1; j < primes.size() && primes[j] - primes[i] <= N; j++) {
        int diff = primes[j] - primes[i];
        can_be_subtractorized[diff] = true;
      }
    }
    for (int i = 2; i <= N; i++) {
      if (is_prime[i] && can_be_subtractorized[i]) result++;
    }
    cout << "Case #" << t << ": " << result << '\n';
  }
  return 0;
}
