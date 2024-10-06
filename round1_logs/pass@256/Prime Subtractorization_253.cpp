
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

const int MAXN = 10000001;

vector<int> primes;
set<int> prime_diff;

bool sieve[MAXN] = {false};

void generate_primes(int n) {
  sieve[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = 2; i * j <= n; j++) {
        sieve[i * j] = true;
      }
    }
  }
  for (int i = 0; i < primes.size(); i++) {
    for (int j = i; j < primes.size() && primes[i] + primes[j] <= n; j++) {
      prime_diff.insert(primes[j] - primes[i]);
    }
  }
}

int solve_per_case(int N) {
  set<int> valid_subtracts;
  for (int i = 1; i <= N; i++) {
    if (!sieve[i])
      valid_subtracts.insert(i);
  }
  int count = 0;
  for (int i = 2; i <= N; i++) {
    if (!sieve[i] && valid_subtracts.count(i)) {
      count++;
    }
  }
  return count;
}

int main() {
  generate_primes(MAXN - 1);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << solve_per_case(N) << endl;
  }
  return 0;
}
