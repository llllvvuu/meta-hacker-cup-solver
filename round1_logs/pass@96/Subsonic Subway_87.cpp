
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
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

struct DeliveryWindow {
  int i; // station index
  int a, b; // delivery window [A, B]
  int distance; // distance to station i

  DeliveryWindow(int i, int a, int b, int distance) : i(i), a(a), b(b), distance(distance) {}

  // ix used for sorting by closing delivery times
  bool operator < (const DeliveryWindow &other) const {
    return b < other.b;
  }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    vector<DeliveryWindow> intervals;
    int N;
    cin >> N;

    // Populate delivery windows and distances
    for (int i = 1; i <= N; ++i) {
      int A, B;
      cin >> A >> B;
      intervals.emplace_back(i, A, B, i); // distance to station i (i.e., the station index)
    }

    // Add virtual delivery windows with extreme boundaries
    intervals.push_back({0, 0, 0, 0});
    intervals.push_back({N + 1, 1000001, 1000001, 0});

    // Sort by closing time of the delivery window
    sort(intervals.begin(), intervals.end());

    long double time = 0;
    long double distance = 0;
    bool isClockWise = true;
    int cursor = 0;

    while (cursor < N) {
      int start = cursor;
      int end = N;
      while (intervals[start].b == intervals[start + 1].b) {
        start++;
      }
      if (start < end - 1) {
        long double timeDifference = abs((long double)(intervals[start].b - intervals[end].b));
        long double distanceDifference = abs(intervals[end].distance - intervals[start].distance);
        long double requiredSpeed = distanceDifference / timeDifference;

        if (intervals[start].i < intervals[end].i) { // Clockwise delivery is planned
          if (time + timeDifference > intervals[start].b) return -1; // Impossibility check
          distance += distanceDifference;
          time += timeDifference;
          isClockWise = true;
        } else {
          if (time + timeDifference > intervals[start].b) return -1; // Impossibility check
          distance -= distanceDifference;
          time += timeDifference;
          isClockWise = false;
        }
      }
      cursor = start + 1;
    }

    double minspeed = distance / time;
    cout << "Case #" << t << ": " << minspeed << endl;
  }

  return 0;
}
