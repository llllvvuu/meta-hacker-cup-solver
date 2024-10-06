
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
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

vector<int> sieve(int n) {
  vector<int> primes = {2}; // always prime
  vector<bool> composite(n + 1, false);
  
  for(int i = 3; i <= n; i += 2) { // loop over odd numbers starting from the last untouched prime (3)
    if(!composite[i]) {
      primes.push_back(i);
    }
    for(int p: primes) { // for an integer i, if it is divisible by a prime less then sqrt(i) is not prime
      int np = p * i; // first multple of p larger than i
      if(np > n) break;
      composite[np] = true;
      if((np - i) % (2 * p) == 0) break;
    }
  }
  return primes;
}
/**
 * Each case is independent.
 * Each test case starts from the last computed prime.
 * - if the prime is less than p, then p – prime is either composite or not in the sieve range.
 * - if the prime is greater than p, then it starts at least at the next of the previous value of p (or more)
 */
int count_Sub_R(int n){ 
  auto primes = sieve(n);
  int c = 0;
  for(int i = 0; i < primes.size(); i++) { //prime numbers
    for(int j = i+1; j < primes.size() && primes[j] <= n; j++) {
      if(primes[j] - primes[i] > primes.back()) break; // the difference can no longer be a valid Subtractorization
      if(primes[j] - primes[i] <= n && distances(primes.begin(), lower_bound(primes.begin() + i, primes.end(), primes[j] - primes[i])) == c.end()){
        c++;
      }
    }
  }
  return c;
}

int main(){
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++){
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << count_Sub_R(N) << "\n";
  }
}
