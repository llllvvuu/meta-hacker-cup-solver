
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

const double INF = 1e12;

double min_speed(int N, vector<pair<int, int>> windows) {
    double left = 0.0, right = 1e9;
    vector<double> max_times;

    for (int i = 0; i < N; ++i) {
        double arrival_interval_start = (double) i / windows[i].second;
        double arrival_interval_end = (double) i / windows[i].first;
        max_times.push_back(arrival_interval_start);
        max_times.push_back(arrival_interval_end);
    }

    sort(max_times.begin(), max_times.end());
    double best = INF;

    for (int i = 0; i + 1 < max_times.size(); ++i) {
        best = min(best, max_times[i + 1]);
    }

    return best == INF ? -1 : best;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<pair<int, int>> windows(N);
        for (int i = 0; i < N; ++i) {
            cin >> windows[i].first >> windows[i].second;
        }

        cout << "Case #" << t << ": " << fixed << setprecision(9) << min_speed(N, windows) << endl;
    }
    return 0;
}
