
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
#define MOD (int)998244353
using namespace std;

typedef long long ll;
ll dp[1 << 27], N, ans = 0;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    cin >> N; ans = 1;
    vector<string> a(N);
    for (int i = 0; i < a.size(); i++) cin >> a[i];
    int full = (1 << 26) - 1;
    for (auto &s : a) {
      ll cur = 1;
      dp[cur++] = 1;
      for (char c : s) {
        vector<ll> next;
        for (ll b = 0; b < cur; b++) next.push_back(full);
        for (ll b = 0; b < cur; b++) {
          ll n = b << 5;
          if (c == '?') for (int i = 1; i <= 26; i++) n |= 1 << i;
          else n |= 1 << (c - 'A' + 1);
          next[n & full] |= b;
        }
        swap(next, dp);
        ll old_cur = cur;
        cur = 0;
        for (auto x : next) {
          if (x != old_cur - 1) cur--;
          else cur++;
          if (x >= 1) dp[x] += dp[x - 1], dp[x] %= MOD;
        }
      }
      for (int i = 0; i < (1 << 27); i++) ans += dp[i] & 1;
    }
    cout << "Case #" << tc << ": " << (ans - 1 + MOD) % MOD << endl;
  }
  return 0;
}
