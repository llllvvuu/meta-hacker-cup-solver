
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

struct Interval {
    int start;
    int end;
};

float checkSpeed(float v, int N, vector<pair<int, int>>& delivery_windows) {
    vector<float> arrival_times(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        float earliest = (float)i / v;
        float latest = earliest + (delivery_windows[i].second - delivery_windows[i].first);
        arrival_times[i] = latest;
        // Backtrack
        for (int j = i; j > 1; j--) {
            if (arrival_times[j - 1] < earliest) {
                float new_arrival = min(arrival_times[j], latest);
                arrival_times[j] = new_arrival;
                latest = new_arrival;
                earliest = latest - (delivery_windows[j].second - delivery_windows[j].first);
            } else {
                break;
            }
        }
    }
    return arrival_times[N] >= delivery_windows[N].first ? v : INF;
}

const float INF = 1e9;

float solve() {
    int N;
    vector<pair<int, int>> delivery_windows;
    cin >> N;
    delivery_windows.reserve(N + 1);
    for (int i = 1; i <= N; i++) {
        int start, end;
        cin >> start >> end;
        delivery_windows.emplace_back(start, end);
    }
    float low = 0, high = 1e6, final = INF;
    while (high - low > 1e-6) {
        float v = (low + high) / 2;
        final = checkSpeed(v, N, delivery_windows);
        if (final > INF - 1e-6) {
            low = v;
        } else {
            high = v;
        }
    }
    return final < INF - 1e-6 ? final : -1;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << fixed << setprecision(6) << solve() << endl;
    }
}
