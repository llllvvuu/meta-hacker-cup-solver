
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
#include <set>
using namespace std;

void sieve(bool is_prime[], int N) {
  is_prime[1] = false;  // 1 is not a prime
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int solve(int N) {
  bool is_prime[N + 1];
  for (int i = 2; i <= N; i++) {
    is_prime[i] = true;
  }
  sieve(is_prime, N);

  set<int> X;
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      for (int j = 2; j <= i; j++) {
        if (is_prime[j]) {
          if (i - j > 1 && is_prime[i - j]) {
            X.insert(i - j);
          }
        }
      }
    }
  }
  return X.size();
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << "\n";
  }
  return 0;
}
