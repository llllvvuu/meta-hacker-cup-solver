
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

const double INF = 1e9;

struct Station {
    int index, A, B;
    double s_lo, s_hi;
};

bool operator< (const Station& s1, const Station& s2) {
    if (s1.s_hi != s2.s_hi) {
        return s1.s_hi < s2.s_hi;
    }
    return s1.index < s2.index;
}

double minimum_speed(vector<Station>& stations) {
    sort(stations.begin(), stations.end());
    double speed = 0;
    for (Station s: stations) {
        speed = max(speed, double(s.index) / s.A);
    }
    return speed;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Station> stations(N);
        for (int i = 0; i < N; i++) {
            cin >> stations[i].A >> stations[i].B;
            stations[i].index = i + 1;
            stations[i].s_lo = double(stations[i].index) / stations[i].B;
            stations[i].s_hi = double(stations[i].index) / stations[i].A;
        }
        double ans = minimum_speed(stations);
        cout << "Case #" << t << ": ";
        cout << (ans > INF ? "-1" : ans) << '\n';
    }
    return 0;
}
