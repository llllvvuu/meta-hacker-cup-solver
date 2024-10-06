
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
#include <queue>
#include <algorithm>
using namespace std;

const double EPS = 1e-6;

struct Comparison {
    bool operator()(const pair<int, double>& lhs, const pair<int, double>& rhs) {
        return lhs.second >= rhs.second;
    }
};

int T, N;
priority_queue<pair<int, double>, vector<pair<int, double>>, Comparison> q;

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        vector<pair<int, int>> events;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int ai, bi;
            cin >> ai >> bi;
            events.push_back({ai, bi});
        }
        sort(events.begin(), events.end());
        q.push({0, (int)2e9});
        for (auto &[ai, bi] : events) {
            while (!q.empty() && ai >= q.top().second) {
                q.pop();
            }
            if (q.empty()) {
                cout << "Case #" << t << ": -1" << endl;
                goto next_case;
            }
            double speed = (double) (q.top().first + 1) / ai;
            q.push({ai, max(bi, q.top().second)});
            
        }
        cout << "Case #" << t << ": " << fixed << setprecision(9) << (double) N / q.top().second << endl;
        q = {};
        next_case:;
    }
    return 0;
}
