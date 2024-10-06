
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

bool is_prime[10000001];
vector<int> primes;

void generate_primes(int n) {
  fill(begin(is_prime), begin(is_prime) + n + 1, true);
  is_prime[1] = false;
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i; j * i <= n; j += 2) {
        is_prime[j * i] = false;
      }
    }
  }
}

int solve(int n) {
  int count = 0;
  generate_primes(n);
  vector<bool> subtractorizations(n + 1, false);
  
  for (int &p : primes) {
    for (int &q : primes) {
      int diff = p - q;
      if (diff > 0 && diff < n) {
        if (is_prime[diff] && !subtractorizations[diff]) {
          subtractorizations[diff] = true;
          count++;
        }
      }
      if (p <= q) break;
    }
  }
  return count; // Returning the count of unique primes expressible as p - q
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    cout << "Case #" << t << ": " << solve(n) << "\n";
  }
  return 0;
}
