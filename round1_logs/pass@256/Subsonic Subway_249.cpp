
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

struct station {
  double arrive; // desired arrival time
  double timeWindow; // time window length
};

const double EPS = 1e-7; // desired precision

bool canDeliverAtSpeed(const vector<station> &stations, double speed) {
  for (int i = 0; i < stations.size(); i++) {
    double arrival = stations[i].arrive;
    double timeWindow = stations[i].timeWindow;
    double timeGap = arrival + timeWindow - (i + 1) / speed; // time diff to arrive before window ends
    if (timeGap >= 0) continue; // ok to arrive on time
    if ((i == 0 || (i > 0 && stations[i - 1].arrive + stations[i - 1].timeWindow > arrival - EPS)) &&
        (i == stations.size() - 1 ||
         (arrival - EPS < stations[i + 1].arrive && arrival + timeWindow < stations[i + 1].arrive + stations[i + 1].timeWindow))) {
      // this region is unreachable even at higher speeds!
      return false;
    }
  }
  return true;
}

double minSpeed(vector<station> &stations) {
  double minSpeed = 0, maxSpeed = 1e9;
  while (minSpeed < maxSpeed) {
    double midSpeed = midSpeed = (minSpeed + maxSpeed) / 2;
    if (canDeliverAtSpeed(stations, midSpeed)) {
      maxSpeed = midSpeed;
    } else {
      minSpeed = midSpeed;
    }
  }
  // make sure corner case of no speed is covered
  return minSpeed < 1e9 ? (minSpeed + maxSpeed) / 2 : -1;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<station> stations(N);

    for (int i = 0; i < N; i++) {
      cin >> stations[i].arrive >> stations[i].timeWindow;
    }

    sort(stations.begin(), stations.end(), [](const station &s1, const station &s2) { 
        return s1.arrive < s2.arrive; });

    double result = minSpeed(stations);
    cout << "Case #" << t << ": " << result << endl;
  }
  return 0;
}
