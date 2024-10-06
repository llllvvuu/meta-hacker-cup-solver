
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
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 10000001;
bool sieve[MAXN];
vector<int> primes;

// Generate prime numbers using Sieve of Eratosthenes
void findPrimes(int N) {
  memset(sieve, 1, sizeof(sieve));
  sieve[0] = sieve[1] = false;
  for (long long i = 2; i <= N; i++) {
    if (sieve[i]) {
      primes.push_back(i);
      for (long long j = i*i; j <= N; j += i) sieve[j] = false;
    }
  }
}

int main() {
  int T;
  findPrimes(MAXN - 1); // finding primes till MAXN-1
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int count = 0;
    
    if (N >= 3) count++; // 2 is a subtractorization for any N >= 3
    
    for (int i = 1; i < primes.size() && primes[i] <= N; i++) {
      int diff = primes[i];
      if (binary_search(primes.begin(), primes.end(), diff) && diff % 2 == 0) {
        count++;
      }
    }
    
    cout << "Case #" << t << ": " << count << endl;
  }
  
  return 0;
}
