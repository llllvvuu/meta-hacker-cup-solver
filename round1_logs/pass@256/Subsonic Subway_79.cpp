
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
#include <queue>
#include <vector>
using namespace std;

const double EPS = 1e-9;

struct stall {
    int i, j;
    stall(int i, int j): i(i), j(j) {}
    bool operator<(const stall &other) const {
        return j < other.j;
    }
};

double solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
    double mid = 0, lb = 0, ub = 1000000;
    
    while (ub - lb > EPS) {
        mid = (lb + ub) / 2;
        vector<stall> v;
        for (int i = 0; i < n; i++) {
            v.emplace_back(A[i] / mid, (B[i] - i) / mid);
        }
        sort(v.begin(), v.end());
        priority_queue<stall> pq;
        for (auto &s: v) {
            if (!pq.empty() && pq.top().j < s.i) pq.pop();
            pq.push(s);
        }
        if (pq.size() > 1) lb = mid;
        else ub = mid;
    }
    if (ub < 1e6) {
        return 1 / mid;
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int case_no = 1; case_no <= t; case_no++) {
        cout << "Case #" << case_no << ": " << setprecision(12) << solve() << endl;
    }
}
