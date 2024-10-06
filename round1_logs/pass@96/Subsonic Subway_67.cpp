
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
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const double EPSILON = 1e-6;

double check(vector<pair<double, double>>& intervals, double speed) {
    vector<double> deliveryTimes;
    for (auto [A, B] : intervals) {
        deliveryTimes.push_back(max(0.0, (A - speed) / speed));
        deliveryTimes.push_back((B - speed) / speed);
    }

    sort(begin(deliveryTimes), end(deliveryTimes));

    for (int i = 1; i < intervals.size(); ++i) {
        double necessaryTime = (deliveryTimes[i] - deliveryTimes[i - 1]) / 2;
        if (speed * necessaryTime < intervals[i].first) {
            return -1.0; // Impossible to make delivery on time
        }
    }
    return deliveryTimes.back() / intervals.size();
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<pair<double, double>> intervals(N);
        for (auto& [A, B] : intervals) {
            cin >> A >> B;
            A /= A + B;
            B /= A + B;
        }
        double lo = 0.0, hi = (intervals[N-1].second + 1) * N;
        for (int i = 0; i < 100; ++i) { // Binary search loop
            double mid = (lo + hi) / 2;
            bool can = check(intervals, mid) > -1;
            if (can) hi = mid;
            else lo = mid;
        }
        cout << "Case #" << t << ": " << fixed << setprecision(6) << (lo == -1 ? -1.0 : lo) << endl;
    }
    return 0;
}
