
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
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double solve_single(vector<pair<int, int>>& pairs) {
    int n = pairs.size();
    assert(n > 0);

    // Using 'ceil' to handle rounding to the nearest whole number
    double max_speed = ceil((double)pairs.back().second / n);
    double speed = 0;

    while (speed < max_speed) {
        vector<long long> prev_possible(n + 1, -1);
        auto [prev_x, prev_y] = pairs[0];
        prev_possible[1] = prev_y;

        for (int i = 2; i <= n; ++i) {
            auto [x, y] = pairs[i - 1];
            double l = (double)x / i;
            double r = (double)prev_possible[i - 1] + (double)y - (double)x;
            speed = (l + r) / 2;

            prev_possible[i] = max(prev_possible[i], prev_y);
            if (speed * (i - 1) <= prev_y + x) {
                prev_possible[i] = max(prev_possible[i], y);
            } else {
                prev_possible[i] = max(prev_possible[i], prev_possible[i - 1] - (i - 1) * speed + x);
            }
        }

        if (prev_possible[n] >= double(n) * speed)
            return speed;
        else
            speed = (double)max_speed;
    }

    return speed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<pair<int, int>> pairs(n);
        for (int j = 0; j < n; j++) {
            cin >> pairs[j].first >> pairs[j].second;
        }
        sort(pairs.begin(), pairs.end());

        cout << "Case #" << i << ": " << fixed << setprecision(8) << solve_single(pairs) << '\n';
    }

    return 0;
}
