
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
using namespace std;

const int MOD = 998244353;
vector<vector<long long>> powers;

long long mod_mult(long long x, long long y) { return (x * y) % MOD; }

long long dfs(const string& s, int idx, int depth) {
  if (depth == (int)s.size()) return 1;
  int curr = s[idx] == '?' ? 0 : s[idx] - 'A';
  if (powers[idx][depth] == -1)
    powers[idx][depth] = 1;
  else
    powers[idx][depth] = powers[idx][depth - 1] * 26 % MOD;

  long long higher = powers[idx][depth - 1] * 26 % MOD;
  long long lower = (depth == 0 ? 1 : powers[idx][depth - 1]);
  if (idx && curr != (s[idx - 1] == '?' ? 0 : s[idx - 1] - 'A') &&
      curr != 0) {
    lower = (powers[idx - 1][depth - 1] * 26 % MOD -
             higher + MOD) %
            MOD;  // subtract lower branches
    higher =
        (higher + powers[idx - 1][depth - 1]) %
        MOD;  // add overlapping branches
  }
  return (dfs(s, idx + 1, depth + 1) + mod_mult(powers[idx][depth] - lower, 26) -
          mod_mult(higher - lower, 26) + MOD) %
         MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    string s[N];
    for (int i = 0; i < N; i++) cin >> s[i];
    powers.assign(N, vector<long long>(s[0].size(), -1));
    long long result = 0;
    for (int i = 0; i < N; i++) {
      result = (result + dfs(s[i], 0, 0)) % MOD;
    }
    cout << "Case #" << t << ": " << result << endl;
  }
  return 0;
}
