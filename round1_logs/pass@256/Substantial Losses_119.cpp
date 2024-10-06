
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

long long modinv(long long a, long long m) {
  long long m0 = m, y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long G, W, L, M = 998244353;
    cin >> W >> G >> L;
    long long diff = W - G + L;
    long long days = diff * 2;
    long long p = days, q = 1;
    long long ans = (p * modinv(q, M)) % M;
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
