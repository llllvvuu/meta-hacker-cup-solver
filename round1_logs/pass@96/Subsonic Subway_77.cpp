
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

const double eps = 1e-10;

void solve() {
  int N;
  cin >> N;
  vector<double> starts(N), ends(N);
  vector<pair<int, int>> intervals(N);
  vector<double> times;
  
  for (int i = 0; i < N; i++) {
    cin >> intervals[i].second >> intervals[i].first;
    starts[i] = (double)intervals[i].second / (i + 1.0);
    ends[i] = (double)intervals[i].first / (i + 1.0);
    times.push_back(starts[i]);
    times.push_back(ends[i]);
  }
  
  // sort times to prepare for sweep line
  sort(times.begin(), times.end());
  const double delta = times[0] * eps;
  vector<vector<int>> sweep_line;
  for (int i = 0, sz = times.size(); i < sz; i++) {
    if (i > 0 && abs(times[i] - times[i - 1]) < delta) continue;
    sweep_line.push_back({i, 0});
  }
  
  for (int i = 0; i < N; i++) {
    auto lb = lower_bound(sweep_line.begin(), sweep_line.end(),
                          make_pair(starts[i], 0));
    lb->second += 1;
    auto ub = lower_bound(sweep_line.begin(), sweep_line.end(),
                          make_pair(ends[i] + delta, 0));
    if (ub == sweep_line.end() || (ub->first > ends[i] + delta)) ub--;
    ub->second -= 1;
  }
  
  double speed = -1;
  int count = 0;
  for (auto [time, delta_count] : sweep_line) {
    count += delta_count;
    if (count > 0) {
      speed = time;
    }
  }
  cout << speed << endl; 
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
  	cout << "Case #" << t << ": ";
  	solve();
  }
  return 0;
}
