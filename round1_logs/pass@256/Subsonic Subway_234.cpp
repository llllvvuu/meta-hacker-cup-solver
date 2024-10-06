
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

const double eps = 1e-9;
const double inf = 1e12;

int T, N;
pair<double, double> intervals[1000005];

double min_speed(const vector<pair<double, double>>& intervals) {
    double minB = inf;
    for (auto& interval : intervals) {
        if (interval.second < minB && !(minB - interval.second < eps))
            return -1;
        minB = min(minB, interval.second);
    }
    return 1.0 / minB;
}

double max_speed(const vector<pair<double, double>>& intervals) {
    double maxA = 0;
    for (auto& interval : intervals) {
        if (interval.first > maxA && !(interval.first - maxA < eps))
            return -1;
        maxA = max(maxA, interval.first);
    }
    return 1.0 / maxA;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> intervals[i + 1].first >> intervals[i + 1].second;
            intervals[i + 1].first = 1.0 / intervals[i + 1].first;
            intervals[i + 1].second = 1.0 / intervals[i + 1].second;
        }

        double min_spd = min_speed(intervals + 1, intervals + N + 1);
        double max_spd = max_speed(intervals + 1, intervals + N + 1);
        
        if (min_spd == -1 || max_spd == -1) {
            cout << "Case #" << t << ": -1" << endl;
        } else {
            cout << fixed << setprecision(6)
                 << "Case #" << t << ": " 
                 << max(min_spd, max_spd) << endl;
        }
    }
}
