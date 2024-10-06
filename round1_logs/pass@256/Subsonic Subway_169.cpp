
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
#include <iostream>
#include <vector>
using namespace std;

pair<double, double> stations[1000000]; // each station's delivery window
bool checkSpeed(double speed, int N) {
    // Check if the speed allows all deliveries on time
    double prev = 0;
    for (int i = 1; i <= N; i++) {
        double requiredTime = i / speed; // when we expected to be at station i
        if (stations[i - 1].second <= requiredTime || stations[i - 1].first > requiredTime) return false; 
        prev = max(prev, requiredTime);
    }
    return true;
}

double solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> stations[i].first >> stations[i].second;
    }
    sort(begin(stations), end(stations));
    double lo = 0, hi = 1e9;
    while (hi - lo > 1e-9) { // need a fixed precision for checking right after the loop
        double mid = (lo + hi) / 2;
        if (checkSpeed(mid, N)) hi = mid;
        else lo = mid;
    }
    return checkSpeed(lo, N) ? lo : -1; // create room at the end to check slightly lower (more realistic speed) just in case of float imprecision
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << fixed << setprecision(6) << solve() << endl; 
    }
    return 0;
}
