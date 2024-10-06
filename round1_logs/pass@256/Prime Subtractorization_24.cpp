
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
#include <array>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 1e7 + 10;
constexpr int sq = 3163;
int sz;

vector<int> generatePrimes(int N) {
  vector<int> primes;
  array<bool, MAXN> isComposite;
  fill(isComposite.begin(), isComposite.end(), false);
  for (int i = 2; i <= sq; i++) {
    if (isComposite[i]) {
      continue;
    }
    for (int j = i * i; j <= N; j += i) {
      isComposite[j] = true;
    }
    primes.push_back(i);
  }
  for (int i = sq + 1; i <= N; i++) {
    if (isComposite[i]) {
      continue;
    }
    for (int j : primes) {
      if (j * j > i) {
        break;
      }
      isComposite[i * j] = true;
    }
    primes.push_back(i);
  }
  return primes;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> primes = generatePrimes(N);
    sz = primes.size();
    vector<bool> isSubtractor;

    for (int i = 0, p = sz - 1; i < sz; i++) {
      if (i * 2 > p) {
        break;
      }
      isSubtractor.push_back(false);
      while (p >= i) {
        if (primes[p] + primes[i] > N) {
          p--;
          continue;
        }
        if (primes[p] + primes[i] < sz && isSubtractor[primes[p] + primes[i]]) {
          isSubtractor[primes[p] + primes[i]] = false;
        } else if (primes[p] - primes[i] < sz && !isSubtractor[primes[p] - primes[i]]) {
          isSubtractor[primes[p] - primes[i]] = true;
        }
        p--;
      }
    }

    int ans = sz;
    for (int i = 0; i < sz; i++) {
      if (isSubtractor[i]) {
        ans++;
      }
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
