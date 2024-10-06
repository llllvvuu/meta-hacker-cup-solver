
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

const int MOD = 998244353;

// Helper function to compute modular inverse using Fermat's Little Theorem
int inv(int n) {
  int res = 1, p = MOD - 2;
  for (; p; p >>= 1) {
    if (p & 1) res = (long long)res * n % MOD;
    n = (long long)n * n % MOD;
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    long long W, G, L;
    cin >> W >> G >> L;
    long long D = W - G;
    long long X = D * D;
    long long Y = D * (D - L);
    long long ans = (X + Y) * inv(X + Y + 2) % MOD;
    cout << ans << endl;
  }
  return 0;
}
