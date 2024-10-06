
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

typedef pair<double, double> interval;

vector<interval> process_intervals(double start, double end, int distance) {
    vector<interval> new_intervals = {
        make_pair(-1 / end, -1 / end + distance),
        make_pair(1 / start, 1 / start + distance)
    };
    return new_intervals;
}

int N;
vector<interval> all_intervals;

void merge_intervals() {
    sort(all_intervals.begin(), all_intervals.end());
    vector<interval> merged;
    for (auto it : all_intervals) {
        if (merged.empty() || merged.back().second < it.first)
            merged.push_back(it);
        else
            merged.back().second = max(merged.back().second, it.second);
    }
    all_intervals = merged;
}

void init() {
    double start = 2e9+5, end = -2e9-5;
    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A >> B;
        vector<interval> intervals = process_intervals(A, B, i);
        start = min(start, intervals[1].first);
        end = max(end, intervals[1].second);
        all_intervals.insert((lower_bound(all_intervals.begin(), all_intervals.end(), intervals[0])
            - all_intervals.begin()), intervals[0]);
        merge_intervals();
    }
    all_intervals.insert((lower_bound(all_intervals.begin(), all_intervals.end(), make_pair(start, end))
        - all_intervals.begin()), make_pair(start, end));
    merge_intervals();
}

double calculate_speed() {
    return 1 / all_intervals.front().second;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        N = 0;
        all_intervals.clear();
        cin >> N;
        init();
        double speed = calculate_speed();
        if (speed > 1e6) speed = -1;
        cout << "Case #" << T+1 << ": " << fixed << setprecision(6) << speed << '\n';
    }
    return 0;
}
