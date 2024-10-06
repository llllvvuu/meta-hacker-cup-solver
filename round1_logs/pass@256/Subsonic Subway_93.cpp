
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
#include <algorithm>
#include <cmath>
using namespace std;

double binary_search_speed(const vector<pair<int, int>>& stations, int N) {
    double left = 0;
    double right = (double) N / *min_element(begin(stations), end(stations), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }).second;
    
    while (right - left > 1e-6) {
        double mid = (left + right) / 2;
        bool feasible = true;
        
        for (int i = 1; i <= N && feasible; ++i) {
            if (i / mid < stations[i-1].first || i / mid > stations[i-1].second) {
                feasible = false;
            }
        }

        if (feasible) right = mid;
        else          left = mid;
    }

    return left; // Returns the feasible speed or close to -1 if not feasible.
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        vector<pair<int, int>> stations(N);
        for (int i = 0; i < N; ++i) {
            cin >> stations[i].first >> stations[i].second;
        }

        double result = binary_search_speed(stations, N);
        cout << "Case #" << t << ": " << fixed << setprecision(7) << (result >= 1e-6 ? result : -1) << endl;
    }
    return 0;
}
