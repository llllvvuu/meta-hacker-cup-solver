
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

const double L = -1;

struct Interval {
  int a;
  int b;
  int pos;
  Interval(int p, int x, int y) : a(x), b(y), pos(p) {}
  
  bool operator< (const Interval& o) const {
    return b < o.b;
  }
};

double solve(vector<Interval>& vec) {
  int N = vec.size();
  sort(vec.begin(), vec.end());
  
  double minBefore = vec[0].a * 1.0 / vec[0].b;
  double minDiff = 1.0 / vec[0].b;
  const double INF = 1e9;
  for (int i = 1; i < N; i++) {
    double currentSpeed = vec[i].a * 1.0 / vec[i].b;
    if (minBefore > currentSpeed) return INF;
    minDiff = max(minBefore, currentSpeed);
    minBefore = vec[i].a;
  }
  return minDiff;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<Interval> vec(N);

    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      vec[i] = Interval(i, a, b);
    }
    double result = solve(vec);
    
    cout << "Case #" << t << ": " << (result == INF ? -1 : result) << endl;
  }
  return 0;
}
