
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

bool canDeliver(vector<pair<int,int>>& stnWindows, double speed, int N) {
    double curTime = 0;
    for (int i = 0; i < N; i++) {
        double dist = i + 1;
        double arrivalTime = curTime + dist / speed;
        curTime = max(arrivalTime, stnWindows[i].first);
        if (curTime > stnWindows[i].second) 
            return false;
    }
    return true;
}

double findMinSpeed(vector<pair<int,int>>& stnWindows, int N) {
    double low = 0.000000001;
    double high = N * 1000000;
    double precision = 0.000000001;
    while (high - low > precision) {
        double mid = (low + high) / 2;
        if (canDeliver(stnWindows, mid, N)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> stnWindows(N);
        for (auto& [a, b] : stnWindows) cin >> a >> b;

        double speed = findMinSpeed(stnWindows, N);
        cout << "Case #" << t << ": " << setprecision(7) << fixed << speed << endl;
    }
    return 0;
}
