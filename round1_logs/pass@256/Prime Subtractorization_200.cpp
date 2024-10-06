
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

vector<bool> sieve(int N) {
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return is_prime;
}

int countSubN (int N) {
  if (N < 3) {
    if (N == 1) return 0;
    return 1;
  }
  vector<bool> primes = sieve(N);
  int count = 0;
  for (int i = 2; i <= N; i++) {
    if (primes[i]) count++;
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << countSubN(N) << endl;
  }
  return 0;
}
