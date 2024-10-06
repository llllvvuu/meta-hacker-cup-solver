
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
const int MAX = 10024, MOD = 998244353, N = 26, NPC = 28;
int dp[MAX][NPC];

void ins(string cur, int d) {
  int i = 0;
  for(auto x: cur) {
    if(x == '?') {
      for(int j = 0; j < NPC; j++)
       dp[d + 1][j] = (dp[d + 1][j] + dp[d][i]) % MOD;
      i = NPC - 1;
    }
    else i = x - 'A';
    d++;
  }
  for(int j = 0; j < NPC; j++)
   dp[d + 1][j] = (dp[d + 1][j] + dp[d][i]) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  for(cin >> T; T--; ) {
    int n;
    cin >> n;
    string s;
    fill(dp[1], dp[MAX], 0); dp[1][NPC - 1] = 1;
    while(n--) {
      cin >> s;
      ins(s, 0);
    }
    cout << (long long)"Case #1: " << (dp[MAX - 1][NPC - 1] + MOD - 1) % MOD << '\n';
  }
}
