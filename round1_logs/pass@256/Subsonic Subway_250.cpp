
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
#include <vector>
#include <iostream>
using namespace std;

struct Interval {
    double left;
    double right;
    int type; // 0 - left end, 1 - right end
};

bool cmp(const Interval& a, const Interval& b) {
    return a.left < b.left || (a.left == b.left && a.type > b.type);
}

double solve(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 0) return 0;

    vector<Interval> events;
    for (int i = 0; i < n; i++) {
        double leftInterval = (double)intervals[i][0] / (i + 1);
        double rightInterval = ((double)intervals[i][1] + 1) / (i + 1);
        events.push_back({leftInterval, rightInterval, 0});
        events.push_back({rightInterval, rightInterval, 1});
    }

    sort(events.begin(), events.end(), cmp);

    double minSpeed = (double)1e9; // Initialize to a very large value
    double maxSpeed = 0;
    int count = 0;
    for (const auto& event : events) {
        if (event.type == 0) {
            count++;
            if (count > 0) {
                minSpeed = min(minSpeed, event.left);
                maxSpeed = max(maxSpeed, event.right);
            }
        } else if (count > 0) {
            count--;
            if (count == 0 && maxSpeed <= minSpeed) {
                return maxSpeed;
            }
        }
    }

    return maxSpeed > minSpeed ? maxSpeed : -1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        cout << "Case #" << t << ": " << solve(intervals) << "\n";
    }
    return 0;
}
