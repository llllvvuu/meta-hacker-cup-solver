
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

const double EPS = 1e-9;

struct Interval {
    double minSpeed;
    double maxSpeed;
    bool operator < (const Interval &other) const {
        return minSpeed < other.minSpeed;
    }
};

double solve(int N, vector<pair<int, int>> &stations) {
    vector<Interval> intervals;
    for (int i = 0; i < N; i++) {
        intervals.push_back({1.0 * (i + 1) / stations[i].second, 1.0 * (i + 1) / stations[i].first});
    }
    sort(intervals.begin(), intervals.end());
    double minSpeedPossible = intervals[0].minSpeed;
    double maxSpeedPossible = intervals[0].maxSpeed;
    for (int i = 1; i < N; i++) {
        if (intervals[i].minSpeed > maxSpeedPossible) return -1;
        minSpeedPossible = max(minSpeedPossible, intervals[i].minSpeed);
        maxSpeedPossible = min(maxSpeedPossible, intervals[i].maxSpeed);
    }
    return minSpeedPossible;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> stations(N);
        for (int i = 0; i < N; i++) {
            cin >> stations[i].second >> stations[i].first;
        }
        cout << "Case #" << t << ": " << fixed << setprecision(10) << solve(N, stations) << endl;
    }
    return 0;
}
