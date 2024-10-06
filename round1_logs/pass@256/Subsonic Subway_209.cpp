
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
using ld = long double;

struct Interval {
    int station;
    ld start;
    ld end;
    
    Interval(int station, ld start, ld end) : station(station), start(start), end(end) {}
    
    friend bool operator < (const Interval& l, const Interval& r) {
        return l.start < r.start;
    }
};

ld closestMerge(const vector<Interval>& intervals) {
    int n = intervals.size();
    vector<Interval> merged;
    for (auto& interval : intervals) {
        if(merged.empty() || merged.back().end < interval.start) {
            merged.back().end = max(merged.back().end, interval.end);
        } else {
            merged.push_back(interval);
        }
    }
    return 1.0 / merged.back().start;
}

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;
        vector<Interval> intervals(n);
        for (int i = 0; i < n; i++) {
            int start, end;
            cin >> start >> end;
            intervals[i] = Interval(i, start / i, end / i);
        }
        sort(intervals.begin(), intervals.end());
        cout << "Case #" << cs << ": ";
        auto ans = closestMerge(intervals);
        if (ans >= 1e7) {
            cout << -1 << endl;
        } else {
            cout << fixed << setprecision(10) << 1.0 / ans << endl;
        }
    }
    return 0;
}
