
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
#include <utility>
using namespace std;

struct Interval {
    int A, B;
    Interval(int A, int B) : A(A), B(B) {}

    // Compare start time, and resort by end time if start time identical
    bool operator<(const Interval& o) const {
        if (A != o.A) return A < o.A;
        return B < o.B;
    }
};

double solve(int N, vector<Interval> intervals) {
    sort(intervals.begin(), intervals.end());


    double minSpeed = 1e12;  // Initially set a very high value
    int start = 0, end = 0;

    // Combine overlapping intervals
    while (start < N) {
        end = start;
        while (end + 1 < N &&
                intervals[end + 1].A <= intervals[end].B &&
               intervals[end + 1].B >= intervals[end].B) {
            end++;
        }
        double currentSpeed = intervals[end].B - start;
        if (currentSpeed < intervals[end].B - intervals[end].A) {
            currentSpeed = 1 / intervals[end].B; // Handle division by distance
        } else {
            // Check if we're falling out the interval
            if (start + currentSpeed > intervals[end].A) {
                return -1;
            }
            if (start - currentSpeed < intervals[end].B) {
                return -1;
            }
        }
        minSpeed = min(minSpeed, currentSpeed / (double)(end - start + 1));
        start = end + 1;
    }

    return minSpeed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<Interval> intervals(N);
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        intervals[i] = Interval(A, B);
    }
    double ans = solve(N, intervals);
    cout << "Case #" << t << ": " << setprecision(16) << fixed << ans << endl;
  }

  return 0;
}
