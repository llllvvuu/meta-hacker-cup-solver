
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
struct Station {
  int dist;
  double min, max;
};

bool comp(Station s1, Station s2) {
  return s1.max < s2.max;
}

double eps = 1e-9;

bool canSonicRun(Station sts[], int n) {
  sort(sts, sts + n, comp);
  double minSpeed = sts[0].dist / sts[0].max;
  double maxSpeed = minSpeed + 1;
  while (maxSpeed - minSpeed > eps) {
    double midSpeed = (minSpeed + maxSpeed) / 2;
    double curPos = 0.0;
    bool works = true;
    for (int i = 0; i < n; i++) {
      double needed = (double)sts[i].dist - curPos;
      if (needed / midSpeed > sts[i].max - curPos) {
        works = false;
        break;
      }
      curPos = (double)sts[i].dist;
    }
    if (works) {
      maxSpeed = midSpeed;
    } else {
      minSpeed = midSpeed;
    }
  }
  return works;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    Station* sts = new Station[N];
    for (int i = 0; i < N; i++) {
      cin >> sts[i].min >> sts[i].max;
      sts[i].dist = i + 1;
    }
    string ans = canSonicRun(sts, N) ? to_string(sts[0].dist / sts[0].max) : "-1";
    cout << fixed << setprecision(10) << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
