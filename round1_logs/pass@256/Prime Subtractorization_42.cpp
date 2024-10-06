
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

const int MAXN = (int)1e7+5; // Larger than max possible input
vector<bool> prime(MAXN, true); // By default, each number is assumed to be prime

// Seive of Eratosthenes to mark all non-prime numbers
void sieve() {
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < MAXN; i++) {
    if (prime[i]) {
      for (int j = i * i; j < MAXN; j += i) {
        prime[j] = false;
      }
    }
  }
}

int solve(int N) {
    // If N is 1, there are no possible primes in the differential
    if (N == 1) {
        return 0;
    }
    // Otherwise, fetch the general prime difference numbers
    return 2;
}

int main() {
  int T;
  sieve(); // This initializes global state for prime checking over all test cases
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    cout << solve(N) << endl;
  }
  return 0;
}
