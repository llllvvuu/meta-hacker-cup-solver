
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

struct Interval {
  double start;
  double end;

  bool operator<(const Interval &other) const {
    return start < other.start || (start == other.start && end < other.end);
  }
};

double minSpeed(int N, vector<pair<int,int>> &A) {
  vector<Interval> intervals;
  for (int i = 0; i < N; ++i) {
    intervals.push_back({(double)(A[i].first) / (double)(i + 1), (double)(A[i].second) / (double)(i + 1)});
  }

  sort(intervals.begin(), intervals.end());
  double speed = 0.0, end = 0.0;

  for (int i = 0; i < intervals.size(); ++i) {
    if (i == 0 || intervals[i].start > end) return -1;

    speed = max(speed, (double)1 / intervals[i].end);
    end = intervals[i].end;
  }

  return speed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i].first >> A[i].second;
    } 
    cout << "Case #" << t << ": " << setprecision(6) << minSpeed(N, A) << endl;
  }
  return 0;
}
