
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

vector<pair<int, int>> intervals;
double speed;

bool canSatisfy(int X) {
    int last = -1;
    for (pair<int, int> seg : intervals) {
        if (X < seg.first) return false;
        if (seg.second >= X + 0.0000001) 
            last = max(last, seg.second);
    }
    return last <= X;
}

double find_speed() {
    sort(intervals.begin(), intervals.end());
    speed = intervals.front().second / intervals.front().first;
    if (intervals.back().first + intervals.back().second > intervals.back().second) return -1;
    
    int N = intervals.size();
    if (N == intervals.back().first) speed = intervals.back().second;
    double left = 0, right = 10000000;
    while((right - left) / speed > 0.0000000001) {
        speed = (left + right) / 2;
        if (canSatisfy(speed * intervals.back().first))
            right = speed;
        else
            left = speed;
    }
    return speed;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        intervals.resize(N);
        for(int i = 0; i < intervals.size(); i++) {
            cin >> intervals[i].first >> intervals[i].second;
            intervals[i].first *= intervals[i].first;
            intervals[i].second *= intervals[i].first;
            if(intervals[i].first > intervals[i].second)
                intervals[i].second = -1;
        }
        sort(intervals.begin(), intervals.end());
        double speed = find_speed();
        if(speed == -1) cout << "Case #" << t << ": " << -1 << "\n";
        else cout << "Case #" << t << ": " << fixed << setprecision(9) << intervals.back().second / intervals.back().first << "\n";
    }
    return 0;
}
