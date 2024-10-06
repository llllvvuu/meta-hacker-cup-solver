
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

vector<int> primes;
bool is_prime[MAXN];

void sieve(int N) {
  fill(is_prime + 2, is_prime + N + 1, true);
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i)
        is_prime[j] = false;
    }
  }
  for (int i = 2; i <= N; i++)
    if (is_prime[i]) primes.push_back(i);
}

int subtractorizations(int N) {
  sieve(N);
  int count = 0, n = primes.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n && primes[j] <= N; j++) {
        if (primes[j] - primes[i] <= N && is_prime[primes[j] - primes[i]]) {
            count++;
            break;
        }
    }
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << subtractorizations(N) << '\n';
  }
  return 0;
}
