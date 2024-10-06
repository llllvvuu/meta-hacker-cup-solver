
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

bool check(double v, vector<pair<int, int>>& stations) {
    double time = 0.0;
    for (auto [a, b] : stations) {
        double next_time = 1.0 / v;
        time += next_time;
        if (time > b) return false;
        if (time > a) {
            v = 1.0 / (time - a);
            time = a;
        }
    }
    return time <= 1.0 / v;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> stations(N);
        for (auto& [a, b] : stations) cin >> a >> b;
        sort(stations.begin(), stations.end());
        double lo = -1, hi = 1e+6;
        auto [a, b] = stations[0];
        lo = 1.0 / b;
        while (hi - lo > 1e-6) {
            double v = (lo + hi) / 2.0;
            if (check(v, stations)) hi = v;
            else lo = v;
        }
        cout << "Case #" << t << ": ";
        if (check(lo, stations)) cout << fixed << setprecision(9) << 1 / hi << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
