
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
#include <algorithm>

using namespace std;

const double EPSILON = 1e-6;
const double INF = 10000000000000; // Way larger than any possible valid speed

struct Interval {
  double lower, upper;
  bool intersects(const Interval &other) const {
    return !(!((other.lower <= this->upper + EPSILON) && 
               (this->lower <= other.upper + EPSILON)));
  }
};

bool can_be_delivered(const vector<Interval>& intervals, double speed) {
  vector<Interval> time_intervals;
  for (const auto& interval : intervals) {
    time_intervals.emplace_back(Interval{interval.lower/speed, interval.upper/speed});
  }
  sort(time_intervals.begin(), time_intervals.end(), [](const Interval& a, const Interval& b) {
    return a.upper + EPSILON < b.upper;
  });
  double maxOverlap = 0;
  for (int i = 1; i < time_intervals.size(); ++i) {
    if (time_intervals[i-1].intersects(time_intervals[i])) {
      maxOverlap = max(maxOverlap, time_intervals[i-1].upper - time_intervals[i].lower);
    }
  }
  return  maxOverlap + EPSILON >= time_intervals[0].upper - time_intervals[0].lower ||
          (time_intervals[0].upper <= time_intervals.back().lower);
}
  
double get_min_speed(const vector<Interval>& intervals) {
  double low = 0, high = INF;
  for (double step = (high-low)/2; step > EPSILON; step /= 2) {
    double mid = low + step;
    if (can_be_delivered(intervals, mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  if (low < high - EPSILON && can_be_delivered(intervals, low)) return low;
  return -1;
}

int main() {
  int T;
  cin >> T;
  
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<Interval> intervals(N);
    for (int i = 0; i < N; i++) {
      cin >> intervals[i].lower;
      cin >> intervals[i].upper;
      intervals[i].lower += i;
      intervals[i].upper += i;
    }
    double minSpeed = get_min_speed(intervals);
    print "Case #$t: "
    if (minSpeed >= 0) printf("%.6f\n", minSpeed);
    else printf("-1\n"); 
  }
  return 0;
}
