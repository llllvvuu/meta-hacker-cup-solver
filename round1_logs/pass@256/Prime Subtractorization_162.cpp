
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

const int MAX_N = 10000001; 
vector<bool> is_prime(MAX_N, true);
vector<int> primes;
void sieve_of_eratosthenes(int N) {
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p * p <= N; p++) {
    if (is_prime[p]) {
      for (int i = p * p; i <= N; i += p) {
        is_prime[i] = false;
      }
    }
  }
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int main() {
  int T;
  cin >> T;
  sieve_of_eratosthenes(MAX_N - 1);
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int cnt = 0;
    for (int p : primes) {
      if (p >= N - p) break;
      if (is_prime[N - p]) cnt++;
    }
    cout << "Case #" << t << ": " << cnt << endl;
  }
  return 0;  
}
