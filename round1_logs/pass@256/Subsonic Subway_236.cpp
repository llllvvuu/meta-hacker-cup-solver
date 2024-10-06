
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
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
  int x, y, ty;
};

bool operator<(const Point& p, const Point& q) {
  return (p.x != q.x) ? p.x < q.x : p.ty < q.ty;
}

double solve() {
  int N;
  cin >> N;
  vector<Point> points;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    points.push_back({i, A, 0});
    points.push_back({i + 1, B, 1});
  }
  sort(points.begin(), points.end());

  vector<int> low(N, -1), high(N, 1e9 + 1);
  int start = 1e9 + 1;
  for (const Point& p : points) {
    if (p.ty == 0) start = min(start, p.y);
    else if (p.x > 0) {
      if (start <= p.y - 1) return -1;
      low[p.x - 1] = start;
      high[p.x - 1] = p.y;
    }
  }

  double min_speed = 1e9 + 1;
  int prev_high = 0;
  for (int i = 0; i < N; i++) {
    min_speed = min(min_speed, (double)(high[i] + i - prev_high) / (i - prev_high));
    prev_high = high[i];
  }

  return min_speed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << fixed << setprecision(6) << 
      solve() << endl;
  }
  return 0;
}
