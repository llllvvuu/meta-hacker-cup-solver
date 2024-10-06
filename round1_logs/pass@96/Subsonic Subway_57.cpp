
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
typedef long double LD;

struct Interval {
    int l, r;
};

LD solve(vector<pair<int, int>> &tasks) {
    vector<Interval> intervals;
    // Sort tasks based on start time
    sort(tasks.begin(), tasks.end());
    
    for (auto &task : tasks) {
        int l = task.first;
        int r = task.second;
        
        if (!intervals.empty() && intervals.back().r >= l) {
            // if overlapping, adjust the current interval
            intervals.back().r = max(intervals.back().r, r);
        } else {
            // else append the new interval
            intervals.push_back({l, r});
        }
    }

    // Now we need to find the smallest non-overlapping gap
    LD ans = -1;
    
    for (int i = 0; i < (int) intervals.size() - 1; i++) {
        ans = max(ans, (LD) 1.0 / (intervals[i + 1].l - intervals[i].r));
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        
        vector<pair<int, int>> tasks(N);
        for (int i = 0; i < N; i++) {
            cin >> tasks[i].first >> tasks[i].second;
        }
        
        cout << "Case #" << t << ": ";
        LD ans = solve(tasks);
        if (ans == -1) cout << ans << endl;
        else cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}
