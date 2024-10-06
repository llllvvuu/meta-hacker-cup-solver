
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

double EPS = 1e-9;

struct Station {
    int leftWindow;
    int rightWindow;
    Station(int l, int r) : leftWindow(l), rightWindow(r) {}
};

double solve(double N, vector<Station> &stations) {
    double speed = -1;
    double time_upperbound = stations[0].leftWindow;
    // Step through each station and track the needed speed
    for (int i = 1; i < N; i++) {
        double next_station_speed = (double)(stations[i].rightWindow - stations[i - 1].leftWindow) / (i);
        // If the speed is negative, it’s not possible to align the windows
        if (next_station_speed <= 0) return -1;
        if(speed != -1 && (speed - EPS > next_station_speed || speed + EPS < next_station_speed)) 
            return -1;
        // Only update speed if it's initially -1 or the calculated speed is smaller
        if(speed == -1 || next_station_speed < speed) speed = next_station_speed;
        // Time upper bound should be maintained to ensure all stations can be reached
        time_upperbound = min(time_upperbound, (double)stations[i].rightWindow);
    }
    // Return the maximum of the time upper bound and the required speed
    return speed;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Station> stations(N);
        for (int i = 0; i < N; i++) {
            int A, B;
            cin >> A >> B;
            stations[i] = Station(A, B);
        }
        cout << "Case #" << t << ": " << fixed << solve(N, stations) << endl;
    }
    return 0;
}
