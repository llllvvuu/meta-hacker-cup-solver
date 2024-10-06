
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
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    vector<double> min_speeds(n + 1), max_speeds(n + 1);
    for (int j = 1; j <= n; j++) {
      int a, b;
      cin >> a >> b;
      min_speeds[j] = n / (double) b;
      max_speeds[j] = n / (double) a;
    }
    double best_min_speed = numeric_limits<double>::max();
    double best_max_speed = -numeric_limits<double>::max();
    for (int j = 1; j <= n; j++) {
      best_min_speed = min(best_min_speed, min_speeds[j]);
      best_max_speed = max(best_max_speed, max_speeds[j]);
    }
    if (best_min_speed > best_max_speed) {
      cout << "Case #" << i << ": " << -1 << endl;
    } else {
      cout << "Case #" << i << ": " << fixed << setprecision(7) << best_min_speed << endl;
    }
  }
}
