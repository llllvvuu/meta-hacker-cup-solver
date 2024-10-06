
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
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Event {
  int distance; // Distance from Sonic
  int time; // Time of event
  int windowStart; // Marks the beginning of a window
};

bool compareEvents(const Event &a, const Event &b) {
  return (double)a.distance / a.time < (double)b.distance / b.time ||
         (double)a.distance / a.time == (double)b.distance / b.time &&
             a.time < b.time;
}

double solve() {
  int n;
  cin >> n;
  vector<Event> events(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> events[i].time >> events[i + n].time;
    events[i].distance = i + 1;
    events[i].windowStart = 1;
    events[i + n].distance = i + 1;
    events[i + n].windowStart = 0;
  }

  sort(events.begin(), events.end(), compareEvents);

  double max_speed = -1;
  priority_queue<pair<double, int>, vector<pair<double, int> >,
                 greater<pair<double, int> > >
      pq; // End time, start distance

  double susp = -1e9 - 1; // Initialize it very early

  for (auto event : events) {
    while (pq.size() > 0 && event.time > pq.top().first) {
      pq.pop();
    }
    if (event.windowStart) {
      // Until now, there was no valid start time so we aren't sure the speed
      // will work yet.
      if (event.time >= susp) {
        pq.push({event.time, event.distance});
      } else {
        // The event has already passed, or will pass any way, ignore it.
      }
    } else {
      // We don't know if the event window could still be ongoing at the current
      // time
      while (pq.size() > 0 && event.time >= pq.top().first - pq.top().second) {
        susp = pq.top().first;
        pq.pop();
      }
      if (pq.size() > 0) {
        max_speed = max(max_speed, (double)pq.top().second / pq.top().first);
      }
    }
  }
  return max_speed < 0 ? -1 : max_speed;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << fixed << setprecision(6) << solve() << '\n';
  }
  return 0;
}
