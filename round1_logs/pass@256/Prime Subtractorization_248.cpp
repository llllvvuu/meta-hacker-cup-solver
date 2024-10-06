
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

const int MAX_N = 10000000 + 5;

vector<int> primes;

bool sieve[MAX_N]; 

void generatePrimes(int N) {
  primes.clear();
  for(int i = 0; i < MAX_N; i++) sieve[i] = true;
  sieve[0] = sieve[1] = false;
  for(int i = 2; i * i <= N; i++) {
    if(sieve[i]) {
      for(int j = i * i; j <= N; j += i)
        sieve[j] = false;
    }
  }
  for(int i = 2; i <= N; i++) {
    if(sieve[i]) primes.push_back(i);
  }
}

int solve(int N) {
  generatePrimes(N); 
  vector<int> cnt(MAX_N, 0);
  int primeCount = 0;
  for(int i = 0; i < primes.size(); i++){
    int res = N - primes[i];
    if(res < 0) break;
    if(sieve[res] && res != 2) { // Ensure unique and proper subtraction
      if(cnt[res] == 0) primeCount++;
      cnt[res] = 1;
    }
  }
  return primeCount;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
