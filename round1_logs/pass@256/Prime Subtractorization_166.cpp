
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

const int MAXN = 10000005;

bool is_prime[MAXN];

// Sieve of Eratosthenes
void sieve(int n) {
  fill(is_prime, is_prime + n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * 2; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  sieve(MAXN);
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 2; i <= N; i++) {
      if (is_prime[i] && is_prime[N - i] && N - i <= N) {
        count++;
      }
    }
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
