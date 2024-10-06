
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

vector<bool> sieve(long max_num) {
  vector<bool> is_prime(max_num + 1, true);
  is_prime[0] = is_prime[1] = false;
  for(long i = 2; i * i <= max_num; i++) {
    if (is_prime[i])
      for (long j = i * 2; j <= max_num; j += i)
        is_prime[j] = false;
  }
  return is_prime;
}

int count_prime_subtractors(int n, vector<bool>& primes) {
  int prime_count = 0;
  for(int i = 2; i <= n; i++) {
    if (primes[i]) {
      bool subtractorizable = false;
      for(int j = i + 1; j <= n; j++) {
        if (primes[j] && primes[j - i]) {
          subtractorizable = true;
          break;
        }
      }
      if (subtractorizable) prime_count++;
    }
  }
  return prime_count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    auto is_prime = sieve(N);
    cout << "Case #" << t << ": " << count_prime_subtractors(N, is_prime) << endl;
  }
  return 0;
}
