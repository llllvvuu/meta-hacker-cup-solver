
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
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

const int64_t INF = 1000000000000;

struct Segtree {
    int64_t n;
    vector<pair<int64_t, int64_t>> t;
    
    void init(int64_t N) {
        n = 1;
        while (n < N) n *= 2;
        t.resize(2 * n - 1);
        for (auto& p : t) p = {INF, 0};
    }

    void update(int64_t i, int64_t tl, int64_t tr, int64_t ind, int64_t a, int64_t b) {
        if (ind + 1 > b || ind < a) return;
        if (a <= ind && ind + 1 <= b) {
            t[i].first = min(t[i].first, 1);
            return;
        }
        int64_t tm = (tl + tr) / 2;
        update(2 * i + 1, tl, tm, ind, a, b);
        update(2 * i + 2, tm + 1, tr, ind, a, b);
        t[i] = {min(t[2 * i + 1].first, t[2 * i + 2].first), max(t[2 * i + 1].second, t[2 * i + 2].second)};
    }

    bool query(int64_t i, int64_t tl, int64_t tr, int64_t ind) {
        if (tl == tr) {
            return t[i].first;
        }
        int64_t tm = (tl + tr) / 2;
        if (ind <= tm) return query(2 * i + 1, tl, tm, ind);
        else return query(2 * i + 2, tm + 1, tr, ind);
    }
};

void solve() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    vector<int64_t> times;
    for (int64_t i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        times.push_back(A[i] + i);
        times.push_back(B[i] + i);
    }
    sort(times.begin(), times.end());
    times.resize(unique(times.begin(), times.end()) - times.begin());
    int64_t maxdist = N;
    Segtree seg;
    seg.init(times.size());

    auto translate = [&](int64_t t) {
        return lower_bound(times.begin(), times.end(), t) - times.begin();
    };

    auto check = [&](int64_t speed) {
        seg.init(times.size());
        for (int64_t i = 0; i < N; i++) {
            int64_t d = i + 1;  // Distance to station i
            int64_t start = (A[i] + d) / speed;
            int64_t arrival = translate(start); 
            int64_t departure = translate((B[i] + d) / speed);
            if (query(arrival, departure) != 0) return false;
            seg.update(0, 1, times.size() - 1, arrival, departure, 1);
        }
        return true;
    };

    double lo = -1, hi = maxdist * 1e6;
    while (hi - lo > 1e-9) {
        double m = (hi + lo) / 2;
        if (check(m)) hi = m;
        else lo = m;
    }
    cout << fixed << setprecision(6) << hi << endl;
}

int main() {
    int64_t T;
    cin >> T;
    for (int64_t t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
