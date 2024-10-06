
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
#include <algorithm>
#include <utility>
using namespace std;

const double INF = 1e9;

double solve(vector<pair<int, int>>& windows) {
  if (empty(windows)) return 0;
  double max_low = 0, min_high = INF;
  for (auto [a, b] : windows) {
    max_low = max(max_low, 1.0 / b);
    min_high = min(min_high, 1.0 / a * (windows.back().second));
  }
  if (min_high < max_low) return -1;
  return 1.0 / max_low;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; ++i) {
      cin >> (intervals[i].first) >> (intervals[i].second);
    }
    cout << "Case #" << t << ": " << solve(intervals) << endl;
  }
  return 0;
}
