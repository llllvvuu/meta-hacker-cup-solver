
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

const int MAXN = 1e7 + 5;

vector<bool> is_prime(MAXN, true);
vector<int> primes;

void sieve(int N) {
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int solve(int N) {
  sieve(N);
  int ans = 0;
  for (int i = 2; i <= N; i++) {
    for (int j = N; j >= i; j--) {
      if (is_prime[i] && is_prime[j] && is_prime[j - i]) {
        ans++;
        break;
      }
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
