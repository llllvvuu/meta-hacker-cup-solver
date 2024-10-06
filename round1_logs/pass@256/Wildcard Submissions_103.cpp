
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
using Lua = uint64_t;
const Lua MOD = 998244353;

Lua dp[101][1025] = {}; // dp[depth][prefix] 

// Calculate result for one wildcard string
Lua solve(const string& S) {
    Lua& ans = dp[S.size()][0];
    if (!ans) {
        int n = S.size();
        ans = 1;  // root node
        for (int i = 0; i < n; i++) {
            ans *= S[i] == '?' ? 28 : 27;
            ans %= MOD;
            if (S[i] != '?') ans += dp[i][prefix(S, i - 1) + 'A'];
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
  int t;
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    int n; 
    cin >> n;
    vec<string> s(n);
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    Lua ans = 0;
    for (const auto& w : s)
      ans += solve(w);
    ans %= MOD;
    cout << "Case #" << case_num << ": " << ans << endl;
  }
  return 0;
}
