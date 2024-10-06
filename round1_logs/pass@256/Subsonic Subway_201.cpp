
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

struct DeliveryDay {
    int start;
    int end;
    int distance;

    DeliveryDay(int s, int e, int d) : start(s), end(e), distance(d) { }
};

int N;
DeliveryDay deliveries[MAX_N];

// Check if it's possible to deliver all under maxSpeed.
// -1 indicates an invalid speed, due to not enough time
bool isPossible(double maxSpeed) {
    int time = 0;
    for (int i = 0; i < N; i++) {
        int startStation = int(ceil((double) deliveries[i].distance / maxSpeed));
        int endStation = int((double) deliveries[i].distance / maxSpeed);
        if (endStation < startStation) endStation = startStation;
        // Alternative strategy: using double for the new interval for more precision.
        double newStart = deliveries[i].start;
        double newEnd = deliveries[i].end;

        if (startStation > newEnd || endStation < newStart) return false;
        time += endStation - startStation;
        if (time > deliveries[i].end || startStation < deliveries[i].start) return false;
    }
    return true;
}

double solveCase() {
    sort(deliveries, deliveries + N, [](DeliveryDay a, DeliveryDay b) {
        return a.end - a.start > b.end - b.start;
    });
    double maxSpeed = 1e8;
    double minSpeed = 0.0;
    
    while (maxSpeed - minSpeed > 1e-9) {
        double mid = (minSpeed + maxSpeed) / 2;
        if (isPossible(mid)) maxSpeed = mid;
        else minSpeed = mid;
    }

    if (isPossible(minSpeed)) return minSpeed;
    return -1;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int start, end;
            cin >> start >> end;
            deliveries[i] = {start, end, i + 1};
        }

        cout << "Case #" << t << ": " << fixed << setprecision(9) << solveCase() << "\n";
    }
}
