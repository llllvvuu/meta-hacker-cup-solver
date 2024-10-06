
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
#include <map>
#include <string>
using namespace std;

const int MOD = 998244353;
int N, sz;
string S;
map<string, int> dp;

int solve(string str) {
  auto it = dp.find(str);
  if (it == dp.end()) {
    return 0;
  }
  return it -> second;
}

void add(string str) {
  dp[str] = (dp[str] + 1) % MOD;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    dp.clear();
    dp[""] = 1; // initial node
    for (int i = 1; i <= N; i++) {
      cin >> S; sz = S.size();
      string base;
      for (int j = sz - 1; j >= 0; j--) {
        if (S[j] == '?') {
          for (char c = 'A'; c <= 'Z'; c++)
            add(base + c);
        } else 
          base = S[j] + base;
        add(base);
      }
    }
    long long ans = 0;
    for (auto it : dp) {
      ans = (ans + it.second) % MOD;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
