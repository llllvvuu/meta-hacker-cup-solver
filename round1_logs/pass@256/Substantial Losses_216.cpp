
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

const int mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long W, G, L;
    cin >> W >> G >> L;
    if (G == W) {
      cout << "Case #" << t << ": " << 0 << endl;
      continue;
    }
    if (W - G == 0 && L == 0) {
      cout << "Case #" << t << ": " << 0 << endl;
      continue;
    }
    if (L == 0) {
      long long days = W - G;
      cout << "Case #" << t << ": " << days % mod << endl;
      continue;
    }

    long long delta = (W - G);
    long long target = G;
    vector<long long> dp(delta + 2);
    dp[delta] = 0;
    for (int i = delta - 1; i >= 0; i--) {
      dp[i] = (2 + ((dp[i + 1] + dp[min(i + L + 1, delta)]) % mod)) % mod;
    }
    long long inv = 1;
    for (int i = 2; i <= delta; i++) {
      inv *= 2;
      inv %= mod;
    }
    cout << "Case #" << t << ": " << dp[target - G] * inv % mod << endl;
  }
  return 0;
}
