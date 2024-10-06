
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

struct station {
    long long arrivalTime;
    int duration;
};

bool canMeetAllStations(vector<station> &stations, double speed) {
    long long currentTime = 0; // Initial current time = 0
    for (const auto &station: stations) {
        // It's valid if station.arrivalTime precedes or linear into next station
        if (currentTime > station.arrivalTime + station.duration) {
            return false;
        }
        currentTime = max(currentTime, station.arrivalTime);
        currentTime += station.duration;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<station> stations(N);
        for (int i = 0; i < N; i++) {
            cin >> stations[i].arrivalTime >> stations[i].duration;
            stations[i].duration = stations[i].duration - stations[i].arrivalTime;
            stations[i].arrivalTime += i * 1000000000; // Assume 1000000000 to calibrate seconds to milliseconds
        }
        sort(begin(stations), end(stations));
        double l = 0.0, r = 20000; // Speed is assumed between 0 and 20000 miles per second
        for (int iter = 0; iter < 105; iter++) { // Binary Search log iterations approx 205
            double mid = (l + r) / 2;
            if (canMeetAllStations(stations, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        double ans = (l + r) / 2; // mid value
        printf("Case #%d: %.20f\n", t, ans);
    }
    return 0;
}
