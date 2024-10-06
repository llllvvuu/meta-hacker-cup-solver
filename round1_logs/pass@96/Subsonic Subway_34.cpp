
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

int main() {
  int T;
  cin >> T;
  vector<pair<int, int>> events[200001];
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      events[a].push_back({b, 1});
      events[b + 1].push_back({b, -1});
    }

    vector<pair<int, int>> intervals;
    int currentEnd = 0;
    for (int i = 0; i < 200000; i++) {
      for (auto e : events[i]) {
        if (currentEnd == 0 && e.second == -1) {
          printf("Case #%d: -1\n", t);
          goto skip;
        }
        currentEnd += e.second;
      }
      if (currentEnd > 0) {
        if (!intervals.empty() && intervals.back().second == i)
          intervals.back().second++;
        else
          intervals.push_back({i, i + 1});
      }
      currentEnd = 0;
    }
    double minSpeed = 1e9, maxReach = 0;
    for (auto &intv : intervals) {
      minSpeed = min(minSpeed, (double)intv.second / (double)intv.first);
      maxReach = max(maxReach, (double)intv.second);
    }
    printf("Case #%d: %.9f\n", t, 1.0 / max(0.0000000001, minSpeed));
skip:;
  }
  return 0;
}
