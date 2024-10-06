
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

struct Interval {
    int i, ai, bi;

    // Constructor to initialize a station's delivery intervals
    Interval(int _ai, int _bi, int _i) : ai(_ai), bi(_bi), i(_i) {}

    // Comparison operator to sort intervals by B_i * i
    bool operator<(const Interval &o) const {
        return 1. * bi * i > 1. * o.bi * o.i;
    }
};

const int MAXN = 1000005;
const int INF = MAXN * MAXN;
const long double EPS = 1e-9;

long double rangeLower(const Interval &i) {
    return 1. * i.i / i.bi;
}

long double rangeUpper(const Interval &i) {
    return 1. * i.i / i.ai;
}

Interval intersectR(const Interval &i1, const Interval &i2) {
    return Interval(
        max(i1.ai, i2.ai),
        min(i1.bi, i2.bi),
        i1.i
    );
}

Interval intersectL(const Interval &i1, const Interval &i2) {
    return Interval(
        max(i1.ai, i2.ai),
        min(i1.bi, i2.bi),
        i1.i
    );
}
    
int solve(int N) {
    vector<Interval> intervals(N);
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].ai >> intervals[i].bi;
        intervals[i].i = i + 1;
    }
    sort(intervals.begin(), intervals.end());

    Interval cur = intervals[0];
    for (int i = 1; i < N; i++) {
        Interval next = intervals[i];
        Interval newRange = (rangeLower(cur) <= rangeLower(next)
                             && rangeUpper(cur) >= rangeLower(next))
                            ? intersectR(cur, next)
                            : intersectL(cur, next);

        if (newRange.bi > INF) return -1;
        cur = newRange;
    }
    
    return 1. / rangeLower(cur);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
    return 0;
}
