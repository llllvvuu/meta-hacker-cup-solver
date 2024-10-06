
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

const int LIMIT = 1000001;

struct Interval {
    int A;
    int B;
    int index;
};

bool canDeliver(vector<Interval> &intervals, double speed) {
    for (Interval &interval : intervals) {
        double timeRequired = interval.index / speed;
        if (timeRequired < interval.A || timeRequired > interval.B) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Interval> intervals(N);
        for (int i = 0; i < N; i++) {
            cin >> intervals[i].A >> intervals[i].B;
            intervals[i].index = i + 1;
        }
        sort(intervals.begin(), intervals.end(), [](Interval &x, Interval &y) {
            return x.index < y.index;
        });
        double L = 0, U = LIMIT, mid;
        while (U - L > 1e-6) {
            mid = (L + U) / 2;
            if (canDeliver(intervals, mid)) {
                U = mid;
            } else {
                L = mid;
            }
        }
        double minSpeed = (L + U) / 2;
        cout << "Case #" << t << ": " << fixed << setprecision(4) << minSpeed << "\n";
    }
    return 0;
}
