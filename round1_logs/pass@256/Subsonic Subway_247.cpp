
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
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const double INF = 1e9;

vector<pair<double, double>> prune_intervals(vector<pair<double, double>> intervals) {
    if (intervals.empty())
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<pair<double, double>> pruned;
    pruned.push_back(intervals[0]);
    for (auto [a, b] : intervals) {
        auto [prev_a, prev_b] = pruned.back();
        if (prev_b >= a) {
            pruned.pop_back();
            pruned.push_back({min(prev_a, a), max(prev_b, b)});
        } else 
            pruned.push_back({a, b});
    }
    return pruned;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<double, double>> intervals(N);
        for (int i = 0; i < N; i++) {
            cin >> intervals[i].second >> intervals[i].first;
            intervals[i].second *= 1.0 / i;
            intervals[i].first *= 1.0 / (i + 1);
        }
        intervals = prune_intervals(intervals);
        double min_speed = INF;
        for (auto [a, b] : intervals) {
            min_speed = min(min_speed, a);
        }
        cout << "Case #" << t << ": ";
        if (min_speed == INF) cout << "-1\n";
        else cout << fixed << setprecision(9) << 1 / min_speed << '\n';
    }
}   
