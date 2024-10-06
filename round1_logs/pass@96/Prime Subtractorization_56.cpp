
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

void sieve(int N) {
  fill(is_prime, is_prime + N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

vector<int> count_subtractorizations(int N) {
  vector<int> count(N + 1);
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      if (is_prime[i + 2] && i > 2) count[2]++;
      for (int j = 3; j * j <= i; j += 2) {
        if (is_prime[i - j]) count[i - j]++;
      }
    }
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  sieve(10000000);
  vector<int> count = count_subtractorizations(10000000);
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << count[N] << endl;
  }
  return 0;
}
