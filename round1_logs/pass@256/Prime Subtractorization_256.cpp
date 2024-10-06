
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

const int MAX_N = 10000000;
vector<int> primes;

void sieve_prime(int n) {
  vector<bool> v(n + 1);
  v[0] = v[1] = true; // 0 and 1 are not primes
  for (int i = 2; i <= n; i++) {
    if (!v[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= n; j += i) {
        v[j] = true;
      }
    }
  }
}

int solve(int n) {
  sieve_prime(n);
  int sz = primes.size();
  vector<bool> subtractorizations(n + 1);
  int answer = 0;

  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      if (primes[j] - primes[i] <= n && !subtractorizations[primes[j] - primes[i]]) {
        subtractorizations[primes[j] - primes[i]] = true;
        if (primes[j] - primes[i] > 1) {
          // Special case handling: 2 is the only even prime
          if (primes[j] - primes[i] == 2) {
            if (i == 0) { // 2 is already accounted for in the sieve
              answer++;
            } else {
              continue;
            }
          } else {
            answer++;
          }
        }
      }
    }
  }

  return answer;
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
