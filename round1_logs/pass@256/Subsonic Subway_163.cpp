
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
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct Close {
    int time;
    bool operator<(Close a) const { return time < a.time; }
    bool operator>(Close a) const { return time > a.time; }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    vector<vector<long long>> windows(N, vector<long long>(2));
    set<Close> openIntervals;
    priority_queue<long double> highestBounds;

    for (int i = 0; i < N; i++) {
      cin >> windows[i][0] >> windows[i][1];
      windows[i][0] = windows[i][1] - windows[i][0];
      windows[i][1] = (long long) (1e18 + 1000);
    }

    for (int i = 0; i < N; i++) {
      windows[i][0] = windows[i][0] / (1ll * (i + 1));
      windows[i][1] = windows[i][1] / (1ll * (i + 1));
    }

    vector<pair<long long, pair<long long, bool>>> events;
    for (int i = 0; i < N; i++) {
      events.push_back({windows[i][0], {i, false}}); // Start event
      events.push_back({windows[i][1], {i, true}});  // End event
    }

    sort(events.begin(), events.end());

    for (auto e : events) {
      if (!e.second.second) {
        if (!openIntervals.count(Close{e.second.first})) {
          highestBounds.push(1.0 / e.first);
          if (highestBounds.size() == 1) openIntervals.insert(Close{e.second.first});
        }
      } else {
        highestBounds.pop();
        auto it = openIntervals.find(Close{e.second.first});
        if (!it->time) return 0;
        openIntervals.erase(it);
        if (highestBounds.size() == 1) openIntervals.insert(Close{e.second.first});
      }
    }

    long double highestInterval = highestBounds.top();
    highestInterval = highestInterval >= (1e9+10) ? -1 : highestInterval;
    cout << highestInterval << endl;
  }
}
