
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
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

struct Interval {
    int l, r, idx; // left end, right end, station number
};

bool compare(const Interval &a, const Interval &b) {
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        vector<Interval> intervals(N);
        for (int i = 0; i < N; i++) {
            cin >> intervals[i].l >> intervals[i].r;
            intervals[i].idx = i;
        }
        sort(intervals.begin(), intervals.end(), compare);

        bool isPossible = true;
        long double lastReleased = 0;
        long double minSpeed = 0;
        for (auto &ival : intervals) {
            if (ival.l > ival.r) {
                isPossible = false;
                break;
            }

            // We need to choose a speed at which ival.l <= time < ival.r + ival.idx + 1
            if (interval.l > lastReleased || ival.l >= ival.r + ival.idx + 1) {
                isPossible = false;
                break;
            }

            minSpeed = max(minSpeed, static_cast<long double>(ival.r + ival.idx + 1 - ival.l) / ival.idx);
            lastReleased = ival.r + ival.idx + 1;
        }
        if (!isPossible) {
            cout << "-1" << endl;
        } else {
            double speed = 1 / minSpeed;
            cout << fixed << setprecision(9) << speed << endl;
        }
    }
    return 0;
}
