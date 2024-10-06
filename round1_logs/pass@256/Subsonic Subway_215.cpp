
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
#define maxn 1000001

using namespace std;

struct Interval {
    double left, right;
};

vector<Interval> computeIntervals(double speed, vector<pair<double, double>> deliveries) {
    vector<Interval> intervals(deliveries.size());
    double accumulated = 0.0;
    for (int i = 0; i < deliveries.size(); ++i) {
        int station = i + 1; // starting at station 1
        double left = max<double>(0.0, accumulated + deliveries[i].first - station / speed);
        double right = accumulated + deliveries[i].second - station / speed;
        intervals[i] = {left, right};
        accumulated += station / speed;
    }
    return intervals;
}

bool isFeasible(double speed, vector<pair<double, double>>& deliveries) {
    vector<Interval> iv = computeIntervals(speed, deliveries);
    for (size_t i = 0; i < iv.size() - 1; ++i) {
        if (iv[i].second > iv[i + 1].left) {
            return false;
        }
    }
    return true;
}

double epsilon = 1e-10;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n;
        cin >> n;
        vector<pair<double, double>> deliveries(n);
        for (int i = 0; i < n; ++i) {
            cin >> deliveries[i].first >> deliveries[i].second;
        }
        double low = 0.0, high = n + epsilon;
        for (int i = 0; i < 100; ++i) {
            double mid = (low + high) / 2.0;
            if (!isFeasible(mid, deliveries)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        double result = low;
        if (isFeasible(result, deliveries)) {
            printf("Case #%d: %.6f\n", tc, result);
        } else {
            printf("Case #%d: -1\n", tc);
        }
    }
    return 0;
}
