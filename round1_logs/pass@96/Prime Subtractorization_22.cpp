
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

const int MAXN = 10000007;
bool sieve[MAXN];

void initialize_sieve(int N) {
  for (int num = 2; num <= N; ++num)
    sieve[num] = true;
  for (int i = 2; i * i <= N; ++i)
    if (sieve[i])
      for (int j = i * i; j <= N; j += i)
        sieve[j] = false;
}

int main() {
  int T;
  cin >> T;
  vector<int> primes;
  initialize_sieve(MAXN);
 
  for (int t = 1; t <= T; t++) {
    int N, count = 0;
    cin >> N;
    for (int i = 2; i < MAXN; i++) 
      if(sieve[i]) {
       primes.push_back(i);
        if (i < N) {
          for (int j = 0; j < primes.size() && primes[j] < N; j++) {
            int diff = primes[j] - primes[i];
            if (diff > 0 && sieve[diff]) count++;
          }
        }
      }
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
