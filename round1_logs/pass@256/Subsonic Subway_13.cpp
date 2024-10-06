
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
#include <vector>
#include <iostream>
using namespace std;

struct Station {
    int i;
    double a;
    double b;
};

int T;
int N;
Station stations[1000001];

double max_min_interval(int l, int r) {
    if (l == r) return stations[l].a;
    int mid = (l + r) / 2;
    double left = max_min_interval(l, mid);
    double right = max_min_interval(mid + 1, r);
    return max(left, right);
}

double min_max_interval(int l, int r) {
    if (l == r) return stations[l].b;
    int mid = (l + r) / 2;
    double left = min_max_interval(l, mid);
    double right = min_max_interval(mid + 1, r);
    return min(left, right);
}

double find_min_speed() {
    double l = 0, r = 1e6, mid;
    int iters = 100;
    while (iters--) {
        mid = (l + r) / 2;
        bool is_valid = true;
        for (int i = 0; i < N; i++) {
            if (stations[i].i / mid < stations[i].a || stations[i].i / mid > stations[i].b) {
                is_valid = false;
                break;
            }
        }
        if (is_valid)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> stations[i].a >> stations[i].b;
            stations[i].i = i + 1;
        }
        double min_max = min_max_interval(0, N - 1);
        double max_min = max_min_interval(0, N - 1);

        double min_speed = max_min;
        double max_speed = min_max;
        if (min_speed > max_speed) {
            cout << "Case #" << t << ": " << -1 << endl;
            continue;
        }
        double final_speed = find_min_speed();

        cout << "Case #" << t << ": " << fixed << setprecision(9) << final_speed << endl;
    }
}
