
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

pair<int, int> interval[2000005];  // Stores intervals
vector<pair<int, int>> events[2000005]; // Events occurrence

void merge(vector<pair<int, int>>& range, vector<pair<int, int>>& events) {
    // Merging overlapping intervals
    for (int i = 0; i < events.size(); i++) {
        pair<int, int> event = events[i]; int j = i + 1;
        int last_interval_end = event.second;
        while (j < (int)(events.size()) && events[j].first <= last_interval_end) {
            last_interval_end = max(last_interval_end, events[j].second);
            j++;
        }
        range.push_back({event.first, last_interval_end});
        i = j - 1;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<double, int>> sticky_vert;
        vector<pair<int, int>> dummy;
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            events[a].push_back({i, b});  // Start Event
            events[b].push_back({i, a});  // End event
        }
        double ans = -1;
        for (int i = 0; i <= 1000000; i++) {
            merge(dummy, events[i]);
            for (pair<int, int> event : dummy) {
                ans = max(ans, (double)(event.first + 1) / ((double)(event.second)));
            }
        }
        cout << "Case #" << t << ": " << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
