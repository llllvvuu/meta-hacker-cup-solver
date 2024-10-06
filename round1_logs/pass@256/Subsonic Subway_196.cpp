
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

struct Interval {
    int station, A, B;
};

bool compareIntervals(const Interval& i1, const Interval& i2) {
    return i1.station < i2.station;
}

double solve(vector<Interval> intervals) {
    const int N = intervals.size();
    
    // Sort intervals by station numbers.
    sort(intervals.begin(), intervals.end(), compareIntervals);

    // Minimum possible speed, woo is the desired relative position.
    double start = 1e-9;
    const double end = 1e4;
    const double accuracy = 1e-9;

    double speed = (start + end) / 2;
    while(start < end){
        double mid = (start + end) / 2;
        int maxStation = -1;
        for(int i = 0; i < N; i++){
            double minArrivalTime = intervals[i].station * mid + intervals[i].A;
            double maxDepartureTime = intervals[i].station * mid + intervals[i].B;
            while(i < N-1 && minArrivalTime <= intervals[i+1].A){
                i++;
                maxDepartureTime = max(maxDepartureTime, intervals[i].station * mid + intervals[i].B);
            }
            if(i == N-1 && minArrivalTime <= intervals[i].A){
                maxStation = i;
            }
            else if(i == N-1){
                return -1;
            }
        }
        if(maxStation != -1){
            end = mid;
        }
        else{
            start = mid;
        }
    }

    return speed;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        vector<Interval> intervals(N);
        for(int i = 0; i < N; i++){
            cin >> intervals[i].A >> intervals[i].B;
            intervals[i].station = i;
        }
        double ans = solve(intervals);
        printf("Case #%d: %.9f\n", t, ans);
    }
    return 0;
}
