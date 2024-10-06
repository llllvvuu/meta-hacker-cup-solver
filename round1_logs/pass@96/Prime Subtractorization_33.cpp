
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

const int MAX_N = 10000007;
const bool is_prime[MAX_N];
void preprocess() {
  for (int i = 0; i < MAX_N; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= MAX_N / 2; i++) {
    for (int j = 2 * i; j < MAX_N; j += i) {
      is_prime[j] = false;
    }
  }
}

int count_primes(int N) {
  int count = 0;
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) count++;
  }
  return count;
}

int main() {
  preprocess();
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int res = (N < 4 ? 1 : count_primes(N) - 1);
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
