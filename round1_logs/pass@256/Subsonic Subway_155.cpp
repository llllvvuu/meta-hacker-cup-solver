
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

pair<double, double> extend(pair<double, double> l, pair<double, double> r) {
    pair<double, double> opt, l1 = l, r1 = r;
    if (l1.first > r1.second) return {-1, -1};
    l1.first = max(l1.first, r1.first);
    r1.first += l1.first;
    l1.second = max(l1.second, r1.first);
    r1.second += r1.first - l1.second;
    return {r1.first / r1.second, l1.second / l1.first};
}

int N;
pair<int, int> A[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector<pair<double, double>> intervals(2);
        intervals[1] = {0, 1e6};
        vector<pair<double, double>> merged;
        for (int i = 0; i < N; i++) {
            cin >> A[i].first >> A[i].second;
            merged = vector<pair<double, double>>(intervals.size());
            for (auto it : intervals) {
                if (it.second >= 1 && 1.0 <= it.first) {
                    merged.push_back({min((double)A[i].second / i, (double)A[i].second), (double)A[i].first / i});
                } else if (it.first <= 1.0 && it.second >= 1) {
                    merged.push_back({min(1.0, (double)A[i].second / i), max(1, (double)A[i].first / i)});
                } else if (i == 1) {
                    merged.push_back({min(1, (double)A[i].second), (double)A[i].first});
                } else {
                    merged.push_back({1, 1});
                }
            }
            intervals = merged;
        }
        sort(intervals.begin(), intervals.end());
        double res = intervals[0].first;
        for (auto it : intervals) {
            res = min(res, it.first);
        }
        cout << "Case #" << t << ": " << res << "\n";
    }
    return 0;
}
