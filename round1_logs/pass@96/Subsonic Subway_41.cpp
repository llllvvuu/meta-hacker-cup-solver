
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
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, pair<int, int>>> stations;

double solve(int n) {
    vector<pair<long long, long long>> intervals;
    for (int i = 1; i <= n; i++) {
        long long a = stations[i].second.first, b = stations[i].second.second;
        intervals.push_back({a * i, b * i});
    }
    sort(intervals.begin(), intervals.end());
    int prev = 0;
    long long prev_end = -1;
    for (int i = 0; i < n; i++) {
        long long start = (prev == 1) ? prev_end + 1 : intervals[i].first;
        prev_end = intervals[i].second;
        if (start > prev_end) return -1;
        prev = intervals[i + 1].first > prev_end;
    }
    return (double)(n * n) / prev_end;
}

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        cin >> n;
        stations.clear();
        stations.push_back({0, {0, 0}});
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            stations.push_back({i, {a, b}});
        }
        double result = solve(n);
        printf("Case #%d: %.7lf\n", test_case, result);
    }
    return 0;
}
