
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
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double INF = 1e10;

int main() {
  int test_cases;
  cin >> test_cases;
  for (int caseno = 1; caseno <= test_cases; caseno++) {
    int N;
    cin >> N;
    vector<pair<double, int>> left, right;
    for (int i = 1; i <= N; i++) {
      int a, b;
      cin >> a >> b;
      left.push_back({1.0 * i / b, 1});
      right.push_back({1.0 * i / a, -1});
    }
    left.push_back({0, 0});
    right.push_back({INF, -1});
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    vector<double> l;
    for (auto &p: left) l.push_back(p.first);
    for (auto &p: right) l.push_back(p.first);
    sort(l.begin(), l.end());
    l.erase(unique(l.begin(), l.end()), l.end());
    double *v = new double[l.size()];
    v[0] = 0;
    for (int i = 1; i < l.size(); i++) {
      v[i] = (l[i] + l[i-1]) / 2;
    }
    int accept = 0;
    for (auto p: left) accept += p.second;
    double ans = 1;
    for (int i = (int)v.size()-1; i >= 0; i--) {
      while((!right.empty() && right.back().first >= v[i]) || accept == N) {
        if (!right.empty()) {
          accept += right.back().second;
          right.pop_back();
        } else {
          break;
        }
      }
      if (i != (int)v.size()-1) ans = min(ans, v[i]);
      while (!left.empty() && left.back().first >= v[i]) {
        accept += left.back().second;
        left.pop_back();
      }
    }
    cout << "Case #" << caseno << ": " << (ans >= INF-EPS ? -1 : ans) << "\n";
  }
  return 0;
}
