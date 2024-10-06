
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
#include <iomanip>
using namespace std;

double EPS = 1e-11;

bool isFeasible(vector<pair<int, int>>& stationWindows, double speed) {
    vector<double> earliestWindows(stationWindows.size());
    for (int i = 0; i < stationWindows.size(); ++i) {
        double arrivalTime = (i + 1) / speed;
        // Exclusive lower bound, inclusive upper bound
        earliestWindows[i] = max(stationWindows[i].first + EPS, stationWindows[i].second - EPS);
        earliestWindows[i] = min(earliestWindows[i], arrivalTime);
    }

    return *min_element(earliestWindows.begin(), earliestWindows.end()) >= 0;
}

double findMinSpeed(vector<pair<int, int>>& stationWindows) {
    double minSpeed = 0, maxSpeed = 1000000;
    double bestFeasibleSpeed = maxSpeed;

    while (maxSpeed - minSpeed > EPS) {
        double midSpeed = (minSpeed + maxSpeed) / 2;
        if (isFeasible(stationWindows, midSpeed)) {
            bestFeasibleSpeed = midSpeed;
            maxSpeed = midSpeed;
        } else {
            minSpeed = midSpeed;
        }
    }

    return nearestFeasibleSpeed(stationWindows, bestFeasibleSpeed);
}

double nearestFeasibleSpeed(vector<pair<int, int>>& stationWindows, double candidate) {
    if (isFeasible(stationWindows, candidate - EPS)) return candidate;
    if (isFeasible(stationWindows, candidate + EPS)) return candidate;
    return -1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << setprecision(6);
        int N;
        cin >> N;
        vector<pair<int, int>> stationWindows(N);
        for (int i = 0; i < N; ++i) {
            cin >> stationWindows[i].first >> stationWindows[i].second;
        }
        double minSpeed = findMinSpeed(stationWindows);
        cout << "Case #" << t << ": " << minSpeed << endl;
    }
    return 0;
}
