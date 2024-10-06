
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
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using namespace std;

const ll M = 998244353;
ll mod_exp(ll a, ll e) { // a^e % M
  ll ret = 1, b = a;
  while (e > 0) {
    if (e & 1) ret = ret * b % M;
    b = b * b % M;
    e >>= 1;
  }
  return ret;
}

ll solve(ll G, ll W, ll L) {
  ll inv = mod_exp(2, L + 1);
  // Simplified calculation for "E[T]" given the analysis above:
  ll ans = ((inv * (W-G+1)) % M - inv + M) % M;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": " << solve(
        ll() , ll() , ll()) << '\n';    
  }
  return 0;
}
