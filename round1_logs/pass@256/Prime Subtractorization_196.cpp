
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

const int N_MAX = 10000000;

vector<int> primes;
bool is_prime[N_MAX+1];

void sieve(int max_n) {
  primes.push_back(2);
  fill(is_prime, is_prime + max_n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 4; i <= max_n; i += 2) 
    is_prime[i] = false;
  for (int p = 3; p * p <= max_n; p += 2) 
    if (is_prime[p])
      for (int k = p * p; k <= max_n; k += 2 * p)
        is_prime[k] = false;
  for (int i = 3; i <= max_n; i += 2)
    if (is_prime[i]) primes.push_back(i);
}

int main() {
  int T;
  cin >> T;
  vector<int> subtractorizations(N_MAX + 1, 0);
  sieve(N_MAX);
  int count = 0;
  for (int p: primes) {
    if(p < N_MAX)
      subtractorizations[p] = count + 1;
    if (is_prime[N_MAX + 1 - p]) 
      count++;
  }
  for (int cas = 1; cas <= T; cas++) {
    int N;
    cin >> N;
    cout << "Case #" << cas << ": " << subtractorizations[N] << endl;
  }
  return 0;
}  
