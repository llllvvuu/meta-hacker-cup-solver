
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

const long double INF = 1e12;

struct Interval {
    long double start, end;
    Interval(long double start, long double end) : start(start), end(end) {}
};

Interval intersect(const Interval& a, const Interval& b) {
    long double start = max(a.start, b.start);
    long double end = min(a.end, b.end);
    return Interval(start, end);
}

// Check if there exists a constant speed v that fulfills all the conditions
bool is_valid_speed(vector<Interval> & intervals, long double v) {
    long double current_time = 0;
    for (const Interval & value : intervals) {
        Interval temp = intersect(Interval(current_time, INF), value);
        temp = Interval(temp.start + 1.0/v, temp.end + 1.0/v);  // Adjust by speed v
        if (temp.start > temp.end) {
            return false;
        }
        current_time = temp.end;
    }
    return true;
}

void process_case() {
    int N;
    cin >> N;
    vector<Interval> intervals(N);
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        if (start > end) {
            start = end;
        }
        intervals[i] = Interval(start, end);
    }
    long double low = 0, high = INF;
    for (int runs = 55; runs--; ) {
        long double mid = (low + high) / 2;
        if (is_valid_speed(intervals, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    if (high - low > 1e-8) high = -1;
    cout << fixed << setprecision(6) << high << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        process_case();
    }
    return 0;
}
