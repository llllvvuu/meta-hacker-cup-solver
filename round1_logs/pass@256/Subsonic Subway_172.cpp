
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
    long long A, B, idx;
    bool operator<(const Interval& other) const {
        if (B == other.B) return idx < other.idx;
        return B < other.B;
    }
};

void solve(int tc) {
    int N;
    cin >> N;
    vector<Interval> intervals(N);
    for(int i = 0; i < N; i++) {
        cin >> intervals[i].A >> intervals[i].B;
        intervals[i].idx = i + 1;
    }
    sort(intervals.begin(), intervals.end());

    long long gap = intervals[0].A;
    bool possible = true;
    for(int i = 1; i < N; i++) {
        if (intervals[i].A < intervals[i-1].A) possible = false;
        gap = min(gap, intervals[i].A);
    }

    if (!possible) cout << "Case #" << tc << ": " << -1 << '\n';
    else {
        long double minSpeed = 1e18;
        for(int i = 0; i < N; i++) {
            minSpeed = min(minSpeed, (1LL * (intervals[i].idx) - gap) / double(intervals[i].idx));
        }
        cout << "Case #" << tc << ": " << setprecision(15) << fixed << (double)minSpeed << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) solve(t);
    return 0;
}
