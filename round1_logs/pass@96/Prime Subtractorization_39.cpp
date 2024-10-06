
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
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// Function to implement the Sieve of Eratosthenes
bool isPrime[10000009] = {};

void sieve(int N) {
  fill(isPrime, isPrime + N + 1, true);
  isPrime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (isPrime[i]) {
      for (int j = i + i; j <= N; j += i)
        isPrime[j] = false;
    }
  }
}

int main() {
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    sieve(N);
    vector<int> primes;
    
    // Store all primes up to N
    for (int i = 2; i <= N; i++)
      if (isPrime[i])
        primes.push_back(i);

    int diff_count = 0;
    for (int i = 0; i + 1 < primes.size(); i++) {
      for (int j = i + 1; j < primes.size(); j++) {
        int diff = primes[j] - primes[i];
        if (diff > N) break;
        
        if (isPrime[diff])
          diff_count++;
      }
    }
    
    cout << "Case #" << t << ": " << diff_count << endl;
  }
  return 0;
}
