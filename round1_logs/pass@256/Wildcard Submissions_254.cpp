
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
#include <cstring>
using namespace std;
int dp[26][1 << 25], MOD = 998244353;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> words(N);
    for (auto &w : words) cin >> w;

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
      for (int m = 0; m < (1 << N); m++) {
        int x = dp[i][m];
        if (x >= MOD) continue;

        bool ok[26]{};
        for (int j = 0; j < N; j++)
          if (!(m & (1 << j))) ok[words[j][i] - 'A'] = true;

        for (int c = 0; c < 26; c++) {
          if (!ok[c]) {
            dp[i + 1][m | (1 << i)] = min(dp[i + 1][m | (1 << i)], x + (c == words[i][0] - 'A') ? 1 : (c ? 26 : 1));
          } else {
            if (words[i][i + 1] == '?' || words[i][i + 1] - 'A' == c)
              dp[i + 1][m] = min(dp[i + 1][m], x);
          }
        }
      }
    }

    int ans = dp[N][0];
    string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    for (int i = 0; i < 26; i++) {
      ans -= dp[N][1 << i];
      for (int j = 0; j < 26; j++) if (j != i){
        ans += dp[N][(1 << i) | (1 << j)];
      }
    }
    cout << "Case #" << t << ": " << (ans % MOD + MOD) % MOD << endl;
  }
  return 0;
}
