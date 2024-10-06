
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
#include <algorithm>
using namespace std;

const double EPSILON = 1e-6; 

int N;
vector<pair<int, int>> stations;

double getSpeed(pair<int, int> &station, int miles) {
    return (double)miles / station.first;
}

bool canDeliver(double speed) {
    vector<pair<double, double>> speed_lines;
    for (auto station : stations) {
        speed_lines.emplace_back(station.first / speed, station.second / speed);
    }
    speed_lines.push_back({0, 0});
    sort(speed_lines.begin(), speed_lines.end());
    
    double cur_day_ends = 0;
    for (auto [line_start, line_end] : speed_lines) {
        if (line_start > cur_day_ends + EPSILON) return false;
        cur_day_ends = max(line_end, cur_day_ends);
    }
    return cur_day_ends >= stations.back().second / speed;
}

double solve() {
    cin >> N;
    stations.resize(N);
    for (auto &station : stations)
        cin >> station.first >> station.second;

    double left = 0;
    double right = 1;
    while (right - left > EPSILON) {
        double mid = (left + right) / 2;
        if (canDeliver(mid))
            right = mid;
        else
            left = mid;
    }
    double result = (left + right) / 2;
    if (canDeliver(result))
        return result;
    return -1;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}
