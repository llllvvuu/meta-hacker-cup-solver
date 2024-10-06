
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

const int MOD = 998244353;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> patterns(N);

    vector<long long> powers(102);
    powers[0] = 1;
    for (int i = 1; i <= 100; i++) {
      powers[i] = (powers[i - 1] * 26) % MOD;
    }

    long long res = 0;

    for (int i = 0; i < N; i++) {
      cin >> patterns[i];
    }

    for (int i = 0; i < N; i++) {
      long long uniq = 0;

      for (char c : patterns[i]) {
        if (c == '?') {
          uniq = (uniq + powers[patterns[i].size() - i - 1]) % MOD;
        }
      }

      res = (res + uniq + 1) % MOD; // +1 for the empty prefix
    }

    res = (res * N) % MOD;

    cout << "Case #" << t << ": " << res << "\n";
  }
  return 0;
}
