
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

const long double inf = 1e11;
const long double eps = 1e-9;

struct StationWindow {
    int station; // index of the station
    long double time; // time for delivery window
};

bool isOneCaseValid(const vector<long double>& milestones,
                    int stations_count, long double speed) {
    long double prev_time = 0.0;
    for (int i = 1; i <= stations_count; i++) {
        long double current_time = (long double)i / speed;
        if (current_time > milestones[2 * i] + eps && prev_time < milestones[2 * i - 1] - eps) {
            return false;
        }
        prev_time = current_time;
    }
    return true;
}

int main() {
    int test_cases;
    cin >> test_cases;
    vector<vector<StationWindow>> all_cases;
    vector<int> stations;

    for (int i = 1; i <= test_cases; i++) {
        int stations_count = 0;
        cin >> stations_count;
        stations.push_back(stations_count);
        vector<StationWindow> cur_case;
        for (int j = 1; j <= stations_count; j++) {
            long double window_start = 0.0,
                        window_end = 0.0;
            cin >> window_start >> window_end;
            cur_case.push_back({j, (long double)j / window_end});
            cur_case.push_back({j, (long double)j / window_start});
        }
        sort(cur_case.begin(), cur_case.end(), [](const StationWindow& left, const StationWindow& right) {
            return left.time < right.time;
        });
        vector<long double> milestones;
        for (const auto& window : cur_case) {
            const int station_index = window.station;
            const long double delivery_time = window.time;
            if (station_index == milestones.empty() || milestones.back().station != station_index) {
                milestones.push_back(delivery_time);
            }
        }
        if (isOneCaseValid(milestones, stations_count, inf)) {
            cout << "Case #" << i << ": " << milestones.back() - 1e-6 << endl;
        } else {
            cout << "Case #" << i << ": -1" << endl;
        }
    }

    return 0;
}
