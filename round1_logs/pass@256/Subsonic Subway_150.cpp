
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
#include <vector>
#include <iostream>
using namespace std;

#define ll long long
const int MAXN = 1e6 + 5;

struct Event {
  int where, when;
  bool operator<(const Event& e) const {
    return when < e.when;
  }
};

int A[MAXN], B[MAXN];

double min_speed(int n) {
  vector<Event> events;
  for (int i = 1; i <= n; ++i) {
    events.emplace_back(i, A[i]);
    events.emplace_back(i, B[i]);
  }
  sort(events.begin(), events.end());

  int end_time = 0;
  double lo = 0, hi = MAXN;
  while (hi - lo > 1e-9) {
    double mi = (lo + hi) / 2;
    end_time = 0;
    bool ok = true;
    for (int i = 0; i < (int) events.size() && ok; ++i) {
      if (events[i].where > end_time) {
        if (events[i].when < events[i].where / mi) {
          ok = false;
        }
        end_time = events[i].where;
      }
    }
    if (ok) {
      hi = mi;
    } else {
      lo = mi;
    }
  }
  return min(mi, MAXN);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {  
        int n;
        cin >> n;
        for (int j = 1; j <= n; ++j) cin >> A[j] >> B[j];
        cout << "Case #" << i << ": " << fixed << setprecision(6) << min_speed(n) << '\n';
    }
    return 0;
}
