
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

vector<int> sieve(int N) {
  vector<int> primes;
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}

int subtractorizations(int N) {
  vector<int> primes = sieve(N);
  int count = 0;

  for (int i = 0; i < primes.size(); i++) {
    for (int j = i; j < primes.size(); j++) {
      int diff = primes[i] - primes[j];
      if (diff > 0 and binary_search(primes.begin(), primes.end(), diff)) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << subtractorizations(N) << endl;
  }
  return 0;
}
