
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
#include <algorithm>
using namespace std;

const double EPSILON = 1e-9;

bool overlaps(double x1, double x2, double y1, double y2) {
    return !((x1 > y2 + EPSILON) || (y1 > x2 + EPSILON));
}

void merge_intervals(vector<pair<double, double>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<pair<double, double>> merged;
    for (auto interval : intervals) {
        if (merged.empty() || !overlaps(merged.back().first, merged.back().second, interval.first, interval.second)) {
            merged.push_back(interval);
        } else {
            merged.back() = {min(merged.back().first, interval.first), max(merged.back().second, interval.second)};
        }
    }
    intervals = merged;
}

double calculate_min_speed(vector<pair<int, int>>& stations) {
    vector<pair<double, double>> lower_bounds, upper_bounds;
    lower_bounds.reserve(stations.size());
    upper_bounds.reserve(stations.size());
    double min_speed = 1e9;
    for (size_t i = 0; i < stations.size(); ++i) {
        auto [a, b] = stations[i];
        min_speed = min(min_speed, (double) (i + 1) / b);
        lower_bounds.emplace_back((double) (i + 1) / b, (double) (i + 1) / a);
    }
    merge_intervals(lower_bounds);
    return lower_bounds.front().first;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector<pair<int, int>> stations(n);
        for (auto& [a, b] : stations) cin >> a >> b;
        double min_speed = calculate_min_speed(stations);
        if (min_speed < 0)
            cout << "Case #" << t << ": -1\n";
        else
            cout << "Case #" << t << ": " << fixed << setprecision(6) << min_speed << "\n";
    }
    return 0;
}
