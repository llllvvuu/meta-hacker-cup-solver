
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
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<pair<long long, long long>> intervals;
int N;

bool cmp(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return a.first < b.first;
}

double solve() {
    cin >> N;
    intervals.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    long long l = 0;
    double res = 0;
    for (int i = 0; i < N; i++) {
        intervals[i].first -= l;
        intervals[i].second -= l;
        l = max(l, intervals[i].second);
        res = max(res, (double)(i + 1) / intervals[i].second);
    }
    if (l < N) return -1;
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
