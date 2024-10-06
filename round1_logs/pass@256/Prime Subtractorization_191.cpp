
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
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool is_prime(vector<bool> &primes, int i) {
  return primes[i];
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<bool> primes(N + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i * i <= N; i++) {
      if (primes[i]) {
        for (int j = i * i; j <= N; j += i) {
          primes[j] = false;
        }
      }
    }
    int res = 0;
    if(N > 2)
      res++;
    for (int i = 3; i < N + 1; i+=2) {
      if (is_prime(primes, i) && is_prime(primes, i + 2)) {
        res++;
      }
    }
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
