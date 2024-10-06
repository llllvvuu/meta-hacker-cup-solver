
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

const double eps = 1e-7;

double get_speed(vector<pair<double, double>> &windows) {
    double LB = 0, UB = 1e9; // very large UB
    double curr_speed = (LB + UB) / 2;

    for (auto [lb, ub] : windows) {
        double new_lb = lb * 1.0 / ub;
        if (new_lb > curr_speed)
            LB = new_lb + eps;
        else
            UB = lb * 1.0 / lb;
    }
    
    if (LB >= UB)
        return -1; // no feasible speed, UB < LB + epsilon meaning they could be so close to each other that it's impossible to find a feasible solution within the margin of floating point precision

    return LB;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<double, double>> windows(N);
        for (int i = 0; i < N; i++) {
            cin >> windows[i].second >> windows[i].first;
            windows[i].second -= windows[i].first;
            windows[i].second = 1.0 / windows[i].second; // Make it linear (lb, ub) to speed calculation.
            windows[i].first = 1.0 / windows[i].first;
        }

        cout << "Case #" << t << ": " << get_speed(windows) << "\n";
    }
    return 0;
}
