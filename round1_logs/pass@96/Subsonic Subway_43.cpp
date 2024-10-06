
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
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// function to check if velocity gives valid delivery times within all intervals
bool isVelocityFeasible(vector<pair<int, int>>& intervals, double V) {
    int n = intervals.size();
    vector<pair<double, int>> events;
    for (int i = 0; i < n; i++) {  // calculating arrival times and intervals
        events.push_back({double(intervals[i].first) / V, i});   // arrival before the start window
        events.push_back({double(intervals[i].second) / V + 1, -i - 1});  // after the end window
    }
    sort(events.begin(), events.end());
    int balance = 0;  // A balance tracker for simultaneous delivery checks
    for (auto [time, index] : events) {
        if (index >= 0) {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> intervals(N);
        for (int i = 0; i < N; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        double low = 0, high = 1e7 + 1;
        for (int turns_count = 0; turns_count < 60; turns_count++) {  // log2(1e7) ≈ ~24 iterations, but used to ensure precision
            double mid = (low + high) / 2;
            if (isVelocityFeasible(intervals, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << fixed << setprecision(6);
        cout << "Case #" << t << ": " << (high == 1e7 + 1 ? -1 : high) << endl;
    }
    return 0;
}
