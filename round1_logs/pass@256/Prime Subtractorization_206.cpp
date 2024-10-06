
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

bool sieve[10000000 + 1];

int primeSubtractorizations(int n) {
  // Sieve of Eratosthenes
  fill(sieve, sieve + n + 1, true);
  sieve[0] = sieve[1] = false; // 0 and 1 are not prime
  for (long long p = 2; p * p <= n; p++) {
    for (long long multiple = p * p; multiple <= n; multiple += p) {
      sieve[multiple] = false;
    }
  }

  set<int> subtractorizations;
  for (int i = 2; i <= n; i++) {
    if (sieve[i]) {
      for (int j = 2; i + j <= n + 1; j++) {
        if (sieve[j] && sieve[i - j + j]) {
          subtractorizations.insert(i - j);
        }
      }
    }
  }

  return subtractorizations.size();
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << primeSubtractorizations(N) << endl;
  }
  return 0;
}
