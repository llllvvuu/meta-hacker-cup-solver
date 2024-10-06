
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
#include <iostream>
#include <vector>
#include <unordered_map>

bool canDeliver(const std::vector<long long>& intervals, long double speed) {
    long double time_left = 0.0;
    std::unordered_map<long long, std::vector<long long>> time_windows;
    
    // Match station index to delivery intervals.
    for (int i = 1; i < intervals.size(); i += 2) {
        time_windows[intervals[i-1]] = {intervals[i], intervals[i+1]};
    }

    for (const auto&[station, bndrs]: time_windows) {
        // calculate time of arrival.
        time_left += (long double) station / speed;

        if (time_left > bndrs[1]) return false;  // Beyond delivery window.
        if (time_left < bndrs[0]) speed = station / (bndrs[0] - time_left);  // Speed adjustment.
    }
    return true;
}

int main() {
    int T;
    std::cin >> T;
    
    for (int t = 1; t <= T; t++) {
        long long N, a, b;
        std::cin >> N;
        std::vector<long long> intervals(2 * N);
        
        // Input intervals for stations.
        for (int i = 0; i < 2 * N; i += 2) {
            std::cin >> b >> a;
            intervals[i] = b;
            intervals[i + 1] = a;
        }
        
        long double l = 0; // naive initial lower bound.
        long double r = 1e10; // Initial upper bound.
        
        // Binary search for smallest valid speed.
        long double ans = -1;
        while (r - l > 1e-6) {
            long double mid = (l + r) / 2;
            if (canDeliver(intervals, mid)) {  // Faster speeds could be valid too.
                ans = mid;
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("Case #%d: %.12Lf\n", t, ans);
    }
    return 0;
}
