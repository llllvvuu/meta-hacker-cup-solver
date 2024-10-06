
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
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> events;

double calcSpeed() {
  vector<pair<double, int>> openings;
  vector<pair<double, int>> closings;
  for (int i = 0; i < N; i++) {
    openings.push_back({events[i].first, i});
    closings.push_back({events[i].second, i});
  }
  sort(openings.begin(), openings.end());
  sort(closings.begin(), closings.end());

  int open = 0;
  int close = 0;
  int currStation = -1;
  double timePassed = 0;
  double minSpeed = 1e10;
  while (open < N && timePassed >= 0) {
    timePassed = max(timePassed, 1.0 / openings[open].first);
    
    while (close < N && closings[close].first <= timePassed) {
      currStation = closings[close].second;
      close++;
    }

    if (currStation == -1) {
      // see if it's feasible to have all stations open when we arrive
      minSpeed = min(minSpeed, 1.0 / openings[open].first);
    } else {
      // find the gap between the last open time and next close time
      double maxVelocity =
          (closings[close].first - openings[openings.size() - 1].first) - (currStation + 1);
      minSpeed = min(minSpeed, 1.0 / (maxVelocity + currStation + 1));
    }
    open++;
  }
  return minSpeed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    events.clear();

    cin >> N;
    events.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> events[i].first >> events[i].second;
    }
    double result = calcSpeed();
    if (result >= 1e10) {
      cout << "Case #" << t << ": -1" << endl;
    } else {
      cout << "Case #" << t << ": " << result << endl;
    }
  }
  return 0;
}
