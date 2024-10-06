
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

vector<bool> sieve(int N) {
  vector<bool> is_prime(N+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (!is_prime[i]) continue;
    for (int j = i * i; j <= N; j += i)
      is_prime[j] = false;
  }
  return is_prime;
}

int subtractorizations(int N) {
  vector<bool> is_prime = sieve(N);
  vector<int> primes;
  // Record primes <= N
  for (int i = 2; i <= N; i++)
    if (is_prime[i])
      primes.push_back(i);
  int result = 0;
  vector<int> seen;
  for (int i = 0; i < primes.size(); i++) {
    // Consider the difference between every pair of primes.
    for (int k = 0; k <= i; k++) {
      int difference = primes[i] - primes[k];
      // If the difference is prime and it hasn't been seen before, count it.
      if (is_prime[difference] && difference <= N && find(seen.begin(), seen.end(), difference) == seen.end()) {
        seen.push_back(difference);
        result++;
      }
    }
  }
  return result;
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
