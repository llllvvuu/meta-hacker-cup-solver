
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
const int MOD = 998244353;
typedef long long ll;

int modpow(ll x, ll p) {
  ll res = 1;
  for (; p > 0; p /= 2, x = (x * x) % MOD) {
    if (p & 1) res = (res * x) % MOD;
  }
  return res;
}

struct Subset {
  int nSet = 0;
  bool v[27] = {0};
  Subset() = default;
  Subset(int n, bool include = false): nSet(n) {
    v[26] = include;
    memset(v, include, sizeof v - 1);
  }

  bool operator[](int i) const {
    return v[i];
  }

  void operator|=(Subset s) {
    for (int i = 0; i < 27; i++) {
      if (s.v[i]) {
        nSet += !v[i];
        v[i] |= s.v[i];
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<vector<Subset>> sets(101);
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      Subset s2 = Subset(1, true);
      for (char c : s) {
        s2.nSet += (c == '?');
        sets[s.size()].push_back(s2);
      }
    }
    vector<Subset> sets_comb;
    for (int i = 0; i < 101; i++) {
      for (Subset s : sets[i]) {
        sets_comb.push_back(s);
      }
    }
    int sz = sets_comb.size();
    sort(sets_comb.begin(), sets_comb.end(), [](Subset a, Subset b) {
      return a.nSet < b.nSet;
    });
    for (int i = 0, j = sz - 1; i < j; i++, j--) {
      Subset& s1 = sets_comb[i];
      Subset& s2 = sets_comb[j];
      Subset s3 = s2;
      s3 |= s1;
      s2 = s3;
    }
    cout << "Case #" << t << ": " << (sets_comb[sz % 2 ^ 1][0] ? 1 : 0) + 
                         (sets_comb[sz % 2 ^ 1][26] ? modpow(26, sets_comb[sz % 2 ^ 1].nSet - 1) : 0) << endl;
  }
  return 0;
}
