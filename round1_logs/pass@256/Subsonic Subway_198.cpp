
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
#include <iostream>
#include <vector>
using namespace std;

double solve() {
    int N; cin >> N;
    vector<pair<double, double>> intervals(N);
    for (int i = 0; i < N; i++) {
        double A, B; cin >> A >> B;
        intervals[i] = {1.0 / B, 1.0 / A};  // Calculate inverse intervals
    }
    
    // Sort intervals by left corner (arrival as critical)
    sort(intervals.begin(), intervals.end(),
         [](const pair<double, double>& l, const pair<double, double>& r) {
             return l.first < r.first; 
         });

    // Combine overlapping & sequential intervals into segments 
    vector<pair<double, double>> merged;
    {
        auto L = intervals[0].first, R = intervals[0].second;
        for (int i = 1; i < N; i++) {
            if (intervals[i].first >= R) {
                merged.push_back({L, R});
                L = intervals[i].first; R = intervals[i].second;
            } else {
                R = max(R,intervals[i].second);
            }
        }
        merged.push_back({L, R});
    }

    double L = -1, R = 2000000;  // Wide bounds ensure an optimal range

    // Binary search to find minimal speed where Sonic intersects every station as needed
    while (R - L > 1e-7) {
        auto M = (L + R) / 2;
        double maxSpeedExceed = L;
        for (auto& I: merged) {
            double NS = M / (1 - M * I.second); // Sonic meet largest demand (tight window) PL
            double NE = M / (1 - M * (I.first + 1e-9)); // Sonic meet least demand (largest gap) PR
            maxSpeedExceed = max(maxSpeedExceed, (NS + NE) / 2);
        }

        if (maxSpeedExceed <= M) R = M;
        else L = M;
    }

    return R;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
}
