
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
#include <map>
using namespace std;

constexpr int MAX_N = 10000000 + 10;
static bitset<MAX_N> primes;

void sieve() {
  for (int i = 2; i <= MAX_N; i++) primes[i] = true; 
  for (int i = 2; i <= MAX_N; i++) {
    if (primes[i]) {
      for (int j = i + i; j <= MAX_N; j += i) primes[j] = false;
    }
  }
}

int count_subtractorizations(int n) {
  map<int,int> diffs;
  for (int i = 2; i <= n; i++) {
    if (primes[i]) { // Check is i is a prime
      for (int j = i; j <= n; j++) {
        if (primes[j]) {
          int diff = j - i;
          if (diff >= 2 && primes[diff])
            diffs[diff]++;
        }
      }
    }
  }
  return diffs.size();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int T;
  cin >> T;
  sieve();
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
  }
  return 0;
}
