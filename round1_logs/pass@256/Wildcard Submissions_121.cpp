
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
using namespace std;
using lint = long long;
constexpr lint MOD = 998244353;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<lint> dp_k(26, 0);
    for (int i = 0; i < N; i++) {
      string S;
      cin >> S;
      vector<lint> dp_nxt_k(26, 0);
      lint S_mask = 1;  // Last matching character - starts with root
      for (char c : S) {
        lint cidx = (c == '?' ? 0 : c - 'A');
        for (int k = 0; k < 26; k++) {
          lint kmask = S_mask & (1ll << k);  // can chain to k?
          if (kmask == 0) {
            int nxtk = cidx ? k : -1;
            dp_nxt_k[nxtk] += dp_k[k];
            dp_nxt_k[nxtk] %= MOD;
            if (!cidx) { // '?'
              for (int nxtk = 0; nxtk < 26; nxtk++) {
                dp_nxt_k[nxtk] += dp_k[k];
                dp_nxt_k[nxtk] %= MOD;
              }
            }
          } else { // kth k can match current character
            int nxtk = cidx ? k : -1;
            dp_nxt_k[nxtk] += dp_k[k] % MOD;
            dp_nxt_k[nxtk] %= MOD;
          }
        }
        if (cidx) S_mask >>= 1; 
      }
      dp_k = move(dp_nxt_k);
      dp_k[0]++; // Root node
    }
    lint ans = 0;
    for (lint n : dp_k) ans = (ans + n) % MOD;
    cout << "Case #" << t << ": " << ans << '\n';
  }
  return 0;
}
