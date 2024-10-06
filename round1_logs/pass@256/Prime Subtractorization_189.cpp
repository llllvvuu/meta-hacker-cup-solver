
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
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000001;
bool prime[MAX_N];
vector<int> primes;

void sieve(int N) {
  fill(prime, prime + N + 1, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= N; i++) {
    if (prime[i]) primes.push_back(i);
  }
}

int solve(int N) {
  int ans = 0;
  sieve(N);
  for (int i = 0; i < primes.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (primes[i] - primes[j] <= N && prime[primes[i] - primes[j]]) {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
