
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
#include <unordered_map>
using namespace std;

const int maxN = 10000000;
bool primes[maxN + 1];
vector<int> all_primes;
unordered_map<int, int> sol;

void sieve() {
  fill(primes, primes + maxN + 1, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i <= maxN; i++) {
    if (primes[i]) for (int j = i * i; j <= maxN; j += i) primes[j] = false;
  }
  for (int i = 2; i <= maxN; i++) if (primes[i]) all_primes.push_back(i);
}

int solve(int N) {
  if (sol.count(N)) return sol[N];
  if (N <= 3) return 0;
  
  vector<int> diff;
  for (int i = 0; i < all_primes.size(); i++) {
    if (all_primes[i] > N) break; 
    for (int j = i + 1; j < all_primes.size(); j++) {
      auto diff = all_primes[j] - all_primes[i];
      if (diff >= 2 && diff <= N && primes[diff]) sol[N]++;
    }
  }
  return sol[N];
}

int main() {
  sieve();
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
}
