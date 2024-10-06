
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
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

const int maxDist = 1e6 + 5;

struct station {
  int left, right, dist;
  station(int d, int l, int r) : dist(d), left(l), right(r) { }
  bool operator<(const station &b) const {
    return dist < b.dist;
  }
};

double solve() {
  int n;
  cin >> n;
  vector<station> stations(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    stations[i] = station(i + 1, a, b);
  }
  sort(stations.begin(), stations.end());
  double l = 0, r = maxDist;
  for (int iters = 0; iters < 100; iters++) { // good to have more than 50
    double mid = (l + r) / 2;
    if (mid == 0) { // Processing corner case 0 (Binary search converged to)
      if (stations[0].left > 0)
        return -1.0;
      if (stations.size() > 1 && stations[1].left > 1.0)
        return -1.0;
      if (stations.size() == 1)
        return mid;
    }
    long long current_time = 0;
    for (int i = 0; i < n; i++) {
      long long travel_time = (long long)mid * stations[i].dist;
      if (current_time + travel_time > stations[i].right)
        return -1.0;
      long long next_time = current_time + travel_time;
      if (next_time < stations[i].left) {
        if (next_time + stations[i].left - current_time - travel_time > stations[i].right)
          return -1.0;
        next_time = stations[i].left;
      }
      current_time = next_time + stations[i].dist / mid;
    }
    if (current_time <= maxDist)
      r = mid; // left station definately fits, check lower speeds
    else
      l = mid;
  }
  return l;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << setprecision(15) << solve() << endl;
  }
  return 0;
}
