
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
const int MAXN = 1000000 + 5;
int n;
double a[MAXN], b[MAXN];

int main() {
  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
    }

    vector<pair<double, int>> vec;

    for (int i = 1; i <= n; i++) {
      vec.push_back({a[i] / i, i});
      vec.push_back({b[i] / i, i});
    }

    sort(vec.begin(), vec.end());

    double maxa = -1e15, res = -1;
    set<int> ps, ns;
    for (auto it : vec) {
      if (it.second == 1) {
        ps.insert(it.first);
      } else {
        ns.insert(it.first);
      }
      if (ps.lower_bound(it.first) != ps.end()) maxa = max(maxa, *ps.lower_bound(it.first));
      if (!ns.empty() && ps.size() - ns.size() > 0) continue;
      
      if (ps.size() && maxa <= *ps.rbegin()) {
        res = maxa;
      }
      if (ns.count(it.first)) ps.erase(it.first);
    } 

    printf("Case #%d: %0.9f\n", testCase, res);
  }
}
