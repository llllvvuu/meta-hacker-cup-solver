
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

const double INF = 1e9;

struct Station {
  int a, b;
};

double solve() {
  int N;
  cin >> N;

  vector<Station> stations(N);
  vector<double> necessary_v;
  for (int i = 0; i < N; i++) {
    cin >> stations[i].a >> stations[i].b;
    necessary_v.push_back((double) (stations[i].b - stations[i].a) / (i + 1));
  }

  sort(necessary_v.begin(), necessary_v.end());
  if (necessary_v.empty() || necessary_v.back() < 0.0) return 0;

  double min_v = -1e9;
  for (const double v : necessary_v)
    min_v = max(min_v, min(1e9, v));

  return min_v;
}

double solveUsingIntervals() {
  int N;
  cin >> N;
  vector<pair<double, double>> intervals;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    intervals.push_back({a - i, a + i});
    intervals.push_back({b - i, -b - i});
  }
  sort(intervals.begin(), intervals.end());

  double maxSpeed = -1e9;
  double lastPos = 0;
  for (const auto &interval : intervals) {
    if (interval.first > lastPos)
      maxSpeed = max(maxSpeed, lastPos);
    lastPos = interval.second;
  }

  return maxSpeed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solveUsingIntervals() << endl;
  }
  return 0;
}
