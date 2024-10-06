
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

typedef long double ld;
const ld eps = 1e-6;

int N;
pair<int, int> info[1000005];
ld D[1000005];
bool okay = false;

ld run_time(int x, ld v) {
  return x / v;
}

bool is_feasible(ld v) {
  overall_time = 0.0;
  D[1] = info[1].second;
  for (int i = 1; i <= N; i++) {
    diff = D[i] - run_time(i, v);
    if (diff < 0 && i != 1 && !okay) return false;
    feasible_set = false;
    for (int j = i + 1; j <= N; j++){
      feasible_start = info[i].first > ((D[i] + (j - i) / v + overall_time + D[i]));
      feasible_end = info[i].second <= ((D[i] - (j - i) / v + overall_time + D[i]));
      feasible_set = feasible_start || feasible_end;
      if (feasible_set)
          break;
    }
    if (!feasible_set) return false;
    okay |= feasible_start;
  }
  return true;
}

ld binary_search_approach(ld lo, ld hi) {
  ok = false;
  while (hi > lo + eps) {
    md = (lo + hi) / 2;
    if (is_feasible(md)) {
      lo = md;
      ok = true;
    }
    else hi = md;
  }
  if (ok)
    return lo;
  else
    return -1.0;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> N;
    for (int i = 1; i <= N; ++i) { //Correct indexing and use "modified" D
      cin >> info[i].first >> info[i].second;
    }
    assert(is_feasible(1.0e2 * 2000000) && "initial assumption broken");
    auto result = binary_search_approach(0.0, 1.0e2 * 2000000);  // Hypothetical constant speed
    cout << "Case #" << t << ": " << fixed << setprecision(6) << result << "\n";
  }
  return 0;
}
