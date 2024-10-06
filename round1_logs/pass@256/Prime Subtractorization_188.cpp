
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
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  
  for (int t = 1; t <= T; t++) {
    int N; 
    scanf("%d", &N);
    std::vector<bool> sieve(N+2);
    int64_t first = 2;
    int last, count = 0;
    vector<int> primes;
    
    // Sieve of Eratosthenes:
    for(int64_t i = 0; i * i < N + 2; i++) {
        if(sieve[i]) continue;
        sieve[i] = true;

        // Mark multiples of primes as not primes:
        for(int64_t j = i * 2; j <= N + 1; j += i) {
           sieve[j] = false;
        }
    }
    
    // Collect all primes.
    for(int i = 2; i < sieve.size(); i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    
    int count = 0;
    last = primes.size() - 1;
    // For each prime, check if it is a subtractorization
    for (int i = 0; i < primes.size(); i++) {
        first = primes[i];
        while (first < last && primes[i] + primes[last] > N) last--;
        // If a difference remains when subtracting the first prime from all primes
        while (primes[last] - primes[i] <= N) {
            if (sieve[primes[i] + primes[last] - N]) count++;
            last--;
        }
    }
    printf("Case #%d: %d\n", t, count);
  }
}
