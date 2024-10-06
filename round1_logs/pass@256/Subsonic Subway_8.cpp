
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

using namespace std;

bool possible(int N, const vector<int>& A, const vector<int>& B, double v) {
    vector<pair<double, int>> events;
    for (int i = 0; i < N; i++) {
        events.push_back({(double)i / v, i});
        events.push_back({min((double)i / v, B[i]), i});
    }
    sort(events.begin(), events.end());
    
    int delivered = 0;
    for (auto [time, i] : events) {
        if (time <= A[i]) {
            delivered++;
            if (delivered == N) {
                return true;
            }
        }
    }
    return false;
}

double solve(int N, const vector<int>& A, const vector<int>& B) {
    double lo = 0, hi = (double)N / *min_element(B.begin(), B.end());
    for (int iter = 0; iter < 100; iter++) {
        double mid = (lo + hi) / 2;
        if (possible(N, A, B, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return lo == hi ? lo : -1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<int> B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }
        double ans = solve(N, A, B);
        cout << "Case #" << t << ": " << ans << endl;
    }
}
