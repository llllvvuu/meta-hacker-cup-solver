
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

vector<bool> Sieve(int n) {
  vector<bool> isPrime(n+1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i*i <= n; i++)
    for (int j = i*i; j <= n; j += i)
      isPrime[j] = false;
  return isPrime;
}

int countSubtractorizations(int n) {
  if (n <= 5) return n > 1 ? 1 : 0;
  vector<int> prime(n+1, 0);
  vector<bool> isPrime = Sieve(n);
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      if (isPrime[i-2]) count--;
      if (isPrime[i-3]) count--;
      prime[i] = prime[i-1] + count + (isPrime[i-2] || isPrime[i-3]);
    }
  }
  return prime[n];
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << countSubtractorizations(N) << endl;
  }
  return 0;
}
