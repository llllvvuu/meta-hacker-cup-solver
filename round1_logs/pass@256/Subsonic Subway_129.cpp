
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
#include <cfloat>
#include <vector>
using namespace std;

bool canDeliver(const vector<vector<long long>>& times, vector<long double>& speedLimits, long double speed) {
    long long l = 0, r = 0;
    for (long long i = 1; i <= (long long)times.size(); ++i) {
        auto& timeRange = times[i - 1];
        auto earliest = l == 0 && r == 0 ? timeRange[0]: l;
        auto latest = r == 0 ? timeRange[1] : r;
        if (speed <= 0 || earliest > latest || i * speed > latest) {
            return false;
        }
        if (i * speed >= earliest && i * speed <= latest) {
            speedLimits[i] = speed;
        } else if (i * speed >= earliest) {
            speedLimits[r] = speed;
            l = i, r = i;
        } else {
            speedLimits[l] = speed;
            l = r = i;
        }
    }
    return true;
}

long double findMinimumSpeed(vector<vector<long long>>& times) {
    sort(times.begin(), times.end(), [](const vector<long long>& a, const vector<long long>& b) {
        return a[1] - a[0] < b[1] - b[0];
    });
    long double l = 0, r = 1e6;
    vector<long double> speedLimits(times.size() + 1, DBL_MAX);
    while (r - l > DBL_MIN) {
        auto midSpeed = (l + r) / 2.0;
        if (canDeliver(times, speedLimits, midSpeed)) {
            r = midSpeed;
        } else {
            l = midSpeed;
        }
    }
    return speedLimits.back();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<vector<long long>> times(N);
        for (long long i = 0; i < N; i++) {
            cin >> times[i][0] >> times[i][1];
        }
        auto result = findMinimumSpeed(times);
        cout << "Case #" << t << ":";
        if (result == DBL_MAX) {
            cout << " -1" << endl;
        } else {
            cout << " " << result << endl;
        }
    }
    return 0;
}
