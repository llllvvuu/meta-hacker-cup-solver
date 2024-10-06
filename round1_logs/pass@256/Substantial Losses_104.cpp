
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
#include <algorithm>
#include <tuple>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll inverse(ll a) {
  ll b = MOD, u = 1, v = 0;
  while (a) {
    ll t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  return u + MOD;
}

ll solve(ll W, ll G, ll L) {
  if (L == 0) return (W - G) % MOD;
  if (W - G <= L + 1) return (W - G) % MOD; 
  ll c = min(W - G, L);
  ll a = 2 * (W - G) * (W - G) - 2 * (W - G) * c + 1;
  ll b = 2 * (W - G - c);
  return (a * inverse(b) % MOD);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    ll W, G, L;
    cin >> W >> G >> L;
    cout << "Case #" << t << ": " << solve(W, G, L) << endl;
  }
  return 0;
}
