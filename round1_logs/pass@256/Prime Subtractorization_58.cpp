
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
#include <algorithm>
using namespace std;

const int MAX_N = 200;

vector<int> generatePrimes(int limit) {
  vector<bool> isPrime(limit + 1, true);
  vector<int> primes;
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= limit; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = i*i; j <= limit; j += i)
        isPrime[j] = false;
    }
  }
  return primes;
}

int smallN(int N) {
  if (N < 3) return 0;
  vector<int> primes = generatePrimes(N);
  vector<int> primesMinus2;
  for (auto p : primes) if (p > 2) primesMinus2.push_back(p);
  set<int> results;
  for (int i = 0; i < primes.size(); ++i) {
    for (int j = 0; j < primesMinus2.size(); ++j) {
      int diff = primes[i] - primesMinus2[j];
      if (diff > N || diff < 2) continue;
      results.insert(diff);
    }
  }
  return results.size();
}

// For N > MAX_N, generatePrimes optimized to just find up to MAX_N and difference logic adjusted.
int largeN(int N) {
  vector<int> primes = generatePrimes(MAX_N);
  set<int> results;
  for (int i = 0; i < primes.size(); ++i) {
    for (int j = 0; j < primes.size(); ++j) {
      int diff = primes[i] - primes[j];
      if (diff > N || diff == 1) continue;
      results.insert(diff);
    }
  }
  return results.size();
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": ";
    cout << (N <= MAX_N ? smallN(N) : largeN(N)) << endl;
  }
  return 0;
}
