
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
#include <cassert>
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Node {
  long long final, children;
};

const int T = 25, lim = 100;
const long long mod = 998244353;

Node dp[lim + 1][T + 1];

// recursive memoized trie construction
long long go(const string& s, int i, int k) {
  if (i == s.size()) return k == 0;
  if (dp[i][k].final != -1) return dp[i][k];
  long long r = go(s, i + 1, k);
  dp[i][k].final = r * k % mod;
  long long n = r * (mod - k);
  if (s[i] == '?')
    dp[i][k].children = n;
  else
    dp[i][k].children = 26ll * n + k;
  return (dp[i][k].final + dp[i][k].children) % mod;
}

int main() {
  assert(go("?", 0, 1) == 27);
  assert(go("???", 0, 1) == 27 * 27 + 26);
  assert(go("???", 1, 26) == 1);
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 0; i < lim; i++) {
      for (int j = 0; j <= T; j++) dp[i][j] = { -1, -1 };
    }
    string s;
    for (int i = 0; i < N; i++) {
      cin >> s;
      ans += go(s, 0, 1);
      ans %= mod;
    }
    cout << "Case #" << c << ": " << ans << '\n';
  }
  return 0;
}
