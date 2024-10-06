
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
#include <tuple>
using namespace std;

struct DeliveryWindow {
    int station;
    int arrival;
    int departure;
};

bool isValid(const vector<int>& departures, const vector<int>& arrivals) {
    for (size_t i = 0; i < departures.size() - 1; i++) {
        if (departures[i] > arrivals[i + 1]) return false;
    }
    return true;
}

tuple<int, int, int> computeDeliveryWindows(int v, int N) {
    vector<int> departures;
    departures.push_back(0); // Initial position at station 1
    int prev_departure = 0;
    for (int i = 1; i <= N; i++) {
        int t = i / v;
        int next_t = max(t * v, departures.back() + v); // Incrementally populating departures
        departures.push_back(next_t);
        if (next_t + v > max(i / v * v, prev_departure + v)) {
            return {v, i, -1}; // Within bounds error
        }
        prev_departure = next_t;
    }
    return {v, N, departures.back()};
}

double findMinSpeed() {
    vector<DeliveryWindow> windows;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        windows.emplace_back(i, a, b);
    }

    sort(windows.begin(), windows.end(), [](const DeliveryWindow &w1, const DeliveryWindow &w2) {
        return w1.departure < w2.departure;
    });

    for (int i = 0; i <= N; i++) {
        if (windows[i].station == 1 && windows[i].departure < windows[0].arrival) continue;
        if (!isValid(vector<int>(windows.begin() + i, windows.end()), vector<int>(windows.begin(), windows.begin() + i))) continue;

        auto [speed, stn, t] = computeDeliveryWindows((windows[stn-1].arrival - i == 0 ? windows[stn-1].arrival : windows[stn-1].departure) / stn, N);
        if (t <= windows[N-1].departure && t >= windows[N-1].arrival) return speed;
    }
    return -1.0;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        double speed = findMinSpeed();
        cout << "Case #" << t << ": " << fixed << setprecision(15) << speed << endl;
    }
    return 0;
}
