
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
#include <queue>
#include <limits>
using namespace std;

struct Event {
    int type, station, time;
    Event(int type, int station, int time) : type(type), station(station), time(time) {}
};

bool compareEvents(Event e1, Event e2) {
    return e1.time < e2.time || (e1.time == e2.time && e1.type < e2.type);
}

int N;
vector<Event> events;
double binary_search_speed() {
    double low = 1e-9, high = 1e9;
    for(int i = 0; i < 80; i++) {
        double mid = (low + high) / 2;
        int dist = 0, time = 0;
        bool canReach = true;
        for (Event e : events) {
            if ((e.station > dist) && ((e.time - time) * mid < e.station - dist)) {
                canReach = false;
                break;
            }
            time = e.time;
            dist = e.station;
        }
        if (canReach) high = mid;
        else low = mid;
    }
    return low;
}

int solve() {
    cin >> N;
    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].first >> intervals[i].second;
        events.emplace_back(0, i + 1, intervals[i].first); // Start of windows
        events.emplace_back(1, i + 1, intervals[i].second); // End of windows
    }
    sort(events.begin(), events.end(), compareEvents);
    return binary_search_speed();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        events.clear();
        cout << "Case #" << t << ": " << setprecision(6) << fixed << solve() << endl;
    }
    return 0;
}
