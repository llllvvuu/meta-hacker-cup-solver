
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
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000;
struct Station {
    int arrival, departure;
    Station(int a, int d) : arrival(a), departure(d) {}
};

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        int arrival[MAX_N];
        int departure[MAX_N];
        for (int i = 0; i < N; i++) {
            cin >> arrival[i] >> departure[i];
        }
        
        long double lo = 0;
        long double hi = 2000000; 
        long double mid = (lo + hi) / 2;
        
        long double result = 0.0;
        for (int _ = 0; _ < 100; _++) {
            long double mid = (lo + hi) / 2;
            bool possible = true;
            int current_arrival = 0;
            for (int i = 1; i <= N; i++) {
                long double time_for_this_station = (i * 1.0) / mid;
                if (time_for_this_station < current_arrival) {
                    possible = false;
                    break;
                }
                current_arrival = max(current_arrival, arrival[i-1]);
                if (time_for_this_station > departure[i-1]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                result = mid;
                lo = mid;
            } else {
                hi = mid;
            }
        }

        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
