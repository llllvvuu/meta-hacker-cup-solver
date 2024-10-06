
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

const int MAXN = 10000005; // A bit larger than the upper limit N

bool isPrime[MAXN];
vector<int> primes;

void sieve(int N) {
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= N; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= N; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    sieve(N);
    sort(primes.begin(), primes.end());
    set<int> subtractorizations;
    
    for (auto p : primes) {
      int i = 0, j = primes.size() - 1;
      while (i <= j) {
        int diff = primes[j] - primes[i];
        if (diff == p) {
          subtractorizations.insert(p);
          break;
        }
        if (diff > p) j--;
        if (diff < p) i++;
      }
    }
    cout << "Case #" << t << ": " << subtractorizations.size() << '\n';
  }
  return 0;
}
