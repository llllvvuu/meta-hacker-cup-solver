
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

bool solve(int N, vector<pair<int, int>> stations) {
    bool possible = false;
    // To calculate the minimum speed if delivery at specific stations is known to be impossible, starting from the left.
    int earliest_index = -1, latest_index = 0;
    int min_speed_left = 2333333333, extra_space = 0;
    for (int i = 0; i < N; i++) {
        // if the delivery at the next station is before reaching a previous station ends, we must run extra fast.
        if (earliest_index != -1 && stations[i].first > stations[earliest_index].second) {
            extra_space = stations[i].first - stations[earliest_index].second;
            min_speed_left = (double)(1 + i + extra_space) / stations[earliest_index].first;
            if (min_speed_left < stations[earliest_index].second / (stations[earliest_index].second - stations[i].first)) {
                min_speed_left = stations[earliest_index].second / (stations[earliest_index].second - stations[i].first);
            }
        }
        // if the delivery is possible, update the latest_index.
        if (latest_index < N && stations[latest_index].second <= stations[i].second) {
            earliest_index = latest_index;
        }
        // if we can deliver to i-th station with stations[earliest_index] as the last station.
        if (stations[i].first > stations[earliest_index].second) {
            possible = true;
            min_speed_left = min(min_speed_left, (double)(stations[i].first - stations[earliest_index].second) / stations[earliest_index].second);
        }
        ++latest_index;
    }
    int min_speed_right = 2333333333;
    latest_index = N - 1;
    for (int i = N - 1; i >= 0; --i) {
        if (earliest_index == -1 && stations[latest_index].first <= stations[i].first) {
            earliest_index = latest_index;
        }
        if (stations[i].second < stations[latest_index].second) {
            latest_index = earliest_index;
            extra_space = stations[latest_index].second - stations[i].second;
            min_speed_right = min(min_speed_right, (double)(1 + extra_space + i) / stations[i].second);
        }
    }
    if (min_speed_right < 1) {
        return false;
    }
    if (earliest_index == -1) {
        min_speed_right = 0;
    }
    min_speed_right = min(min_speed_right, (double)(max(N, stations[latest_index].second) - extra_space) / stations[latest_index].second);
    return possible ? 1 : min(min_speed_left, min_speed_right);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> stations(N);
        for (auto &s : stations) {
            cin >> s.first >> s.second;
        }
        if (!solve(N, stations)) {
            cout << "Case #" << t << ": -1\n";
            continue;
        }
        sort(stations.begin(), stations.end());
        int earliest = stations[0].first, latest = 0;
        double ret = 0;
        for (int i = 0; i < N; i++) {
            latest = max(latest, stations[i].second);
            ret = max(ret, (double)(i + 1 + max(latest - earliest, 0)) / earliest);
            earliest = stations[i].first;
        }
        cout << "Case #" << t << ": ";
        cout << fixed << setprecision(7) << ret << '\n';
    }
    return 0;
}
