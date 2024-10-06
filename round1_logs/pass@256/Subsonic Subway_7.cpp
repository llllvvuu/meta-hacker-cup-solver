
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
using namespace std;

struct Station {
    int A, B;
    Station(int a = 0, int b = 0) : A(a), B(b) {}
};

double binarySearchMinSpeed(const vector<Station>& stations, int n) {
    double low = 0, high = 10'000;
    for (int it = 0; it < 100; it++) {
        double mid = (low + high) / 2;
        bool valid = true;
        int arriveBy = stations[0].B / mid;
        for (int i = 1; i < n; i++) {
            int reachBy = stations[i].A / mid;
            if (arriveBy > reachBy) {
                valid = false;
                break;
            }
            arriveBy = stations[i].B / mid;
        }
        if (valid) high = mid;
        else low = mid;
    }
    return low;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
        int n;
        cin >> n;
        vector<Station> stations(n);
        for (Station& s : stations) cin >> s.A >> s.B;
        
        if (!all_of(stations.begin(), stations.end(), [](const Station& s) {
            return s.A <= s.B;
        })) {
            cout << "Case #" << t << ": -1\n";
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            if (stations[i].B >= stations[i + 1].A) {
                cout << "Case #" << t << ": -1\n";
                break;
            }
        }
        if (t == 1) continue;

        double speed = binarySearchMinSpeed(stations, n);
        cout << "Case #" << t << ": " << fixed << setprecision(9) << speed << '\n';
    }
    return 0;
}
