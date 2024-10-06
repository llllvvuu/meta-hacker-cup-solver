
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

pair<long double, long double> calc(int D, long double speed) {
  return {D / speed, (D + 1) / speed};
}

pair<int, int> T[1000005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<long double, long double>> V;
    vector<long double> W;
    for (int i = 1; i <= N; i++) {
      long double A, B;
      cin >> A >> B;
      T[i] = {A, B + A};
      V.emplace_back(B + A, i);
      W.emplace_back(A);

      auto p = calc(i, A);
      if (p.second >= B) {
        cout << "Case #" << t << ": -1\n";
        return 0;
      }
    }
    sort(V.begin(), V.end());
    long double lo = 0, hi = 1e9 + 1;
    while (hi - lo > 1e-8) {
      long double mid = (lo + hi) / 2;
      bool good = true;
      int cur_st = 1, cur_pos = lo;
      long double cur_t2 = lo;
      for (int i = 0; i < N; i++) {
        int s = V[i].second;
        if (cur_t2 < W[s - 1]) {
          good = false;
          break;
        }
        cur_pos += s;
        cur_t2 = cur_pos / mid;
        if (cur_t2 > T[s].second) {
          good = false;
          break;
        }
      }
      if (good) {
        hi = mid;
      } else {
        lo = mid + 1e-8;
      }
    }

    long double ans = (hi + lo) / 2;
    cout << "Case #" << t << ": " << fixed << setprecision(12) << ans << "\n";
  }
  return 0;
}
