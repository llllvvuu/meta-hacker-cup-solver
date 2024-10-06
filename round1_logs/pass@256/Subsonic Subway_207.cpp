
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

struct delivery {
    int start, end;
    delivery(int s, int e): start(s), end(e) {}
    bool operator<(const delivery &d2) const {
        if (start == d2.start) return (end < d2.end);
        return (start < d2.start);
    }
} d[1000001];
vector<delivery> sweep;

int N;

double intersect(int i) {
    if (sweep.empty()) return 1e9;
    // Check if there's an intersection
    double start = sweep[0].start;
    for (auto &ticket : sweep) {
        // Sweep valid windows of tickets
        if (ticket.end < start) continue;  // Out of sweep range
        if (ticket.start <= start) sweep.pop_back();
        else return 1e9;  // No overlap
    }
    sweep.push_back(delivery(i + 1 - start, 1e9 - 1));
    return sweep.size() > 1 ? sweep[1].end : 1e9;  // Next intersection
}

double cut(double speed) {
    vector<delivery> sweep2;
    for (int station = 1; station <= N; ++station) {
        double end = (double)station / speed;
        if (end < d[station].start) return intersect(station);
        sweep2.push_back(delivery(end - 1, d[station].end - station / speed));
    }
    return intersect(N + 1);
}

const double EPS = 1e-9;
const double INF = 1e9;

bool prune(double speed_l, double speed_r) {
    return fabs(speed_l - speed_r) / ((speed_l + EPS) + (speed_r + EPS)) < EPS;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> d[i].start >> d[i].end;
        }
        double lo = -1.0, hi = max(1.0, d[N].end / N), ans = -1;
        while (!prune(lo, hi)) {
            double mid = (hi + lo) / 2;
            if (cut(mid) <= 1 + EPS) {
                ans = mid;
                lo = mid;
            } else {
                hi = mid;
            }
        }
        printf("Case #%d: %.10f\n", t, ans);
    }
    return 0;
}
