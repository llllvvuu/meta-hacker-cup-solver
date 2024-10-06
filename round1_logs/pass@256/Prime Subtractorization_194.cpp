
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
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7+1; // appropriately setting bounds for precomputation
vector<long long> primes;
bitset<maxN> is_prime;

void sieve(long long n) { // sieve of eratosthenes to find primes
  is_prime.set(); is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i*i <= n; ++i)
    if (is_prime[i]) 
      for(int j = i*i; j <= n; j += i) 
        is_prime[j] = 0;
  for (int i = 2; i <= n; ++i) 
    if(is_prime[i])
      primes.push_back(i);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  sieve(maxN - 1); // precompute primes up to upper bound
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    int N;
    cin >> N;  
    cout << "Case #" << t << ": ";
    long int ans = 0;
    for(auto d : primes) { // iterate over all primes ≤ N
      if (2 * d > N) break; // check constraints
      ans += is_prime[d] && 2 * d <= N; // check if d is an N-subtractorization
    }
    cout << ans << "\n";
  }
  return 0;
}
