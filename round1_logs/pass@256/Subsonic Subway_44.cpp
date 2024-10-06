
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
#include <algorithm>
using namespace std;

const double DELTA = 1e-6; //Tolerance

bool findInterval(const vector<int>& start, const vector<int>& finish, int i, int j) {
    int l = i, r = j;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (start[m] >= start[i] && start[m] <= finish[i])
            return true;
        if (start[m] < start[i])
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

void travelCase() {
    int N;
    cin >> N;
    vector<double> distances(N);
    vector<int> start(N), finish(N);
    for (int i = 0; i < N; i++) {
        cin >> start[i] >> finish[i];
        distances[i] = i + 1;
    }
    sort(start.begin(), start.end());

    double max_speed = 2.0e9;
    double min_speed = 0.0;
    for (int i = 0; i < N; i++) {
        if (start[i] <= N)
            max_speed = min(max_speed, (double)distances[i] / start[i]);
        if (start[i] < finish[N-1] && findInterval(start, finish, i, N - 1))
            min_speed = max(min_speed, (double)distances[i] / start[i]);
    }
    
    //Binary search for exact speed that matches all constraints.
    while (max_speed - min_speed > 2 * DELTA) {
        double mid_speed = (min_speed + max_speed) / 2.0;
        bool can_travel = true;
        for (int i = 0; i < N && can_travel; i++) {
            if ((double)distances[i] > mid_speed * start[i] || (double)distances[i] > mid_speed * finish[i])
                can_travel = false;
        }
        if (can_travel)
            max_speed = mid_speed;
        else
            min_speed = mid_speed;
    }

    cout << "Case #1: " << max_speed << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        travelCase();
    }
    return 0;
}
