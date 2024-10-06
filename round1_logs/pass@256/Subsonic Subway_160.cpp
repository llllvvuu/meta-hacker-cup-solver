
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
#include <queue>
#include <vector>
using namespace std;

struct interval {
    double lb, ub;
    bool operator<(const interval &other) const {
        return ub < other.lb;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        vector<bool> use(2 * n);
        priority_queue<interval> pq;
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            use[j] = use[2 * n - 2 - j] = 1;
            pq.push({static_cast<double>(j + 1) / b, 1e9});
            pq.push({-static_cast<double>(j) / (a + 1), -1e9});
        }
        interval curr;
        curr.lb = 0;
        curr.ub = 1e9;
        while (!pq.empty()) {
            const auto &seg = pq.top();
            pq.pop();
            if (use[static_cast<int>(seg.lb)])
                continue;
            if (seg.ub > curr.lb) {
                curr.lb = seg.ub;
            }
            if (curr.lb > curr.ub)
                break;
            if (abs(curr.lb - curr.ub) < 1e-6) {
                printf("%.6f\n", 0.5 * (curr.lb + curr.ub));
                break;
            }
        }
        if (pq.empty() || curr.lb > curr.ub)
            cout << "-1\n";
    }
    return 0;
}
