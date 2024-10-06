
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
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const double EPS = 1e-6;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int, int>> stations(N);
    for (int i = 0; i < N; i++) {
      cin >> stations[i].second >> stations[i].first; // Reversed for later sorting by open time
    }
    sort(stations.begin(), stations.end());
    int max_d = -1, min_t = -1;
    bool impossible = false;
    for (int i = 0; i < N; i++) {
      if (stations[i].second <= i + 1 && max_d < i + 1) {
        max_d = i + 1;
        min_t = stations[i].first;
      }
      if (stations[i].first >= i + 2 && max_d >= min_t - 1) {
        impossible = true;
        break;
      }
    }
    double speed;
    if (impossible) speed = -1.0;
    else if (max_d == -1 || min_t == -1) speed = 0.0;
    else speed = (double)max_d / min_t;
    cout << "Case #" << t << ": ";
    cout << fixed << setprecision(6) << speed << endl;
  }
  return 0;
}
