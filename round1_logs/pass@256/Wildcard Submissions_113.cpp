
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
#include <unordered_set>
using namespace std;

constexpr int MOD = 998244353;
unordered_set<long long> seen;
int pcs[101][101] = {};

int count_insert(string p) {
  if(!p.empty() && pcs[p[0] - 'A'][p.length() - 1]) return pcs[p[0] - 'A'][p.length() - 1];

  long long c = 0;
  for(auto prev: prev_path(p)) {
    c = (c + count_insert(prev)) % MOD;
  }
  c += pow(26, p.length() - (seen.count(p) ? 1 : 0));
  c %= MOD;
  if(pcs[p[0] - 'A'][p.length() - 1] = c, !p.empty()) return c;
  return (c - pow(p.length(), 26) + MOD) % MOD;
}

long long prev_path(string p) {
  for(int i = 0; i < p.length(); i++) {
    if(p[i] == '?') {
      seen.insert(p.substr(0, i));
      return i;
    }
  }
  seen.insert(p);
  return p.length();
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    seen.clear();
    int N;
    cin >> N;
    long long ans = 0;
    for(int i = 0; i < N; i++) {
      string s;
      cin >> s;
      ans += count_insert(s);
      ans %= MOD;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
