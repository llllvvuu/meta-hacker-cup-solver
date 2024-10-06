
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

class DeliveryTime {
    public:
    double earliest, latest;

    DeliveryTime() : earliest(0), latest(0) {}

    DeliveryTime(double e, double l) : earliest(e), latest(l) {}

    bool operator<(const DeliveryTime &other) const {
        return latest < other.latest;
    }
};

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<DeliveryTime> delivery_times;
        while (N--) {
            int A, B;
            cin >> A >> B;
            delivery_times.emplace_back(
                max((double)0, (double)(1 - B)), 
                max((double)0, (double)(1 - A)));
        }
        sort(delivery_times.begin(), delivery_times.end());

        double latest = delivery_times[0].latest;
        double earliest = delivery_times.back().earliest;
        if (latest > earliest || latest < (double)0) {
            cout << "Case #" << t << ": -1" << endl;
            continue;
        }
        cout << "Case #" << t << ": " << 1 / latest << endl;
    }
    return 0;
}
