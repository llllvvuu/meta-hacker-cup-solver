
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
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const double MAX_TOL = 1e-6; // error tolerance
const int MAXN = 1001000;    // maximum N value

struct S {
  double lb, ub;
} stations[MAXN];
double to_delivered_first[MAXN];

bool get_delivered_at_right_time(int N, double speed) {
  fill(to_delivered_first, to_delivered_first + N, 0);
  // Initially all pairs are impossible to match at a strictly positive time.
  for (int i = 0; i < N; i++) {
    // Time taken at constant speed.
    double distance_from_start = i + 1;
    double delivery_time = distance_from_start / speed;

    // Only stations with a matching interval are checked.
    if (stations[i].lb > delivery_time) return false;
    if (stations[i].ub > delivery_time) to_delivered_first[i] = 1;

    int ti = 0, tj = 0;
    // Use stepwise building of time array overstations.
    for (int j = i + 1; j < N; j++) {
      // Find first station to receive, then continue building array.
      while (ti < j && to_delivered_first[ti])
        ti++;
      while (tj < j && !to_delivered_first[tj]) tj++;
      if (stations[j].lb > (tj + 1) / speed) return false;
      if (stations[j].ub > (tj + 1) / speed) to_delivered_first[j] = 1;
      // Check as much as necessary.
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
      double A, B;
      scanf("%lf%lf", &A, &B);
      stations[n].lb = A - double(n + 1); // Time from starting point - distance.
      stations[n].ub = B - double(n + 1); // Same for upper bound.
    }
    double lb = 0, ub = 1000000.0;
    for (int b = 0; b < 100; b++) {
      double mid = (lb + ub) / 2;
      if (get_delivered_at_right_time(N, mid))
        ub = mid;
      else
        lb = mid;
    }
    printf("Case #%d: %.10f\n", t, !isfinite(ub) ? -1 : ub);
  }
  return 0;
}
