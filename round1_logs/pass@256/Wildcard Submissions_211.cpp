
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
using namespace std;
static const long long mod = 998244353;

long long mnn(bool *memo, long long &n, string &w, int i, int j, int &l) {
  if (memo[i << l | j]) return 0;
  memo[i << l | j] = true;
  if (j == (int)w.size() || (w[j] != '?' && w[j] != w[i])) return 0;
  long long x = mnn(memo, n, w, min(i + 1, l), j + 1, l);
  n = (n + x) % mod;
  if (w[j] == '?' && w[i] != '?') n = n * 26 % mod;
  return x + 1;
}

long long solve(string &wildcard) {
  bool memo[5000] = {false};
  long long res = 0;
  int len = (int)wildcard.size();
  for (int i = 0; i < len; ++i) {
    res += mnn(memo, res, wildcard, i, 0, len);
  }
  return res % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N;
    cin >> N;
    vector<string> wildcards(N);
    for (auto &s : wildcards) cin >> s;
    long long ans = 0;
    for (const string &s : wildcards) {
      bool visited[5000] = {false}; // Reset memoization table
      ans = (ans + solve(s)) % mod;
    }
    cout << "Case #" << i << ": " << ans;
  }
  return 0;
}
