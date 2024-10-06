
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

bool is_prime[10000001];

void sieve(int N) {
  fill(is_prime, is_prime + N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i)
        is_prime[j] = false;
    }
  }
}

vector<int> generate_primes(int N) {
  vector<int> primes;
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i])
      primes.push_back(i);
  }
  return primes;
}

int main() {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N;
    cin >> N;
    sieve(N);
    auto primes = generate_primes(N);
    set<int> prime_diffs;
    int count = 0;

    for (int i = 0; i < primes.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        int diff = primes[i] - primes[j];
        if (diff > 0 && is_prime[diff])
          ++count;
      }
    }

    cout << "Case #" << tc << ": " << count << endl;
  }
  return 0;
}
