
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

typedef long double ld;

vector<pair<ld, ld>> intervals;

ld determine_speed(int N) {
    pair<ld, ld> current = {-INFINITY, -INFINITY};
    for (int i = 0; i < N; i++) {
        ld a = intervals[i].first;
        ld b = intervals[i].second;
        if (b < current.second) return -1;  // window collision
        if (a <= current.first) continue;  // within existing interval

        // extend the interval
        current = {current.first, b};
        if (ld dist = b - current.first; dist > 0) {
            return dist / (b - i);  // min speed
        }
    }
    return 0;  // arbitrarily small positive speed
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    intervals.clear();
    intervals.reserve(N);
    ld greatest_pretail = -INFINITY, greatest_after = INFINITY;
    for (int i = 0; i < N; i++) {
      int first, second;
      cin >> first >> second;
      greatest_pretail = max(greatest_pretail, (ld)first - i);
      greatest_after = min(greatest_after, (ld)second - i);
      intervals.emplace_back(first - i, second - i);
    }
    if (greatest_pretail > greatest_after) {
      cout << "Case #" << t << ": -1\n";
      continue;
    }
    sort(intervals.begin(), intervals.end());
    cout << "Case #" << t << ": " << fixed << setprecision(8) << determine_speed(N) << '\n';
  }
  return 0;
}
