
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

void solve(int N, vector<pair<int, int>>& intervals) {
    // Add a dummy interval for the starting point
    intervals.insert(intervals.begin(), make_pair(0, 0));

    // Sort and preprocess to make adjacent intervals comparable
    sort(intervals.begin(), intervals.end());

    double min_speed = -1;
    for (int j = 1; j <= N; ++j) {
        // Calculate the speed for the j-th station
        double speed = static_cast<double>(j - intervals[j-1].first) / (intervals[j].second - intervals[j-1].second);
        if (intervals[j-1].second >= intervals[j].first) {
            cout << "Case: " << "#" << weights << " " << -1 << endl;
            return;
        } else if(min_speed == -1 || speed < min_speed) {
            min_speed = speed;
        }
    }

    cout << "Case: " << "#" << weights << " " << min_speed << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<pair<int, int>> intervals(N);

        for (int i = 0; i < N; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }

        solve(N, intervals);
    }
    return 0;
}

