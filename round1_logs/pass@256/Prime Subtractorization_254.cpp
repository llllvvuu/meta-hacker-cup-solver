
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

const int MAX_N = 10000001;

bool is_prime[MAX_N] = {};

void sieve() {
  fill_n(is_prime, MAX_N, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < MAX_N; i++) {
    if (is_prime[i]) {
      for (int j = i * 2; j < MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

vector<int> all_primes;

void generate_primes() {
  for (int i = 2; i < MAX_N; i++) {
    if (is_prime[i]) all_primes.push_back(i);
  }
}

int count_subtractorizations(int N) {
  vector<int> primes = all_primes;
  int count = 0;

  for (int i = 0; i < primes.size(); i++) {
    if (primes[i] > N) break;

    for (int j = 0; j <= i; j++) {
      if (primes[i] - primes[j] > N || !is_prime[primes[i] - primes[j]]) break;

      if (primes[i] - primes[j] >= 2) count++;
    }
  }

  return count;
}

int main() {
  sieve();
  generate_primes();

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
  }
  return 0;
}
