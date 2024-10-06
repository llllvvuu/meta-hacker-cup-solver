
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

const int MAXN = 10000001;

bool is_prime[MAXN];
vector<int> primes;

void sieve(int N) {
  fill(is_prime, is_prime + N, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < N; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    sieve(N + 1);
    int count = 0;
    for (int p : primes) {
      if (p >= N) break; // Optimization: Stop after finding all primes <= N
      for (int a : primes) {
        int b = a - p;
        if (a >= b && b >= 2 && is_prime[b]) {
          count++;
          break; // Optimization: Only the first occurrence is needed
        }
      }
    }
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
