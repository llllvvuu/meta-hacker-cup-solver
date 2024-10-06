
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

const double INF = 100000000;
const double epsilon = 1e-6;

double max(double a, double b) {
  return a > b ? a : b;
}

double min(double a, double b) {
  return a < b ? a : b;
}

bool is_valid(double speed, long long len, vector<pair<long long, long long>>& doors) {
  for (int i = 0, start = 0, end = 0; i < doors.size(); ++i) {
    if (end < doors[i].first) {
      if (len / speed < doors[end].second - doors[start].first + epsilon) {
        return false;
      }
      start = i, end = i;
    }
    end = max(end, doors[i].second);
  }
  if (len / speed < doors[end].second - doors[start].first + epsilon) {
    return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<long long, long long>> doors(N);
    for (int i = 0; i < N; ++i) {
      cin >> doors[i].first >> doors[i].second;
    }
    sort(doors.begin(), doors.end());
    double left = 0, right = INF;
    for (int iter = 0; iter < 100; ++iter) {
      double mid = (left + right) / 2;
      if (is_valid(mid, N, doors)) {
        right = mid;
      } else {
        left = mid;
      }
    }
    double min_speed = (right < INF) ? right : -1;
    cout << "Case #" << t << ": " << fixed << setprecision(10) << min_speed << "\n";
  }
  return 0;
}
