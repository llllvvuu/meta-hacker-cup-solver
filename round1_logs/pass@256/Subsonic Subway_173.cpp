
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
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<double, double>> intervals(N);
        for (int i = 0; i < N; i++) {
            double A, B;
            cin >> A >> B;
            intervals[i] = {A, B};
        }
        
        double low = 0.0, high = 1000000.0, result = -1.0;
        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;
            double currTime = 0.0;
            for (int i = 0; i < N; i++) {
                double startTime = currTime, endTime = startTime + 1.0 / mid;
                if (intervals[i].first > endTime || intervals[i].second < startTime) {
                    result = -1.0;
                    break;
                }
                currTime = max(currTime + 1.0 / mid, intervals[i].first);
            }
            if (result == -1.0) {
                high = mid;
            } else {
                result = mid;
                low = mid;
            }
        }
        cout << "Case #" << t << ": " << fixed << setprecision(6) << result << endl;
    }
    return 0;
}
