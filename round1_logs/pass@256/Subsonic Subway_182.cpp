
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
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

namespace {
typedef pair<int, int> II;

struct Interval {
  int t, B, id;
  bool operator<(const Interval& that) const { return t < that.t; }
};

class Case {
public:
  int result;
  vector<Interval> intervals;

  Case() : result(0) { }

  void read(int N) {
    intervals.clear();
    for (int i = 0; i < N; ++i) {
      int tA, tB;
      cin >> tA >> tB;
      intervals.push_back({tA, tB, i});
    }
    sort(intervals.begin(), intervals.end());
  }

  double solve() {
    double low = 0.0, high = 1e11;
    for (int it = 0; it < 100; ++it) {
      double mid = (low + high) / 2;
      if (check(mid)) low = mid;
      else high = mid;
    }
    return low;
  }

  bool check(double stime) {
    set<II> our_intervals;
    for (auto iv : intervals) {
      double end = IV_start(iv.t, iv.B, stime);
      if (end > double(iv.B)) return false;

      if (our_intervals.size() && our_intervals.rbegin()->first > end) {
        return false;
      }

      if (iv.B <= our_intervals.begin()->first) return true;
      our_intervals.insert({end, iv.B});
    }

    return true;
  }

  double IV_start(const double di, const double end_interval_time, const double second) {
    return (end_interval_time * second) / (di * second);
  }
}; 

} 

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    Case C;
    C.read(N);
    double res = C.solve();
    cout << "Case #" << t << ": ";
    if (res > 1e10) cout << -1 << '\n';
    else cout << setprecision(10) << res << '\n';
  }
  return 0;
}
