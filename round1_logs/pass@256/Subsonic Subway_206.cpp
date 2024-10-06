
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
#include <queue>
#include <vector>
using namespace std;

struct Interval {
  double low, high;
  
  Interval(double l, double h) : low(l), high(h) {}
};

bool operator < (const Interval &a, const Interval &b) {
  return a.low < b.low;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<Interval> intervals(N);
    
    for (int i = 0; i < N; ++i) {
      long long a, b;
      cin >> a >> b;
      intervals[i] = Interval(1.0 * (i + 1) / b, 1.0 * (i + 1) / a);
    }
    
    // Sorting and pruning
    sort(intervals.begin(), intervals.end());
    priority_queue<double, vector<double>, greater<double>> pq;
    double maxS = 0;
    for (auto interval : intervals) {
      while (!pq.empty() && pq.top() < interval.low) {
        pq.pop();
      }
      if (pq.empty()) {
        cout << "Case #" << t << ": -1\n";
        goto skip;
      }
      maxS = max(maxS, pq.top());
      pq.push(interval.high);
    }
    cout << "Case #" << t << ": " << maxS << endl;
skip:;
  }
  return 0;
}
