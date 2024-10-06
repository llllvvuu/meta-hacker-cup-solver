
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
using namespace std;

vector<double> intervals;
double min_valid_speed, max_invalid_speed;

void prepare_intervals(int N, vector<int> A, vector<int> B) {
  intervals.resize(N);
  for (size_t i = 0; i < intervals.size(); i++) {
    intervals[i] = ((double)(A[i] + i)) / (B[i] - A[i]) * i;
  }
  intervals.push_back(1e99);
}

bool can_serve(double speed) {
  if (speed < (intervals.back() - 1)) return false;
  int i = -1, j = 0;
  while (j < intervals.size()) {
    if (intervals[i] >= speed - 1) {
      int next = min(++i, (int)intervals.size() - 1);
      if (intervals[next] - 1 < speed && intervals[next] > speed - 1) {
        min_valid_speed = min(min_valid_speed, speed);
      } else {
        max_invalid_speed = max(max_invalid_speed, speed);
      }
      j = next + 1;
    } else {
      j++;
    }
  }
  return min_valid_speed > max_invalid_speed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    intervals.clear();
    min_valid_speed = 1e9;
    max_invalid_speed = -1;
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (size_t i = 0; i < A.size(); i++) cin >> A[i] >> B[i];
    prepare_intervals(N, A, B);
    double low = 0, high = 1;
    while (low <= high) {
      double mid = (high + low) / 2;
      if (can_serve(mid)) {
        low = mid + 1e-9;
      } else {
        high = mid - 1e-9;
      }
    }
    printf("Case #%d:", t);
    if (min_valid_speed > 1e9) { printf("-1\n"); }
    else { printf("%.6f\n", (min_valid_speed + max_invalid_speed) / 2.); }
  }
  return 0;
}
