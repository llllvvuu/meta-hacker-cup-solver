
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
#include <cmath>
using namespace std;

const double INF = 1e7;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    vector<pair<double, double>> windows(N);
    for (int i = 0; i < N; i++) {
      cin >> windows[i].first >> windows[i].second;
      windows[i].first /= i + 1;
      windows[i].second /= i + 1;
    }
    sort(windows.begin(), windows.end());
    vector<pair<double, double>> intervals = { { windows[0].second, INF } };
    double max_start = windows[0].second;
    for (int i = 1; i < N; i++) {
      if (windows[i].first > windows[i-1].second){
        cout << "-1\n";
        break;
      }
      auto it = lower_bound(intervals.begin(), intervals.end(), make_pair(windows[i].first + 1e-6, 0));
      max_start = min(max_start, windows[i].first);
      if (intervals.size() && intervals.back().second >= windows[i].second) {
        if (intervals.back().first < windows[i].second) {
          intervals.back().first = windows[i].second;
        }
        continue;
      }
      if (it == intervals.begin()) {
        if (it->first > max_start) {
          cout << "-1\n";
          break;
        }
        intervals.push_back({ windows[i].second, INF});
        continue;
      }
      if (it == intervals.end()) {
        intervals.pop_back();
        intervals.push_back({ max_start, windows[i].second });
        intervals.push_back({ windows[i].second, INF});
        continue;
      }
      intervals.pop_back();
      intervals.insert(it, { max_start, windows[i].second });
      intervals.insert(it, { windows[i].second, INF});
      max_start = windows[i].second;
    }
    double speed = INF;
    for (auto x : intervals) {
      speed = min(speed, x.first / x.second);
    }
    if (speed == INF) cout << "-1\n";
    else cout << fixed << setprecision(10) << 1e9 * speed << "\n";
  }
  return 0;
}
