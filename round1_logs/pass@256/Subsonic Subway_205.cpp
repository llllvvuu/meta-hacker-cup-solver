
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

const double EPS = 1e-9; // for handling floating point precision issues
pair<double, double> convertToRate(double a, double b) {
    return {1.0/b, 1.0/a};
}

double solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    vector<pair<double, double>> intervals;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        auto rateInterval = convertToRate(a, b);
        intervals.push_back(rateInterval);
    }
    sort(intervals.begin(), intervals.end());
    pair<double, double> merged = make_pair(EPS, 1.0/EPS);
    for (const auto& interval : intervals) {
        if (interval.first >= merged.second)
            return -1; // break if the new interval can't merge
        merged.first = max(merged.first, interval.first);
        merged.second = min(merged.second, interval.second);
    }
    return 1.0 / merged.first;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << fixed << setprecision(9) << solve() << endl;
    }
    return 0;
}
