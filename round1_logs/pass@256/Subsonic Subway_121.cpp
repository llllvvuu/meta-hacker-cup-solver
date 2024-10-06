
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

double can_deliver(vector<pair<double, double>>& intervals, double speed) {
  double last_end = 0;
  for (auto& [start, end] : intervals) {
    start = max(start, last_end + 1.0 / speed);
    if (start > end) return false;
    last_end = end + 1.0 / speed;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    vector<pair<double, double>> intervals(N+1);
    for (int i = 1; i <= N; i++) {
      double A, B;
      cin >> A >> B;
      intervals[i] = {A, B}; // intervals are [start_time, end_time]
    }

    double low = -1, high = 1e6; // Range for binary search
    for (int _ = 0; _ < 100; _++) { // Precision, 10^(-6)
      double mid_speed = (low + high) / 2;
      if (can_deliver(intervals, mid_speed)) {
        high = mid_speed;
      } else {
        low = mid_speed;
      }
    }
    double ans = (low + high)/2;
    cout << "Case #" << t << ": " << fixed << setprecision(6) << (ans == 1e6? -1 : ans) << endl;
  }
  return 0;
}
