
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

void sieve(vector<bool> &primes, int n) {
  for (int i = 2; i * i <= n; i++) {
    if (!primes[i]) continue;
    for (int j = i * i; j <= n; j += i) {
        primes[j] = false;
    }
  }
}

int countSubtractorizations(int n) {
  vector<bool> primes(n+1, true);
  sieve(primes, n);
  int count = 0;
  
  for (int p1 = 2; p1 <= n; p1++) {
    if (primes[p1]) {
      for (int p2 = 2; p2 < p1; p2++) {
        if (primes[p2] && primes[p1 - p2]) {
          count++;
          break;
        }
      }
    }
  }
  
  return count;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << "Case #" << i << ": " << countSubtractorizations(n) << '\n';
    }
    return 0;
}
