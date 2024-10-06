
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
#include <queue>
#include <limits>

using namespace std;

#define INF (int) limits::max()

struct Event {
    int time; 
    bool isStart; 

    bool operator< (const Event& other) const {
        if (time != other.time) return time < other.time;
        return isStart;
    }
};

double solve(int N, vector<int>& A, vector<int>& B) {
    vector<Event> events;
    for (int i = 1; i <= N; i++) {
        events.push_back({B[i - 1], true});
        events.push_back({A[i - 1], false});
    }
    sort(events.begin(), events.end());

    priority_queue<double, vector<double>, greater<double>> pq;
    double maxSpeed = 0, minSpeed = INF;
    for (auto e : events) {
        if (e.isStart) {
            maxSpeed = max(maxSpeed, (int)(1.0 * e.time / e.isStart ? A[e.time - 1] : B[e.time - 1]));
            minSpeed = min(minSpeed, (int)(1.0 * e.time / e.isStart ? A[e.time - 1] : B[e.time - 1]));
        } else {
            maxSpeed = max(maxSpeed, (int)(1.0 * e.time / e.isStart ? A[e.time - 1] : B[e.time - 1]));
            if (pq.empty()) {
                return -1;
            }
            if (pq.top() < minSpeed) {
                return -1;
            }
            pq.pop();
            minSpeed = e.time;
        }
        pq.push(e.time);
    }
    return (double)maxSpeed;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
        cout << "Case #" << t << ": " << fixed << setprecision(9) << solve(N, A, B) << endl;
    }
    return 0;
}
