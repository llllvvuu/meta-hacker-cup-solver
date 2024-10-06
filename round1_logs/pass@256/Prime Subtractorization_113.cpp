
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
#include <bitset>
#include <iostream>
using namespace std;

const int maximum_value = 10000000;

bitset<maximum_value + 1> sieve_data;
bitset<maximum_value + 1> non_prime_sieve_data;
int primes[maximum_value / 10];
int sz;

void sieve(int N) {
  fill(primes, primes + sz, 0);
  fill(sieve_data.begin(), sieve_data.end(), true);
  fill(non_prime_sieve_data.begin(), non_prime_sieve_data.end(), false);
  sieve_data[0] = sieve_data[1] = false;
  sieve_data[2] = true;
  for (int i = 4; i <= N; i += 2) non_prime_sieve_data[i] = true;
  for (int i = 3; i <= N; i++) {
    if (non_prime_sieve_data[i] or i > N) continue;
    for (int j = 2 * i; j <= N; j += i) non_prime_sieve_data[j] = true;
  }
  sz = 0;

  for (int i = 1; i <= N; i++) {
    if (sieve_data[i]) primes[sz++] = i;
  }
}

int solve(int N) {
  sieve(N);
  int count = 0;

  // Special handling for the smallest primes
  if (N >= 2) count++;
  if (N >= 3) count++;

  for (int i = 2; primes[i] * 2 <= N; i++) {
    int p_i = primes[i];
    for (int j = 0; primes[j] * 2 <= p_i and j < sz; j++) {
      int p_j = primes[j];
      if (p_i - p_j >= 0) {
        if (non_prime_sieve_data[p_i - p_j] == false) count++;
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
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
