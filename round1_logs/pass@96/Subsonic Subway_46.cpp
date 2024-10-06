
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
#include <cmath>
using namespace std;

vector<pair<double, double>> events;

// Finds the overlap and determines the speed
double findSpeed(int N) {
    int eventsIndex = 0; 
    double ansMin = 1e8, ansMax = -1;
    for (int i = 1; i <= N; ++i) {
        while (eventsIndex < 2 * N && events[eventsIndex].first == i) {  // Process events for the current i
            ansMax = max(ansMax, events[eventsIndex++].second);
            ansMin = min(ansMin, events[eventsIndex-2].second);
        }
        
        if (ansMin > ansMax) return -1;  // No overlap, exit as impossible
        if (i == N) break;  // Only process till last station
    }
    return ansMax;  // If overlapped, highest speed within overlapping range
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<int> B(N);
        for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
        events = vector<pair<double, double>>();
        for (int i = 0; i < N; ++i) {
            events.push_back({A[i], (double)B[i]/(i + 1)});
            events.push_back({B[i], (double)A[i+1]/(i + 2)});
        }
        sort(events.begin(), events.end());
        double speed = findSpeed(N);
        cout << "Case #" << t << ": " << fixed << setprecision(10) << speed << endl;
    }
}

