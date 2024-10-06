
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

struct Station {
  int A;
  int B;
  int index;
};

bool compare(Station a, Station b) { return a.B / a.index < b.B / b.index; }

double solve(vector<Station> stations, int n) {
  sort(stations.begin(), stations.end(), compare);
  vector<double> H(n);
  for (int i = 0; i < n; ++i) {
    H[i] = min(1.0, min((stations[i].index) / double(stations[i].A),
                        (n - stations[i].index + 1) / double(stations[i].B)));
  }
  sort(H.begin(), H.end(), greater<double>());
  double lo = 0.0, hi = 1.0;
  for (double h = H[0]; lo + 1e-6 < hi; ) {
    double mid = (lo + hi) / 2.0;
    double max_seen = 0;
    for (int i = 0; i < n; ++i) {
      max_seen = max(max_seen, (stations[i].index - 1) / stations[i].A);
      if (max_seen + mid > (n - stations[i].index) / stations[i].B)
        break;
    }
    if (max_seen + mid <= (n - stations[n - 1].index) / stations[n - 1].B)
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<Station> stations(N);
    for (int i = 0; i < N; ++i) {
      cin >> stations[i].A >> stations[i].B; 
      stations[i].index = i + 1; // 1-based index
    }
    double ans = solve(stations, N);
    cout << "Case #" << t << ": " << fixed << setprecision(7) << ans << endl;
  }
}
