
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

typedef long double ld;

const ld INF = 1e18;

ld solve(const vector<pair<ld, ld>> &intervals) {
    // Binary search on speed from slightly above zero to astronomical values
    // Lower bound of speed is 1/infinity = 0, but we need a slight positive value specifically to handle the second test case where every delivery window is identical
    ld L = 0.00000001, R = INF;
    ld lo = L, hi = R;

    int N = intervals.size();
    // This just attempts 60 rounds of binary search
    for (int i = 0; i < 60; i++) {
        ld m = (L + R) / 2;
        ld prev = L;
        bool valid = true;

        // The largest t where m < intervals[i].first/i , we test m against this t from i = 0 to i = n i-1
        for (int j = 0, max_t = -1; j < N; j++) {
            ld cur = max(max_t, ld(intervals[j].first) / ld(j+1));
            ld rem = ld(intervals[j].second) / ld(j+1); 
            if (cur > rem) {
                valid = false;
                break;
            }
            max_t = cur;
        }

        if (valid) {
            R = m;
        } else {
            L = m;
        }
    }
    return (L + R) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<int,int>> intervals(N);
        for (int j = 0; j < N; ++j) {
            cin >> intervals[j].second >> intervals[j].first;
            intervals[j].first = -intervals[j].first;
        }
        sort(intervals.begin(), intervals.end());
        cout << "Case #" << t << ": " << solve(intervals) << '\n';
    }
    return 0;
}
