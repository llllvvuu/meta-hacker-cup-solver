
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

const double INF = 1e8;

struct Interval {
    double start, end;
    Interval(double st, double en) : start(st), end(en) {}
};

double findMinimumSpeed(vector<pair<double, double>> &stations) {
    vector<Interval> intervals;
    for (auto &station : stations) {
        intervals.emplace_back(station.first / station.second, station.second / station.second);
    }
    sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
        return a.start < b.start;
    });

    Interval ans = {-INF, INF};
    for (auto &interval : intervals) {
        if (interval.start > ans.end) {
            return -1;
        } else {
            ans.end = min(ans.end, interval.end);
        }
    }
    return 1.0 / ans.end;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<double, double>> stations(N);
        for (auto &station : stations) {
            cin >> station.first >> station.second;
        }
        cout << "Case #" << t << ": " << findMinimumSpeed(stations) << endl;
    }
    return 0;
}
