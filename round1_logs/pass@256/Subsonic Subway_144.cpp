
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
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

const int MAX_T = 95;
const int MAX_N = 1000000;

int T, N;
vector<pair<long long, long long>> intervals[MAX_T];

long long solve() {
    long long best = LLONG_MAX;
    vector<pair<long long, long long>> points;
    for (auto p : intervals[N]) {
        points.push_back({p.first * N, -1});
        points.push_back({p.second * N, 1});
    }
    sort(points.begin(), points.end());
    long long cnt = 0;
    for (int i = 0; i < points.size(); i++) {
        best = min(best, (points[i].first-((long long)N)*cnt));
        cnt += points[i].second;
        if (cnt == 0 && best > 0) {
            return -1.0;
        }
    }
    return (double)best / N;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        intervals[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> intervals[i][j].first >> intervals[i][j].second;
        }
        cout << "Case #" << i+1 << ": " << setprecision(8) << solve() << endl;
    }
}
