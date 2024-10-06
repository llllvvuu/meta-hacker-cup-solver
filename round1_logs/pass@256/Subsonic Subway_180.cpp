
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
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;

bool can_run_at_speed(double speed, vector<pair<int, int>>& stations) {
  for (int i = 0; i < stations.size(); i++) {
    int A = stations[i].first, B = stations[i].second;
    double arrival_time = i + 1.0 / speed;
    if (arrival_time < A + EPS || arrival_time > B + EPS) return false;
  }
  return true;
}

double find_min_speed(vector<pair<int, int>>& stations) {
  double lo = 0.0, hi = 1e10;
  for (int _ = 0; _ < 100; _++) {
    double mid = (lo + hi) / 2.0;
    if (can_run_at_speed(mid, stations)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  return lo;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<pair<int, int>> stations(N);
    for (auto &p : stations) {
      cin >> p.first >> p.second;
    }
    double min_speed = find_min_speed(stations);
    if (min_speed > 1e9) {
      cout << "Case #" << t << ": -1\n";
    } else {
      cout << fixed << setprecision(6) << "Case #" << t << ": " << min_speed << endl;
    }
  }
  return 0;
}
