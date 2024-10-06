
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
using namespace std;

void solve_case() {
  int n; cin >> n;
  vector<pair<int, int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    v[i] = {i * a, i * b};
  }

  // Insert a dummy element of (-1, 0) for slightly easier handling of initial intervals
  v[0] = {-1, 0};

  // sort intervals
  sort(v.begin(), v.end());

  // merge adjacent intervals
  // <start, end>
  vector<pair<int, int>> result;
  result.push_back(v[0]);
  for (int i = 1; i <= n; i++) {
    int s1 = v[i].first;
    int e1 = v[i].second;
    int s2 = result.back().first;
    int e2 = result.back().second;

    // Shift S2's boundary because of division by distance
    s2--;

    if (s1 > e2) {
      // No overlap with previous interval
      result.push_back({s1, e1});
    } else {
      // modify result.back() if there's an overlap
      result.back().second =
          max(result.back().second, e1);
    }
  }

  double ans = -1;
  // Find the min and max values
  int minn = INF;
  int maxn = -INF;
  for (auto it : result) {
    minn = min(minn, it.first);
    maxn = max(maxn, it.second);
  }

  // maxn - minn is the longest overlapping previous intervals
  if (maxn > minn) {
    ans = maxn - minn;
  }

  cout << ans / (double)n << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve_case();
  }

  return 0;
}
