
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
#include <cstring>
#include <iostream>
using namespace std;

int T, N;

bool prime[10000010];

void sieve(int N) {
  memset(prime, true, sizeof(prime));
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }
}

int main() {
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    sieve(N);
    int count = 0;
    for (int i = 2; i <= N; i++) {
      for (int j = 2; j < i && j * j <= N; j++) {
        if (prime[i] && prime[j] && prime[i - j]) count++;
      }
    }
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
