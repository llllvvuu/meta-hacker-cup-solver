
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
#include <assert.h>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
int dp[100][1024];

int solve(const vector<string>& strings, int pos) {
  if (pos == 0) return 1;
  if (dp[pos][0] == -1) {
    dp[pos][0] = 0;
    for (const string& str : strings) {
      int cur = 0;
      int uses = 0;
      if (pos <= str.size() && str[pos - 1] != '?') {
        cur |= 1 << (str[pos - 1] - 'A');
        uses = 1;
      }
      for (int i = 1; i < 26; i++) {
        if (cur & i) continue;
        dp[pos][0] += solve(strings, pos - 1);
        dp[pos][0] %= MOD;
      }
      dp[pos][cur] = (dp[pos][0] + uses) % MOD;
    }
  }
  return dp[pos][0];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> strings(N);
    for (string& s : strings) {
      cin >> s;
    }

    int H = strings[0].size();
    memset(dp, -1, sizeof(int) * H * 1024);
    int ans = solve(strings, H);
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
