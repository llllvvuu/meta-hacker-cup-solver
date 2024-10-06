
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
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        vector<pair<int, int>> windows(N);
        for (int i = 0; i < N; ++i) {
            cin >> windows[i].first >> windows[i].second;
        }

        sort(windows.begin(), windows.end());

        double min_speed = -1.0;

        pair<int, int> segment {0, -1};
        for (int i = N-1; i >= 0; --i) {
            if (segment.first <= windows[i].first && windows[i].first <= segment.second) {
                // feasible interval found for windows[i]
                double speed = static_cast<double>(i) / windows[i].first;
                min_speed = max(min_speed, speed);
            } 
            auto next = make_pair(windows[i].second - i + 1, windows[i].second);
            segment = min(segment, next);
        }

        if (min_speed < 0) {
            cout << "-1" << "\n";
        } else {
            cout << fixed << setprecision(6) << min_speed << "\n";
        }
    }
    return 0;
}
