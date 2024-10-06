
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
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

const double EPS = 1e-6;
const double MAX_SPEED = (double)1e6 + EPS;
const double INF = 1e15;

double find_min_speed(vector<pair<double, double>>& windows, int N) {
    if (windows.empty()) return 0.0;

    // Sort the windows in the starting time
    sort(windows.begin(), windows.end());
    
    // Find the latest arrival time and the earliest departure time for the whole trip.
    double T0 = windows[0].first, TN = windows[N - 1].second;
    
    if (T0 > TN) { // No solution if latest arrival is before earliest departure.
       return -1;
    } else {
        double speed_min = (double)1 / TN, speed_max = MAX_SPEED;
        while (speed_max - speed_min > EPS) {
            // Midpoint of the current search interval
            double V = 0.5 * (speed_max + speed_min);

            // Track current running state
            double T_current = 0;
            bool can = true;
            for (int i = 0; i < N; ++i) {
                double A = windows[i].first, B = windows[i].second;

                // We find the next stop time as the acceptable delay 
                double T_next = (T_current > A - static_cast<double>(i) / V) 
                            ? B - static_cast<double>(i+1) / V : 
                              A - static_cast<double>(i) / V;
                if (T_next <= T_current) {  // Impossibility of arrival within V
                    can = false;
                    break;
                }
                T_current = T_next;
            }
            if (can) {
                speed_max = V;
            } else {
                speed_min = V;
            }
        }
        return speed_max;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<double, double>> windows(N);
        for (int i = 0; i < N; ++i) {
            cin >> windows[i].first >> windows[i].second;
        }
        cout << "Case #" << t << ": " << fixed << find_min_speed(windows, N) << endl;
    }
    return 0;
}
