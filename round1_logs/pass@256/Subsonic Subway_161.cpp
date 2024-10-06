
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
using namespace std;

const double EPS = 1e-10;

struct Event {
    int time, station;
    bool operator<(const Event &other) const {
        return time < other.time || time == other.time && station > other.station;
    }
};

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        Event events[2 * N];
        for (int i = 0; i < N; ++i) {
            int A, B;
            cin >> A >> B;
            events[2 * i] = {A, i};
            events[2 * i + 1] = {B, i};
        }
        sort(events, events + 2 * N);
        double max_speed_min = 0;
        double max_speed_max = 1e6;
        while(max_speed_max - max_speed_min > EPS) {
            double search_speed = (max_speed_min + max_speed_max) / 2.0;
            bool works = true;
            double time = events[0].time;
            for (int i = 0; i < 2 * N; ++i) {
                if (i % 2 == 1) continue;
                if (time > events[i + 1].time || 
                    time + events[i].station / search_speed > events[i + 1].time + events[i + 1].station / search_speed) {
                    works = false;
                    break;
                }
                time = events[i + 1].time;
            }
            if (works)
                max_speed_max = search_speed;
            else
                max_speed_min = search_speed;
        }
        cout << "Case #" << t << ": ";
        if(abs(max_speed_min) <= 1e-6) cout << "0";
        else cout << fixed << setprecision(9) << max_speed_min;
        cout << endl;
    }
    return 0;
}
