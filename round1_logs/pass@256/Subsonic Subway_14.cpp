
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

struct Interval {
    double l, r;
};

bool canDeliver(double speed, const vector<Interval>& intervals) {
    for (auto interval : intervals) {
        double min_speed = 1.0 / interval.r;
        double max_speed = 1.0 / interval.l;
        if (speed < min_speed || speed > max_speed) return false;
    }
    return true;
}

double binarySearchMinSpeed(const vector<Interval>& intervals) {
    double lo = 0.0;
    double hi = 1e6; // Upper bound based on constraints.
    while (lo < hi - 1e-9) {
        double mid = (lo + hi) / 2;
        if (canDeliver(mid, intervals)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return canDeliver(lo, intervals) ? lo : -1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Interval> intervals(N);
        for (int i = 0; i < N; i++) {
            cin >> intervals[i].l >> intervals[i].r;
        }
        cout << "Case #" << t << ": " << fixed << setprecision(6) << binarySearchMinSpeed(intervals) << endl;
    }
    return 0;
}
