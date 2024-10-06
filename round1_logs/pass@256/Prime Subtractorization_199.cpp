
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

const int MAX = 10000000 + 1;

bool isPrime[MAX]; // Sieve of Eratosthenes

void generatePrimes(int N) {
  fill(isPrime, isPrime + MAX, true);
  isPrime[0] = isPrime[1] = false;
  for (int p = 2; p * p <= N; p++) {
    if (isPrime[p]) {
      for (int multiple = p * p; multiple <= N; multiple += p) {
        isPrime[multiple] = false;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    generatePrimes(N);
    
    set<int> differences;
    for (int i = 2; i <= N; i++) {
      if (isPrime[i]) {
        for (int j = 2; j <= N; j++) {
          if (isPrime[j] && i + j <= N + 2 && isPrime[j]) {
            differences.insert(j - i);
          }
        }
      }
    }
    
    int count = 0;
    for (int candidate : differences) {
      if (isPrime[candidate]) {
        count++;
      }
    }
    
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
