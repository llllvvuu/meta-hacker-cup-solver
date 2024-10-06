
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
#include<bits/stdc++.h>
using namespace std;

const int INF = 1000*1000*1000*1000; // denotes impossible journey
using Double = long double; 
// Use "long double" for better precision handling compared to "double" 

Double Calc(Double first, Double second) {
    if (first <= 0 && second <= 0) return INF; // impossible journey
    if (first > 0) return second / first; // valid journey, calculate the required speed
    return -second; // if unachievable, take negative of the exact time required
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        vector<pair<int, int>> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i].first >> A[i].second;
        }
        Double start = 0, end = INF, ans = INF; // initial boundaries for the binary search over speed

        // Transform coordinates so that we only need to carry roughly the average arrival time
        for(auto &t : A) {
            t.first -= t.second; // subtracting the second term to adjust for time difference
            start = min(start, Double(t.first)); // updating the minimum start time required
        }

        // Binary search for the critical speed that allows Sonic to reach every station within the respective window.
        for (int i = 0; i < 50; i++) {
            Double speed = (start + end) / 2; // Mid-point of the current search space
            Double last_arrival = A[0].first / speed; // Time when Sonic reaches the first station
            Double time = last_arrival;
            bool ok = true;
            for (int j = 0; j < N - 1 && ok; j++) {
                time += A[j + 1].first / speed; // Updating the arrival time for the subsequent station
                ok &= A[j].second <= A[j + 1].first / speed - last_arrival; // Ensuring the subsequent window opens before Sonic arrives
                last_arrival += A[j].second / speed; // Updating last_arrival time
            }
            if (ok) {
                ans = min(ans, speed); // Latest speed that works is our answer
                end = speed; // Solve for the faster speed
            } else {
                start = speed; // Solve for the slower speed
            }
        }
        
        cout << "Case #" << t << ": ";
        if (ans != INF) printf("%.10Lf\n", ans); // print answered speed with high precision
        else puts("-1"); // print -1 if not achievable
    }
    return 0;
}
