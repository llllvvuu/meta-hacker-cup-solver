
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
#include <vector>
#include <iostream>
using namespace std;

struct Interval {
  double lo, hi;

  Interval(double a, double b) : lo(a), hi(b) {}
};

bool comp(const Interval& i1, const Interval& i2) {
  return i1.lo < i2.lo;
}

// Merges overlapping intervals
Interval mergeIntervals(vector<Interval>& intervals, int start, int end) {
  double minV = intervals[0].lo;
  for (int i = start; i <= end; i++) {
    minV = min(minV, intervals[i].lo);
  }
  double maxV = intervals[0].hi;
  for (int i = start; i <= end; i++) {
    maxV = max(maxV, intervals[i].hi);
  }
  return Interval(minV, maxV);
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<Interval> intervals(N);
    for (int i = 0; i < N; i++) {
      int A, B;
      cin >> A >> B;
      intervals[i] = Interval((A / (double)(i + 1)), (B / (double)(i + 1)));
    }
    
    sort(intervals.begin(), intervals.end(), comp);

    double ans = INT_MAX;
    int st = 0;
    
    for (int en = 0; en < N; en++) {
      if (en + 1 < N && intervals[en].hi >= intervals[en + 1].lo) {
        continue;
      } else {
        Interval merged = mergeIntervals(intervals, st, en);
        ans = min(ans, merged.hi);
        st = en + 1;
      }
    }

    if (ans < INT_MAX) {
      printf("Case #%d: %f\n", t, 1.0 / ans);
    } else {
      printf("Case #%d: -1\n", t);
    }
  }
}
