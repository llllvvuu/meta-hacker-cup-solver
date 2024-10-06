
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
#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long double ld;

const ld eps = 1e-7;

array<ld, 2> get_shifts(const vector<pair<ld, ld>> &windows, ld speed) {
    int N = windows.size();
    vector<ld> turns(N+1);
    for (int i = 0; i < N; i++) {
        turns[i+1] = max(windows[i].second, turns[i] + speed);
    }

    vector<ld> leaves(N+1);
    for (int i = N-1; i >= 0; i--) {
        leaves[i] = min(windows[i].first, speed + leaves[i+1]);
    }

    return {turns[0], leaves[N], *min_element(begin(turns), end(turns)), *max_element(begin(leaves), end(leaves))};
}

bool legal(const vector<pair<ld, ld>> &windows, ld speed, ld lo, ld hi) {
    ld a = ak(speed, windows);
    if (a < windows[0].first || a > windows[0].second) return false;

    ld b = bk(lo, hi, speed);
    for (int i = 0; i < windows.size() - 1; i++) {
        if (b < windows[i + 1].first || b > windows[i + 1].second) return false;
        b += speed;
    }
    return true;
}

ld solve(int N, vector<pair<ld, ld>> windows) {
    ld lo = 0, hi = 1e6;
    while ((hi - lo) > eps) {
        ld speed = (lo + hi) / 2;
        auto turns = get_shifts(windows, speed);
        if (legal(windows, speed, turns[0], turns[1])) {
            hi = speed;
        } else {
            lo = speed;
        }
    }
    return (hi + lo) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<ld, ld>> windows(N);
        for (int i = 0; i < N; i++) {
            ld A, B;
            cin >> A >> B;
            windows[i] = {A, B};
        }
        cout << "Case #" << t << ": ";
        cout << fixed << setprecision(12) << (solve(N, windows) == 0 ? -1 : solve(N, windows)) << endl;
    }
    return 0;
}
