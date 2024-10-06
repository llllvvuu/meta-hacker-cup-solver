
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
#include <queue>
using namespace std;

const double INF = 1e9;

struct Event {
  int i;
  double t;
  Event(int I, double T): i(I), t(T) {}
  bool operator<(const Event& other) const {
    return t < other.t;
  }
};

double findMinSpeed(vector<pair<int, int>>& stations) {
  vector<Event> events;
  for (int i = 0; i < stations.size(); i++) {
    events.push_back(Event(i, stations[i].first - i));
    events.push_back(Event(i, stations[i].second - i));
  }
  sort(events.begin(), events.end());

  double D = 0, T = 0;
  double minSpeed = INF;
  for (Event ev : events) {
    double neededTime = ev.i + ev.t;
    if (T > neededTime) return -1; // Implies it is impossible to deliver on time.
    if (T <= ev.t && ev.t <= neededTime) {
      minSpeed = min(minSpeed, (ev.i - D) / (ev.t - T));
    }
    if (ev.t == neededTime) T = ev.t;
    D = ev.i;
  }
  return minSpeed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int, int>> stations(N);
    for (int i = 0; i < N; i++) {
      cin >> stations[i].first >> stations[i].second;
    }
    cout << "Case #" << t << ": " << fixed << setprecision(8)
         << findMinSpeed(stations) << endl;
  }
  return 0;
}
