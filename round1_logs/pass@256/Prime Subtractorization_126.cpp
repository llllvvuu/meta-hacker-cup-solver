
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
#include <vector>
using namespace std;

// Sieve of Eratosthenes for generating all primes up to n
void sieve(vector<bool>& is_prime, int n) {
  fill(is_prime.begin(), is_prime.end(), true);
  is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
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

    int upper_bound = max(N * 2, 5); // upper limit for sieve
    vector<bool> is_prime(upper_bound + 1, false);
    sieve(is_prime, upper_bound);

    int count = 0;
    for (int i = 2; i <= N; i++) {
      if (is_prime[i] && (N != 2 || i != 2)) count++;
    }

    cout << "Case #";
    cout << t << ": " << count << endl;
  }
  return 0;
}
