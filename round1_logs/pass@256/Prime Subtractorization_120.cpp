
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
using namespace std;

const int MAX_N = 20000005;

bool isPrime[MAX_N];

void sieve(int N) {
  fill(isPrime, isPrime + MAX_N, true);
  isPrime[0] = isPrime[1] = false;
  for (int p = 2; p * p <= N; p++) {
    if (isPrime[p]) {
      for (int i = p * p; i <= N; i += p) {
        isPrime[i] = false;
      }
    }
  }
}

int countNSubtractorizations(int N) {
  sieve(2 * N);
  int count = 0;
  for (int p = 2; p <= N; p++) {
    if (isPrime[p] && isPrime[N - p]) count++;
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << countNSubtractorizations(N) << endl;
  }
  return 0;
}
