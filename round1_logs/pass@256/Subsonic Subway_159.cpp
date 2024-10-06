
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
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    double start, end;
    bool operator<(const Interval &other) const {
        return this->start < other.start;
    }
};

vector<Interval> transform(int d, const vector<pair<int, int>> &times, double v) {
    vector<Interval> transformed;
    for (auto [a, b] : times) {
        double start = (d * v - b) / v;
        double finish = (d * v - a) / v;
        transformed.push_back({start, finish});
    }
    return transformed;
}

bool check(double v, const vector<pair<int, int>> &times) {
    double curr = 0;

    multiset<Interval> active;

    for (int i = 1, j = 1; i <= times.size(); i++) {
        auto [a, b] = times[i - 1];

        while (j < times.size() && times[j - 1].second < a / (v + 1e-9)) {
            auto [next_a, next_b] = times[j - 1];
            Interval canDeliever{next_a / v, next_b / v};
            if (canDeliever.start >= curr) {
                curr = canDeliever.end;
                break;
            }
            active.insert(canDeliever);
            j++;
        }
        if (curr >= a / (v + 1e-9)) {
            active.erase(prev(active.lower_bound({curr, 0})));
            curr = max(curr, times[j - 1].second / v);
            continue;
        }
        if (active.empty()) return false;
        auto lower = *active.begin();
        curr = max(curr, max(lower.start, a / (v + 1e-9)));
        active.erase(active.begin());
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> times;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.emplace_back(a, b);
    }

    double lo = 0, hi = 1e6 + 1e-9;
    while (hi - lo >= 1e-6) {
        double mid = (lo + hi) / 2;
        if (check(mid, times)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    double ans = hi;
    if (!check(ans, times)) {
        ans = -1;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}
