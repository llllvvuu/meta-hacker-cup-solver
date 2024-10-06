
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

double solve(int N, vector<pair<double, double>>& intervals) {
  sort(intervals.begin(), intervals.end());
  int lastClosed = -1;
  for (auto& [x, y] : intervals) {
    if (lastClosed != -1 && x > lastClosed) return -1;
    lastClosed = max(lastClosed, (int) y);
  }
  return 1.0 / lastClosed;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N; cin >> N;
    vector<pair<double, double>> intervals(N);
    for (auto& [x, y] : intervals) cin >> x >> y, x--, y--;
    cout << "Case #" << t << ": " << fixed << setprecision(12) << solve(N, intervals) << "\n";
  }
  return 0;
}
