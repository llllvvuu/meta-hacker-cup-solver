
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
  int open, close;
  bool operator<(const Interval& other) const {
    if (open != other.open)
      return open < other.open;
    return close < other.close;
  }
};

double calculateSpeed(int N, vector<pair<int, int>> windows) {
  vector<Interval> intervals(2 * (N + 1), {0, 1'000'000});
  for (int i = 1; i <= N; ++i) {            
    intervals[2 * i - 1] = {windows[i-1].first, windows[i-1].first};
    intervals[2 * i] = {windows[i-1].second, windows[i-1].second};
  }
  sort(intervals.begin(), intervals.end());
  double earliest = 0.0, latest = 0.0;
  bool isValid = true;
  int prev = intervals[0].close;
  for (Interval interval : intervals) {
    if (interval.open > prev) isValid = false;
    earliest = max(earliest, (double)interval.close / i);
    latest = min(latest, (double)interval.open / i);
    prev = interval.close;
  }
  return isValid ? 1 / latest : -1;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int, int>> windows(N);
    for (int i = 0; i < N; i++)
      cin >> windows[i].first >> windows[i].second;
    cout << "Case #" << t << ": " << calculateSpeed(N, windows) << "\n";
  }
  return 0;
}
