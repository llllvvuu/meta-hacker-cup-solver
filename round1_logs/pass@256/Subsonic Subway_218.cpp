
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

int T;
int N;
vector<pair<long long, long long>> intervals;

double binary_search_speed() {
    long double low = 0, high = 1e9;
    for(int i = 0; i < 100; i++) {  // Sufficient iteration for precision
        long double mid = (low + high) / 2;
        bool valid = true;
        for (int i = 0; i < N; i++) {
            long double L = intervals[i].first, R = intervals[i].second;
            double neededL = intervals[i].first * mid;
            double currentR = intervals[i].second * mid;
            
            if (neededL > (i + 0.0) || currentR < (i + 0.0)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        vector<pair<long long, long long>> valid_times;
        cin >> N;
        intervals.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        double speed = binary_search_speed();
        if (speed > 1e9) {
            cout << "Case #" << t << ": " << -1 << '\n';
        } else {
            cout << "Case #" << t << ": " << fixed << setprecision(6) << speed << '\n';
        }
    }
    return 0;
}
