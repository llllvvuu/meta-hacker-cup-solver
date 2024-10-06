
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

const double EPS = 1e-8;

struct Station {
    int si, ei;
};

bool canDeliver(vector<Station>& stations, double v) {
    int curr = 0;
    for (int i = 0; i < (int)stations.size(); i++) {
        if (v == 0 && stations[i].si > 0) return false;
        double toInit = stations[i].si - curr;
        if (v > 0 && toInit > v * stations[i].ei) return false;
        int crossing = max(0, ceil(toInit / v));
        curr = stations[i].ei + crossing;
    }
    return true;
}

double solve(vector<Station>& stations) {
    sort(stations.begin(), stations.end(), [](const Station& x, const Station& y) { return x.si < y.si; });
    double lo = 0, hi = 1e9;
    for (int i = 0; i < 80; i++) {
        double v = (lo + hi) / 2;
        if (canDeliver(stations, v)) {
            hi = v;
        } else {
            lo = v;
        }
    }
    double ans = hi;
    return abs(ans - lo) > EPS ? -1 : ans;
}

int main() {
   int T;
   cin >> T;
   for (int t = 1; t <= T; t++) {
      int N;
      cin >> N;
      vector<Station> stations(N);
      for (auto &s : stations) {
            cin >> s.si >> s.ei;
      }
      cout << "Case #" << t << ": " << solve(stations) << endl;
   }
   return 0;
}
