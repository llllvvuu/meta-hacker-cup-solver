
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

const int MAXN = 10000000;

vector<bool> prime(MAXN + 1, true);

void sieve() {
  prime[0] = prime[1] = false;
  for (int p = 2; p * p <= MAXN; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= MAXN; i += p) {
        prime[i] = false;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  sieve(); // Compute prime status for all numbers up to MAXN
    
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 2; i <= N; i++) {
      if (prime[i]) {
        count++;
      }
    }
    // subtract 1 for not counting the 2 as a difference
    if (N > 2) count--; // Adjust if N > 2 not to count 2+2
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
