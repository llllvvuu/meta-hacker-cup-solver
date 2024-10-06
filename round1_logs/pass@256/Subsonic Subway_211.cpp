
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
#include <cmath>
using namespace std;

double findMinimumSpeed(const vector<pair<int, int>>& stations) {
  double minv = 1e9;  // Maximum possible speed, assuming far worst case
  double maxv = 0;    // Minimum possible speed, assuming far worst case

  int N = stations.size();
  if (N == 0) return -1;

  for (int i = 1; i <= N; ++i) {
    double lowerBound = i * 1.0 / stations[i - 1].second;  // = i / B_i
    double upperBound = i * 1.0 / stations[i - 1].first;   // = i / A_i

    if (upperBound < minv)
      minv = upperBound;
    if (lowerBound > maxv)
      maxv = lowerBound;
  }

  if (minv > maxv)
    return -1;
  return minv;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int, int>> stations(N);
    for (int i = 0; i < N; ++i) {
      cin >> stations[i].first >> stations[i].second;
    }
    double speed = findMinimumSpeed(stations);
    cout << "Case #" << t << ": " << fixed << speed << endl;
  }
  return 0;
}
