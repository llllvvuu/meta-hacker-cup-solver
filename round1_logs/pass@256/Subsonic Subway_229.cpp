
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

const double PRECISION = 1e-6;

struct Station {
    int i;
    int A;
    int B;
};

double getMinimalSpeed(const vector<Station>& stations) {
    double lo = PRECISION;
    double hi = 1e8;
    
    while (hi - lo > PRECISION) {
        double mid = (lo + hi) / 2.0;
        bool valid = true;
        double lastCheckpoint = 0;
        
        for (const auto& station : stations) {
            double lowerBound = max(static_cast<double>(station.i) / station.B, lastCheckpoint);
            double upperBound = static_cast<double>(station.i) / station.A;
            if (lowerBound > upperBound || mid < lowerBound) {
                valid = false;
                break;
            }
            lastCheckpoint = upperBound;
        }
        if (valid) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    
    return lo;
}

int main() {
    int T;
    cin >> T;
    vector<Station> stations;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        stations.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> stations[i].A >> stations[i].B;
            stations[i].i = i + 1;
        }
        sort(stations.begin(), stations.end());
        double speed = getMinimalSpeed(stations);
        cout << "Case #" << t << ": ";
        if (speed < 1e-6) {
            cout << "-1" << endl;
        } else {
            cout << speed << endl;
        }
    }
    return 0;
}
