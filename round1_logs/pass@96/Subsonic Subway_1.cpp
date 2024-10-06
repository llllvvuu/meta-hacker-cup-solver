
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
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int T, N;
int A[1000009], B[1000009];

bool check(double speed) {
  vector<pair<double, int>> events;
  for (int i = 1; i <= N; i++) {
    double time = 1.0 * i / speed;
    events.push_back(make_pair(time, -1));
    events.push_back(make_pair(time + 1.0 * i / speed, 1));

    for (int op : {-1, 1}) {
      int time = 1.0 * i / speed * op;
      events.push_back({A[i] + time, -op});
      events.push_back({B[i] + time + 1e-9, op}); // 1e-9 for floating point precision
    }
  }
  sort(events.begin(), events.end());

  int active_deliveries = 0;
  for (auto [time, op] : events) {
    active_deliveries += op;
    if (active_deliveries > N) {
      return false;
    }
  }

  return true;
}

void solve() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i] >> B[i];
  }
  double low = 0, high = 1e9;
  while (high - low > 1e-7) {
    double mid = (low + high) / 2;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << fixed << setprecision(8);
  cout << "Case #1: " << high << endl;
}

int main() {
  int numTestCases;
  cin >> numTestCases;
  for (int testCase = 1; testCase <= numTestCases; testCase++) {
    solve();
  }
  return 0;
}
