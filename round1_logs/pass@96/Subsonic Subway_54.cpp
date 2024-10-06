
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

const double eps = 1e-6;

struct Event {
    int type; // 1 for start, 2 for end
    double time, dist;
    bool operator<(Event other) const {
        if (time != other.time)
            return time < other.time;
        return type < other.type;
    }
};

double solve(int N, vector<pair<int, int>> stations) {
    vector<Event> events;
    for (int i = 1; i <= N; ++i) {
        int arrival = stations[i - 1].first, departure = stations[i - 1].second;
        events.push_back({1, (double)arrival / i, i});
        events.push_back({2, (double)departure / i, i});
    }
    sort(events.begin(), events.end());
    double last_time = 0, max_speed = 0;
    for (const auto &event : events) {
        if (event.dist > 1) {
            double speed = (event.type == 1) ? event.dist / event.time : event.dist / (last_time + eps);
            if (speed > max_speed)
                max_speed = speed;
        }
        last_time = (event.type == 1) ? event.time : last_time;
    }
    return max_speed;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<pair<int, int>> stations(N);
        for (int i = 0; i < N; ++i)
            cin >> stations[i].first >> stations[i].second;
        cout << "Case #" << t << ": " << (solve(N, stations) - 1 / 1e6) << endl;
    }
    return 0;
}
