
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
#include <cmath>
using namespace std;

const double EPS = 1e-10;
const double INF = (double)1e9;

template <class T> bool equals(T a, T b) {
  return abs(a - b) < EPS;
}

bool check_speed(const vector<pair<long long, long long>>& timings, double speed) {
  double last_time = 0;
  for (const auto& [start, end] : timings) {
    if (start / speed + INF > end / speed + INF) return false;
    last_time = max(last_time, (double)end / speed);
    if (last_time + EPS >= start / speed) return false;
  }
  return true;
}

double find_min_speed(const vector<pair<long long, long long>>& timings) {
  double lo = 0, hi = INF;
  for (int _ = 0; _ < 200; _++) {
    double mid = (lo + hi) / 2;
    if (check_speed(timings, mid))
      hi = mid - EPS;
    else 
      lo = mid + EPS;
  }
  double min_speed = INF;
  if (lo < INF)
    min_speed = lo;

  return min_speed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<long long, long long>> timings(N);
    for (auto& [start, end] : timings) {
      cin >> start >> end;
    }
    sort(timings.begin(), timings.end());
    double ans = find_min_speed(timings);
    cout << "Case #" << t << ": ";
    if (ans >= INF)
      printf("%.6f", -1);
    else
      printf("%.6f", ans);
    if (t < T) cout << endl;
  }
  return 0;
}
