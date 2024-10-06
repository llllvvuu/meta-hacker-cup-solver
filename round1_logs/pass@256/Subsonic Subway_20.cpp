
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

const int MAXT = 2e6 + 5;
long long EPS = 1e-9;

struct event {
    int time;
    int station; // 0 meaning close; 1 meaning open
};

bool compare_events(const event& e1, const event& e2) {
    return e1.time < e2.time || e1.time == e2.time && e1.station > e2.station;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<event> timeline;
        timeline.reserve(2 * N);
        
        for (int i = 0; i < N; i++) {
            int A, B;
            cin >> A >> B;
            timeline.push_back({A, i});
            timeline.push_back({B, i});
        }
        
        sort(timeline.begin(), timeline.end(), compare_events);
        
        int stations_open = 0;
        bool is_possible = false;
        long long min_max_speed = 0, min_speed = 1e10;
        
        for (auto [time, i] : timeline) {
            if (i != -1) { // station start or end
                if (stations_open++ == 0) min_speed = time;
                else if (stations_open == N) {
                    is_possible = true;
                    min_max_speed = max(min_max_speed, (long double)time / N);
                    min_speed = min(min_speed, time);
                }
            } else { // station roof closed
                if (--stations_open == 0) {
                    min_speed = 0;
                    min_max_speed = N * time / N + EPS;
                }
            }
        }
        
        double result = min_max_speed * N < min_speed + EPS && is_possible ? min_speed / N : -1;
        cout << "Case #" << t << ": " << fixed << setprecision(9) << result << endl;
    }
    return 0;
}
