
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
#include <iostream>
#include <vector>
using namespace std;

int T;
int arr[1000001];
pair<int, int> intervals[1000001];

double try_speed(double mid) {
  // For a given speed mid, checks if Sonic can make all deliveries.
  vector<pair<double, double>> events;
  for (int i = 0; i < 1000001; i++) {
    if (arr[i] == 0) continue;
    double start_calc = (double)i / ((double)mid);
    double earliest_start = max(start_calc, (double)intervals[i].first);
    double latest_start = min(start_calc, (double)intervals[i].second);
    if (latest_start < earliest_start) {
      return false;
    }
    events.emplace_back(latest_start, 1);
    events.emplace_back(earliest_start, -1);
  }
  sort(events.begin(), events.end());
  int total_balance = 0;
  bool consistent = true;
  for (auto &event : events) {
    total_balance += event.second;
    if (total_balance > 1) {
      consistent = false;
      break;
    }
  }
  return consistent;
}

double solve() {
  cin >> N;
  double lo = 0;
  double hi = 1000000;
  while (hi - lo > 1e-7) {
    double mid = (lo + hi) / 2;
    if (try_speed(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  return lo;
}

int main() {
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
      cin >> intervals[i].first >> intervals[i].second;
      arr[i] = 1;
    }
    cout << "Case #" << t << ": " << fixed << setprecision(6) << solve() << endl;
    // Zero out arr and intervals for next iteration
    for (int i = 0; i <= 1000000; ++i) {
      arr[i] = 0;
    }
    for (int i = 1; i <= N; ++i) {
      intervals[i] = {0, 0};
    }
  }
  return 0;
}
