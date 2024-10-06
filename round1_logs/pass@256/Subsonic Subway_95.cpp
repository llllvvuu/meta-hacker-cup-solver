
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

#define int long long
#define all(v) (v).begin(), (v).end()
const int INF = 1e18;

double A[1000001], B[1000001];

bool intervalsOverlap(double lo1, double hi1, double lo2, double hi2) {
    return lo2 <= hi1 && lo1 <= hi2;
}

bool check(double v) {
    int N;
    cin >> N;
    vector<double> limits(N);
    vector<double> options;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        options.push_back(i/v);
        limits[i] = i/v;
    }
    sort(all(options));
    for (int i = 0; i < N; i++) {
        limits[i] = (options[i] > A[i]) ? options[i] : A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        limits[i] = (i/v < B[i]) ? i/v : B[i];
    }

    for (int i = 1; i < N; i++) {
        if (!intervalsOverlap(limits[i-1], limits[i], (i-1)/v, i/v)) return false;
    }
    return true;
}

int solve() {
    cin >> N;
    double low = 0.0, high = 1e7;
    for (int it = 0; it < 64; it++) {
        double mid = (low + high) / 2;
        if (check(mid)) high = mid;
        else low = mid;
    }
    double speed = high;
    high /= 1000;
    low /= 1000;
    if (high != low) return -1;
    return round(speed * 1000) / 1000.0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
