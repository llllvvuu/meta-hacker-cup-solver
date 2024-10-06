
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
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int solve(string E) {
  int N = E.size(), dp[N], res = 0;
  fill(dp, dp + N, 1);
  for (int i = 0; i < N; i++) {
    if (E[i] == '?') E[i] = '1';
  }
  for (int i = 0; i < N; i++) {
    dp[i] = 0;
    if (i > 0) dp[i] = dp[i - 1];
    if (i > 0 && E[i - 1] != '0' && stoi(E.substr(i - 1, 2)) <= 26)
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    res = (res + dp[i]) % MOD;
  }
  return res;
}

string reconstruct(string E) {
  string R = E;
  for (auto& c : E) c = (c == '?') ? '1' : c;
  return R;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string E;
    int K;
    cin >> E >> K;
    string E2;
    convert();
    E = reconstruct(E);
    cout << "Case #" << t << ": " << E << " " << solve(E) << endl;
  }
  return 0;
}
