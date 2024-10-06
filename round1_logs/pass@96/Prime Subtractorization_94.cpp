
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

vector<bool> primes;

void sieve(int N) {
  primes.resize(N+1, true);
  primes[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (primes[i]) {
      for (int j = i * i; j <= N; j += i) {
        primes[j] = false;
      }
    }
  }
}

vector<int> prime_diffs;

void count_prime_diffs(int N) {
  for (int i = 2; i <= N; i++) {
    if (primes[i]) {
      for (int j = 1; i + j <= N && primes[i + j]; j += 2) {
        prime_diffs[i + j]++;
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
  
    sieve(N);
    prime_diffs.resize(N+1, 0);
    count_prime_diffs(N);
  
    int ans = 0;
    for (int i = 2; i <= N; i++) if (primes[i] && prime_diffs[i]) ans++;
  
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
