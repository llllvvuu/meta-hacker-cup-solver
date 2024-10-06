
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

typedef long long ll;

const ll MOD = 998244353;

ll mod_inverse(ll a, ll m) {
  ll m0 = m, t, q;
  ll x0 = 0, x1 = 1;

  if (m == 1) return 0;

  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0) x1 += m0;

  return x1;
}

ll solve(ll W, ll G, ll L, ll inv2) {
  if (W < G + L) return W - G;
  vector<ll> inv(G + L + 1, 0), dp(G + L + 1, 0);
  inv[0] = 0;
  inv[G + L] = 1;
  ll min_wt = inv[G + L];

  for (ll gaps = 2; gaps <= G + L; gaps++) {
    ll num_inv = min(gaps / 2, L);
    ll gain = (num_inv == gaps / 2 ? 0 : inv2);
    inv[G + L - gaps + 1] = (gain + ((L - num_inv) * inv[G + L - gaps] + num_inv * inv[G + L - gaps + 1]) % MOD) % MOD;
    min_wt = (min_wt * 2 + inv[G + L - gaps + 1]) % MOD;
  }
  ll ans = (min_wt * (W - G - L + 1) + inv[G + 1]) % MOD;
  return ans;
}

int main() {
  ll T;
  cin >> T;
  ll inv2 = mod_inverse(2, MOD);
  for (ll t = 1; t <= T; t++) {
    ll W, G, L;
    cin >> W >> G >> L;
    cout << "Case #" << t << ": " << solve(W, G, L, inv2) << endl;
  }
  return 0;
}
