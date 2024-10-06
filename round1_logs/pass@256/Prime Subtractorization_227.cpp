
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
#include <cstring>
#include <iostream>
using namespace std;

const int MAX_N = 10000000 + 5;
bool is_prime[MAX_N];
int primes[MAX_N];
int prime_count = 0;

void generate_primes() {
  memset(is_prime, true, sizeof(is_prime));
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i < MAX_N; i++) {
    if(is_prime[i]) {
      primes[prime_count++] = i;
      for(long long j = 1LL * i * i; j < MAX_N; j += i) 
        is_prime[j] = false;
    }
  }
}

int main() {
  int T;
  cin >> T;
  generate_primes();
  for(int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int result = 0;
    if(N <= 2) {
      cout << "Case #" << t << ": " << result << endl;
      continue;
    }
    for(int i = 0; i < prime_count && primes[i] <= N / 2; i++) {
      if(is_prime[N - primes[i]]) {
        result++;
      }
    }
    if(is_prime[N] && N >= 4) {
      result++;
    }
    cout << "Case #" << t << ": " << result << endl;
  }
  return 0;
}
