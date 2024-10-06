
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
#include <deque>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

using ld = double;

tuple<ld, ld, int> interval(long i, long lo, long hi) {
  // Calculate and handle one endpoint gap if needed
  ld unit = (lo == hi) ? 1 : ld(lo) / i;
  return {(ld(lo) - ld(0.5) * unit) / i, (ld(hi) + ld(0.5) * unit) / i, i};
}

ld solve() {
  long N;
  cin >> N;
  ld ans = -1;
  vector<pair<ld, ld>> intervals;

  for (long i = (1); i <= (N); ++i) {
    long lo, hi;
    cin >> lo >> hi;
    tie(lo, hi, N) = interval(i, lo, hi);
    intervals.push_back({lo, hi});
  }

  // Sort intervals by start time
  sort(intervals.begin(), intervals.end());

  deque<pair<ld, int>> dq;
  for (const auto& [lo, hi] : intervals) {
    if (!dq.empty() && dq.front().first > lo) {
      return -1; // Invalid due to speed conflicts
    }
    ld cur = hi; // Keep track of the local max high end of intervals so far
    while (!dq.empty() && dq.back().second <= N) {
      cur = min(cur, dq.back().first);
      dq.pop_back();
    }
    dq.push_back({cur, N});
  }

  // Find the slowest required speed to cover everything
  if (!dq.empty()) {
    ans = (dq.front().second + 1) / dq.back().first;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << double(solve()) << endl;
  }
  return 0;
}

