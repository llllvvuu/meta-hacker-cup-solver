
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

const double INF = (double)1e18;

int n;
pair<int, int> v[1000001];

double solve() {
    sort(v + 1, v + n + 1);  // Sort based on end times.
    double ans = -1.0;
    for (int i = 1; i < n; ++i) {
        double distance = i - v[i].first;
        double time_left = v[i].second - v[i + 1].first;
        if (distance * time_left <= 0) return -1;
        ans = max(ans, distance / time_left);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        double result = solve();
        cout << "Case #" << test_case << ": ";
        if (result == -1) {
            cout << result << endl;
        } else {
            cout << fixed << setprecision(8) << result << endl;
        }
    }
    return 0;
}
