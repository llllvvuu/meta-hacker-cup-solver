
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

const int MAXN = 10000000;
vector<int> primes;

void sieve() {
  vector<bool> is_prime(MAXN + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= MAXN; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= MAXN; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int subtractorizations(int N) {
  if (N < 5) return 0;
  int cnt = 0;
  for (int i = 0; i < primes.size(); i++) {
    int p = primes[i];
    if (p > N) break;
    for (int j = 0; j < primes.size(); j++) {
      if (primes[j] + p > N) break;
      if (is_prime[primes[j] + p]) {
        cnt++;
        break;
      }
    }
  }
  return cnt - 1; // Exclude the prime 2 if it is overcounted
}

int main() {
  sieve();
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << subtractorizations(N) << endl;
  }
  return 0;
}
