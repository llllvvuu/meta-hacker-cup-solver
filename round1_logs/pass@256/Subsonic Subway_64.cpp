
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

struct Station {
    double minTime, maxTime;
    int stationIndex;
};

bool compare(Station a, Station b) {
    return a.minTime < b.minTime;
}

bool isFeasible(double speed, int N, vector<int>& A, vector<int>& B) {
    vector<Station> stations(N);
    for (int i = 0; i < N; i++) {
        double timeToStation = 1.0 / speed;
        stations[i] = { timeToStation + A[i], timeToStation + B[i], i };
    }

    sort(stations.begin(), stations.end(), compare);

    double maxUntilNow = 0;
    for (int i = 0; i < N; i++) {
        if (stations[i].minTime > maxUntilNow) return false;
        maxUntilNow = max(maxUntilNow, stations[i].maxTime);
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }

        double lo = 0, hi = 1e6, mid;
        for (int i = 0; i < 100; i++) {
            mid = (lo + hi) / 2;
            if (isFeasible(mid, N, A, B))
                hi = mid;
            else
                lo = mid;
        }

        double result = (lo + hi) / 2;
        cout << "Case #" << t << ": " << setprecision(6) << result << endl;
    }
    return 0;
}
