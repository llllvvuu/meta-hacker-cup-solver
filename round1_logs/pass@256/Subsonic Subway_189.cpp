
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
#include <numeric>
#include <cmath>
using namespace std;

bool can_deliver(const vector<long long> &times, long long n, double speed) {
    long long time = 0;
    for (int i = 1; i <= n; ++i) {
        time += i / speed;
        if (time < times[i - 1] || time > times[i]) {
            return false;
        }
    }
    return true;
}

double calculate_speed(const vector<long long> &times, long long n) {
    long double l = (long double)(times.back() + 1) * (long double)(n + 1), r = 1;
    for (long long i = 1; i <= n; ++i) {
        r = min(2LL * (long double)i / max(1LL, times[i - 1]), r);
    }
    while (r - l > 1e-10) {
        long double mid = (l + r) / 2;
        if (can_deliver(times, n, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long n;
        cin >> n;
        vector<long long> times(n);
        for (auto &time : times) {
            cin >> time;
        }
        cout << "Case #" << t << ": ";
        if (n == 1) {
            cout << fixed << setprecision(9) << (double)(n + 1) / times.back() << "\n";
        } else {
            cout << fixed << setprecision(9) << calculate_speed(times, n) << "\n";
        }
    }
}
