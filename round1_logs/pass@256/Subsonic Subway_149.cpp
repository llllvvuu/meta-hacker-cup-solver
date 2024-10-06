
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

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<pair<long long, long long>> stations(N);
    for (int i = 0; i < N; ++i)
      cin >> stations[i].first >> stations[i].second;

    sort(stations.begin(), stations.end());
    const int INF = 1e9;  // Arbitrary large value.
    double low = 0, high = INF;
    while (high - low > 1e-6) {  // Criterion for approximation
      double speed = low + (high - low) / 2;
      double arrival = 0;
      bool feasible = true;
      for (int i = 0; i < N; ++i) {
        arrival += 1.0 / speed;
        if (arrival < stations[i].first || arrival > stations[i].second) {
          feasible = false;
          break;
        }
      }
      if (feasible)
        high = speed;
      else
        low = speed;
    }
    if (low == INF)
      cout << "Case #1: " << -1 << '\n';
    else
      cout << "Case #" << T+1 << ": " << low << '\n';  // Adjust T for 1-indexed cases
  }
}
