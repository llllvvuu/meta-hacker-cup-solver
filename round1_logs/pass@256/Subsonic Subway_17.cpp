
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

const double EPS = 1e-6;
const double INF = 1e12;

// Function to assess if a speed works
bool assessSpeed(double speed, const vector<pair<double, double>>& intervals) {
  for (auto& [lb, ub] : intervals) {
    if (speed < lb || speed > ub) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<double, double>> intervals(N);
    for (int i = 0; i < N; i++) {
      int Ai, Bi;
      cin >> Ai >> Bi;
      intervals[i] = {1.0 * Ai / (i + 1), 1.0 * Bi / (i + 1)};
    }

    // Find extreme bounds of intervals
    double l = INF, r = -INF;
    for (auto [lb, ub] : intervals) {
      l = min(l, lb);
      r = max(r, ub);
    }

    // Binary search for smallest valid speed
    vector<double> distances;
    for (double d = l; d <= r + EPS; d += 1.0/N) {
      distances.push_back(d);
    }
    sort(distances.begin(), distances.end());
    for (double speed : distances) {
      if (assessSpeed(speed, intervals)) {
        cout << "Case #" << t << ": " << speed << endl;
        break;
      }
    }
    if (distances.back() == r) cout << "Case #" << t << ": -1";
  }
  return 0;
}
