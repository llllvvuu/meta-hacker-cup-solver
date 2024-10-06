
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

void solve() {
  int N;
  cin >> N;

  vector<int> al(N), bl(N);
  for (int i = 0; i < N; i++) {
    cin >> al[i] >> bl[i];
  }

  double lo = 0;
  double hi = N;
  const double th = 1e-9;

  while (hi - lo > th) {
    double mid = (lo + hi) / 2;
    bool feasible = true;
    double cur = 0;
    for (int i = 0; i < N; i++) {
      cur = min(DBL_MAX, cur + 1.0 / mid);
      if (bl[i] < cur) {
        feasible = false;
        break;
      }
      if (al[i] > cur) cur = al[i];
    }
    if (feasible) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << fixed << hi << "\n";
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
