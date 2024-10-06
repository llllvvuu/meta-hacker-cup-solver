
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
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using dbl = double;

dbl PRECISION = 1e-9;

// Determines if a given speed is sufficient for Sonic
bool is_valid(const dbl speed, const vector<vector<dbl>>& stations) {
    for (const auto& [a, b] : stations) {
        if (speed < a / speed || speed > b / speed) return false; 
    }
    return true;
}

// Computes the minimum speed required for Sonic
dbl find_speed(const vector<vector<dbl>>& stations) {
    dbl low = 0.0, high = 1.0e9;
    while (high - low > PRECISION) {
        dbl mid = (low + high) / 2.0;
        if (is_valid(mid, stations)) low = mid;
        else high = mid;
    }
    return low;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<vector<dbl>> stations(N, vector<dbl>(2));
        for (int i = 0; i < N; i++) {
            cin >> stations[i][0] >> stations[i][1];
        }
        dbl min_speed = find_speed(stations);
        cout << "Case #" << t << ": " 
             << fixed << setprecision(9) 
             << (is_valid(min_speed, stations) ? min_speed : -1) << endl;
    }
    return 0;
}
