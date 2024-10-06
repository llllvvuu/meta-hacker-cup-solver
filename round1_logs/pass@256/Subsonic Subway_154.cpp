
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

#define EPS 1e-9 // precision error for floating point comparisons

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long N;
        cin >> N;
        vector<double> minSpd(N + 1);  // minimum speed needed at each station
        vector<double> maxSpd(N + 1);  // maximum speed possible at each station

        for (int i = 1; i <= N; i++) {
            double a, b;
            cin >> a >> b;
            minSpd[i] = 1.0 * i / b;
            maxSpd[i] = 1.0 * i / a;
        }

        // Binary search parameters
        double low = 0, high = 1e9, mid;
        int iter = 0;

        // Binary search for speed V that satisfies all constraints
        while(abs(low - high) > EPS && iter < 1000) {
            mid = (low + high) / 2;
            bool feasible = true;
            for (int i = 1; i <= N; i++) {
                if (!(minSpd[i] <= mid && mid <= maxSpd[i])) {
                    feasible = false;
                    break;
                }
            }
            if (feasible) low = mid;
            else high = mid;
            iter++;
        }

        double result = (low + high) / 2;
        cout << "Case #" << t << ": ";
        if (result < -1 + 2 * EPS) cout << -1;
        else cout << fixed << setprecision(9) << result;
        cout << "\n";
    }
    return 0;
}
