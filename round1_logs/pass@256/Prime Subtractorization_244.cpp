
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
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> primes{(int)2, (int)3};
vector<bool> prime_check{(int)4};

// Function to return primes up to n using the Sieve of Eratosthenes
void sieve(int n) {
  prime_check.assign(n + 1, true);
  prime_check[0] = prime_check[1] = false;
  for (int i = 2; i <= n; i++) {
    if (prime_check[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= n; j += i) {
        prime_check[j] = false;
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
    if (N <= 2) {
      cout << "Case #" << t << ": " << (N == 2 ? 1 : 0) << endl;
      continue;
    }
    
    sieve(N);
    int count = 0;
    for (int i = 0; i < primes.size() && primes[i] <= N; i++) {
      if (prime_check[N - primes[i]]) {
        count++;
      }
    }
    
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
