
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

bool can_run(double speed, const vector<pair<int, int>>& intervals);
double binary_search_speed(const vector<pair<int, int>>& intervals);

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    vector<pair<int, int>> intervals;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      intervals.emplace_back(a, b);
    }
    cout << fixed << setprecision(6) << "Case #" << t << ": ";

    // Adjust intervals to be station-relative
    for (auto& [a, b] : intervals) {
      a = a / (intervals.size() + 1);
      b = b / (intervals.size() + 1);
    }

    double min_speed = binary_search_speed(intervals);
    cout << min_speed << endl;
  }
  return 0;
}

double binary_search_speed(const vector<pair<int, int>>& intervals) {
  double lower = 0.0, upper = 1000000.0;
  while (upper - lower > 1e-7) {
    double mid = (lower + upper) / 2.0;
    if (can_run(mid, intervals)) {
      upper = mid;
    } else {
      lower = mid;
    }
  }
  return lower;
}

bool can_run(double speed, const vector<pair<int, int>>& intervals) {
  for (const auto& [a, b] : intervals) {
    if (speed < a || speed > b) {
      return false;
    }
  }
  return true;
}
