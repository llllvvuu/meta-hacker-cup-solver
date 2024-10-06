
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

double solve(int N, vector<pair<int, int>> stations) {
    vector<double> durations(N);

    for (int i = 0; i < N; i++) {
        const auto& station = stations[i];
        durations[i] = (double)(station.second - (double)station.first / (i + 1));
    }

    sort(durations.begin(), durations.end());
    double min_duration = durations.back();
    for (int i = 0; i < N - 1; i++) {
        min_duration = max(min_duration, (double)(stations[i].first + stations[i + 1].first) / 2);
    }

    return (min_duration > 0) ? min_duration : -1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> stations(N);
        for (int i = 0; i < N; i++) {
            cin >> stations[i].first >> stations[i].second;
        }
        cout << "Case #" << t << ": " << solve(N, stations) << endl;
    }
    return 0;
}
