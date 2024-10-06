
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
#include <cmath>
#include <iostream>
using namespace std;

const double INF = 1e9;

double solve() {
  int n;
  cin >> n;
  vector<pair<double, double>> pairs(n);
  for (double& p : pairs) {
    cin >> p.first >> p.second; // (A_i, B_i)
  }
  pairs.emplace_back(INF, INF); // sentinel
  double leftmost = 0;
  double min_speed = 0;
  for (int i = 0; i < n; i++) {
    double a = pairs[i].first, b = pairs[i].second;
    if (b < leftmost) return -1; // impossible
    if ((b - i) < min_speed) min_speed = b - i;
    leftmost = min(leftmost, min(a, b));
  }
  return 1 / min_speed;
}

int main() {
  int t;
  cin >> t;
  for (int case_id = 1; case_id <= t; case_id++) {
    cout << "Case #" << case_id << ": " << solve() << '\n';
  }
  return 0;
}
