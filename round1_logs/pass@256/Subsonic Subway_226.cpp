
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
#include <iostream>
#include <vector>

using namespace std;

struct SpeedInterval {
    double v_low;
    double v_high;
};

bool compare_speeds(const SpeedInterval& a, const SpeedInterval& b) {
    return a.v_low < b.v_low;
}

double calculate_speed(const vector<SpeedInterval>& speed_ints) {
    double min_v = speed_ints[0].v_low;
    double max_v = speed_ints[0].v_high;

    for (int i = 1; i < speed_ints.size(); i++) {
        double current_min_v = speed_ints[i].v_low;
        double current_max_v = speed_ints[i].v_high;
        if (max_v < current_min_v) {
            return -1.0;  // Impossible to find a speed that satisfies all conditions.
        }
        min_v = max(min_v, current_min_v);
        max_v = min(max_v, current_max_v);
    }
    // min_v is the lower bound and max_v is the upper bound of the interval
    return (max_v + min_v) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<SpeedInterval> speed_ints(N);

        for(int i = 0; i < N; ++i) {
            int A, B;
            cin >> A >> B;
            double speed_high = 1.0 * (i + 1) / A;
            double speed_low = 1.0 * (i + 1) / B;
            speed_ints[i] = {speed_low, speed_high};
        }

        sort(speed_ints.begin(), speed_ints.end(), compare_speeds);

        double speed = calculate_speed(speed_ints);
        cout << "Case #" << t << ": ";
        if (speed == -1) {
            cout << speed << endl;
        } else {
            cout << speed << endl;
        }
    }
    return 0;
}
