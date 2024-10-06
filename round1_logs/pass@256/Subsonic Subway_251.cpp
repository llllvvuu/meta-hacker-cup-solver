
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

const double EPS = 1e-6; // availability for floating point constraints
const int MAX_B = 1000000;

double minConstSpeed(vector<int>& deliveryWindows, int N) {
    double l = 0, r = MAX_B;
    while (r - l > EPS) {
        double v = (l + r) / 2; // midpoint between l and r
        long long timeFinished = 0;
        for (int i = 1; i <= N; i++) {
            double timeToThis = i / v, mid = (timeToThis + timeFinished) / 2;
            int lo = lower_bound(deliveryWindows.begin() + (i - 1) * 2, deliveryWindows.begin() + (i) * 2, mid) - deliveryWindows.begin();
            if (lo % 2 == 0) // if in a window interval, fine
                continue;
            double delivEndTime = deliveryWindows[lo];
            if (mid < delivEndTime) {
                timeFinished = max(timeFinished, delivEndTime); // update latest time.
            } else { // not possible
                break;
            }
        }
        if (timeFinished > deliveryWindows.back()) // if successful, reduce search to left
            l = v;
        else
            r = v;
    }
    return l;
}

// drivers and convenience code around logic
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> deliveryWindows(2 * N);
        for (int i = 0; i < 2 * N; i++) {
            cin >> deliveryWindows[i];
        }
        cout << "Case #" << t << ": ";
        double answer = minConstSpeed(deliveryWindows, N);
        if (answer >= MAX_B) cout << "-1";
        else cout << fixed << setprecision(6) << answer << endl;
    }
    return 0;
}
