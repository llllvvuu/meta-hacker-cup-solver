
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

ll N, W, G, L;

ll mod_pow(ll b, ll e) {
  ll res = 1;
  for (ll i = 0; e > (1LL << i); i++) {
    if (((e >> i) & 1) == 1) res = res * b % MOD;
    b = b * b % MOD;
  }
  return res;
}

ll inv(ll x) { return mod_pow(x, MOD - 2); }

ll memo[100005][100005]; // Maximum necessary due to calculations

const ll MAXM = 100000;
ll fact[MAXM + 2], inv_fact[MAXM + 2];
void pre() {
  fact[0] = fact[1] = inv_fact[1] = 1;
  for (ll i = 2; i <= MAXM; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    inv_fact[i] = inv(fact[i]);
  }
}

ll get_sum(ll s, ll t) { return (t - s + 1) * (s + s + t - 1) / 2 % MOD; }

ll solve(ll w, ll m) {
  if (memo[w][m] != 0) return memo[w][m];
  if (w == G) return 0;
  if (w <= G) return MOD - 1;
  ll sum = (w - G);
  if (w <= m + L) {
    return memo[w][m] = (1 + (sum * get_sum(1, w - m) % MOD * inv_fact[sum] % MOD) % MOD) % MOD;
  }
  return memo[w][m] = (1 + solve(m, m)) % MOD;
}

int main() {
  cin >> N;
  pre();
  for (ll i = 1; i <= N; i++) {
    cin >> W >> G >> L;
    memo[0][0] = solve(W, W);
    cout << "Case #" << i << ": " << memo[0][0] << endl;
  }
  return 0;
}
