
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
#include <numeric>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;

bool isValidSpeed(int N, vector<pair<double, double>>& intervals, double speed) {
    int prevEnd = -1;
    for (int i = 0; i < N; i++) {
        double arrivalTime = intervals[i].first / speed;
        double lastGoodTime = max(prevEnd, intervals[i].first);
        double nextStationTime = i + 1 < N ? intervals[i+1].first : 1e9;
        if (lastGoodTime > nextStationTime || lastGoodTime > intervals[i].second) {
            return false;
        }
        prevEnd = max(prevEnd, intervals[i].second);
        if (nextStationTime > lastGoodTime) {
            double time = (double)(nextStationTime - lastGoodTime) / speed;
            prevEnd = min(prevEnd + time, nextStationTime);
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int N;
        cin >> N;
        vector<pair<double, double>> intervals(N);
        for (auto &interval : intervals) cin >> interval.first >> interval.second;

        sort(intervals.begin(), intervals.end());
        double l = 0, r = 2e6;
        while(r - l > EPS) {
            double mid = (l + r) / 2.0;
            if (isValidSpeed(N, intervals, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << "Case #" << caseNum << ": " << r << endl;
    }
    return 0;
}
