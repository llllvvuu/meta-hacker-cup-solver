
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
    double floor;
    double ceiling;
};

bool compare(const Interval& a, const Interval& b) {
    return a.floor < b.floor;
}

Interval station_bounds(int dist, int start, int stop) {
    Interval interval;
    interval.floor = double(dist) / stop;
    interval.ceiling = double(dist) / start;
    return interval;
}

bool contains_overlap(const vector<Interval>& intervals) {
    vector<double> lower, upper;
    for (const auto& interval : intervals) {
        lower.push_back(interval.floor);
        upper.push_back(interval.ceiling);
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    for (int i = 0; i < lower.size(); i++) {
        if (lower[i] <= upper[i]) {
            return true;
        }
    }
    return false;
}

double solve() {
    int N;
    cin >> N;
    vector<Interval> intervals;
    intervals.resize(N);
    for(int i = 0; i < N; i++) {
        int dist = i + 1;
        int start, stop;
        cin >> start >> stop;
        intervals[i] = station_bounds(dist, start, stop);
    }

    sort(intervals.begin(), intervals.end(), compare);

    double min_bound = -1.0;

    if (contains_overlap(intervals)) {
        min_bound = intervals[0].floor;
    }

    return min_bound;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
