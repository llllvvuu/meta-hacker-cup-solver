
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

double computeMinSpeed(int N, vector<pair<int, int>>& windows) {
  // Sort the stations by their schedules
  sort(windows.begin(), windows.end());
  // Binary search the constant speed
  auto& [a, b] = windows.back(); 
  double left = min(left, a / (double)N);
  double right = min(left, b / (double)(N + 1));
  double ans = -1;
  while (right >= left + 1e-8) {
    double mid = (left + right) / 2;
    bool canDeliver = true;
    for (int i = 1; i <= N; i++) {
      auto [ai, bi] = windows[i - 1];
      if (a / (double)i > b / (double)(i + 1)) {
        canDeliver = false;
        break;
      }
      double deliveryEnd = i * mid; 
      if (a / (double)i + 1e-8 >= deliveryEnd
        || deliveryEnd >= b / (double)(i + 1))
        canDeliver = false;
    }
    if (canDeliver)
      ans = mid, right = mid;
    else
      left = mid;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int, int>> windows(N);
    for (auto &i : windows) cin >> i.first >> i.second;
    double speed = computeMinSpeed(N, windows);
    cout << "Case #" << t << ": ";
    cout << fixed << setprecision(8) << speed << '\n';
  }
  return 0;
}
