
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
using namespace std;

struct station {
    int start, end;
    station(int s, int e) : start(s), end(e) {}
};

bool compare(station a, station b) {
    return a.start < b.start;
}

double minspeed(const vector<station>& stations, int stations_count, int dist) {
    double ret = -1, tr = 0;
    vector<pair<double, pair<double, int>>> events;
    for (int i = 0; i < stations_count; ++i) {
        events.emplace_back(static_cast<double>(stations[i].start), make_pair(static_cast<double>(dist / stations[i].end), tr));
        tr = max(tr, stations[i].end);
        events.emplace_back(static_cast<double>(stations[i].end), make_pair(static_cast<double>(tr + 1), i));
    }
    sort(events.begin(), events.end());
    
    for (auto& ev : events) {
        if (ev.second.second != -1) {
            ret = max(ret, ev.second.first);
        }
    }
    return ret == -1 ? -1 : 1.0 / ret;
}

int main() {
    int test_cases, stations_count;
    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; ++tc) {
        cin >> stations_count;
        vector<station> stations(stations_count);
        for (int i = 0; i < stations_count; ++i) {
            cin >> stations[i].start >> stations[i].end;
        }
        sort(stations.begin(), stations.end(), compare);
        cout << "Case #" << tc << ": " 
             << minspeed(stations, stations_count, stations_count + 1) 
             << endl;
    }
    return 0;
}
