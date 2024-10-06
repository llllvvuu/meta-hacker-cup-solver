
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

const int NMAX = 10000100;
typedef long long int LLI;

int isPrime[NMAX], howManyPrimes;

// Sieve of Eratosthenes to generate primes up to NMAX
void sieve() {
  for (int i = 2; i < NMAX; i++) {
    if (isPrime[i] == 0) {
      // All multiples of i are not prime
      for (int j = i; j < NMAX; j += i) {
        isPrime[j] = 1;
      }
    }
  }
  // Now collecting all primes
  for (int i = 1; i < NMAX; i++) {
    if (isPrime[i] == 0) {
      howManyPrimes++;
    }
  }
}

int main() {
  sieve();
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int N;
    scanf("%d", &N);
    
    // Count of possible subtractorizations
    LLI count = 0LL;
    for (int i = 2, p = 1; i <= N; i++) {
      if (isPrime[i] == 0) {
        p = 1; // Mark as prime
        for (int j = i - 1; j >= 2 && j - p >= howManyPrimes; j -= p) {
          p = (p + 1);
          if (p > isPrime[j]) {
            break;
          }
          if (!isPrime[i - j]) {
            count++;
          }
        }
      }
    }
    printf("Case #%d: %lld\n", t, count);
  }
  return 0;
}
