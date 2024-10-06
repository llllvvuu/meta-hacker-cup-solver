
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
#include <cassert>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int64_t min_speed(int64_t start[2], int64_t end[2], int64_t start_min[2], int64_t end_max[2]) {
  const int64_t DELTA = 1e9;
  // Ensure interval overlap
  if (start[0] > end[1] + DELTA || start[1] < end[0] - DELTA) {
    return -1;
  }
  // Compute valid start and end times (-1 indicates no valid start)
  int64_t valid_start_time = max(start[0], start_min[0]), valid_end_time = min(start[1], end_max[0]);
  return valid_start_time <= valid_end_time ?
      max((end_max[1] - valid_end_time) / end_max[0], (valid_start_time - start_min[1]) / start_min[0]) :
      -1;
}

double solve(int N, vector<int64_t>&A, vector<int64_t>&B) {
  const int64_t DELTA = 1e9;
  // Create intervals for all stations in terms of start and end moments.
  int64_t start[2] = {INT_MAX, INT_MIN}, end[2] = {INT_MAX, INT_MIN};
  for (int i = 0; i < N; i++) {
    const auto adjusted_start = A[i] - i;
    const auto adjusted_end = B[i] - i;
    start[0] = min(start[0], adjusted_start - i * DELTA);  // Start earlier adjusted for distance
    start[1] = max(start[1], adjusted_start + i * DELTA);  // Start later adjusted
    end[0] = max(end[0], adjusted_end + i * DELTA);        // End min adjusted
    end[1] = min(end[1], adjusted_end - i * DELTA);        // End max adjusted
  }
  vector<int64_t> start_min = {start[0], start[1]}, end_max = {end[0], end[1]}; // Save original max and min for reference
  sort(start_min.begin(), start_min.end());
  sort(end_max.begin(), end_max.end());
  // Compute minimum start-end interval where all intervals overlap
  const int64_t min_start = start_min[1], max_end = end_max[0];
  start_min[1] = end_max[0] = max_end - min_start + 1;

  // Validate and calculate speed
  double optimal_speed = min_speed(start, end, start_min, end_max) * (double) DELTA;
  return optimal_speed;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    cout << "Case #" << t + 1 << ": " << setprecision(10) << solve(N, A, B) << endl;
  }
  return 0;
}
