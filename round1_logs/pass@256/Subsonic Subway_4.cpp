
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

// Interval class for representing left and right bounds of time intervals
class Interval {
public:
    double left = 0, right = 0;
    Interval(double l, double r): left(l), right(r) {}
};

// Function for the compare operation for sorting intervals
bool cmp(const Interval &int1, const Interval &int2) {
    return int1.left < int2.left;
}

const double INF = 1e18;

double solve(int N, vector<vector<int>> &windows) {
    vector<Interval> intervals(2 * N);
    for (int i = 0; i < N; i++) {
        intervals[2 * i] = Interval(windows[i][0], INF);
        intervals[2 * i + 1] = Interval(windows[i][1], -INF);
    }
    // Sort the intervals based on the starting time
    sort(intervals.begin(), intervals.end(), cmp);
    
    double biggest_gap = -INF;
    double current_interval_start = 0.0;
    
    // Sweep line algorithm to determine gaps between non-overlapping intervals
    for (const Interval &interval : intervals) {
        if (interval.left > current_interval_start) {
            biggest_gap = max(biggest_gap, interval.left - current_interval_start);
        }
        current_interval_start = max(current_interval_start, interval.right);
    }
    
    return biggest_gap != -INF ? 1 / biggest_gap : -1;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        vector<vector<int>> windows(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> windows[i][0] >> windows[i][1];
        }
        double result = solve(N, windows);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
