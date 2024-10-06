
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
#include <cmath>
#include <algorithm>
using namespace std;

bool canDeliverSonic(double speed, const vector<pair<int, int>>& deliveries) {
  double current_time = 0.0;
  for (int i = 1; i < deliveries.size(); ++i) {
    double dist = i;
    double arrival_time = current_time + dist / speed;
    current_time = max(arrival_time, (double)delic[i - 1].second);
    if (arrival_time < (double)delic[i].first) {
      return false;
    }
  }
  return true;
}

double findMinimumSpeed(const vector<pair<int, int>>& deliveries) {
  double low = 0.0, high = 1000000;
  for (int _ = 0; _ < 50; ++_) { // Binary search iterations.
    double mid = (low + high) / 2.0;
    if (canDeliverSonic(mid, deliveries)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return (high - low) / 2.0 + low;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int, int>> deliveries(N, { 0, 0 });
    for (int i = 0; i < N; i++) {
      cin >> deliveries[i].first >> deliveries[i].second;
    }
    double min_speed = findMinimumSpeed(deliveries);
    cout << "Case #" << t << ": ";
    if (min_speed >= 1000000.0) {
      cout << -1 << endl;
    } else {
      cout << min_speed << endl;
    }
  }
  return 0;
}
