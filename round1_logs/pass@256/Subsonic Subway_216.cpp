
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
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double INF = 1E12, ERROR_TOL = 1E-6;

struct Interval {
  double left, right;
  Interval(double l, double r) : left(l), right(r) { }
  bool operator<(const Interval& other) const {
    if (left == other.left) return right > other.right;
    return left < other.left;
  }
};

double binary_search(const vector<Interval>& intervals) {
  double lo = 0, hi = INF, ans = INF;
  for (int it = 0; it < 100 && hi - lo > ERROR_TOL; ++it) {
    double mid = (lo + hi) / 2;
    bool pass = true;
    double current_expire = 0;
    for (const auto& interval : intervals) {
      if (mid >= interval.left && mid <= interval.right && current_expire >= interval.right) {
        pass = false;
        break;
      }
      if (mid >= interval.left && mid <= interval.right) {
        current_expire = max(current_expire, interval.right);
      }
    }
    if (pass) hi = mid;
    else lo = mid;
  }
  return lo;
}

pair<double, double> fromAdding(int i, int a, int b) {
  return make_pair((double)(i + 1) / a, (double)(i + 1) / b);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<Interval> intervals;
    for (int i = 0; i < N; i++) {
      int A, B;
      cin >> A >> B;
      intervals.push_back(fromAdding(i, A, B));
    }
    sort(intervals.begin(), intervals.end());
    double lo = binary_search(intervals);
    double hi = INF;
    for (const auto& interval: intervals) {
      hi = min(hi, interval.right);
      if (lo >= interval.left && lo <= interval.right) {
        hi = min(hi, (hi + lo) / 2);
        break;
      }
    }
    cout << "Case #" << t << ": " << (lo < INF ? lo : -1) << "\n";
  }
  return 0;
}
