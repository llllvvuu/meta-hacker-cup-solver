
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

const double INF = 1e12; // Somewhat large value above all intervals

struct Delivery {
    int i;
    double Ai, Bi; // Expected delivery window
};

bool sortB(Delivery a, Delivery b) {
    return a.Bi < b.Bi;
}

double minSpeed(int N, vector<pair<double, double>> &A) {
    vector<Delivery> D;
    for (int i = 1; i <= N; ++i) {
        D.emplace_back(Delivery{i, A[i-1].first, A[i-1].second});
    }
    sort(D.begin(), D.end(), sortB); // Sort by delivery time window earliest end
    double amin = 0;
    double bmax = INF;
    for (int i = 0; i < N; ++i) {
        double d = i+1; // Distance (determined by station #)
        auto [prev_ai, prev_bi] = A[i];
        auto [curr_ai, curr_bi] = A[i+1];
        
        // Adjusting based on the previous delivery window and distance
        auto ai = max(prev_bi + d, curr_ai);
        auto bi = min(prev_bi + d, curr_bi);
        
        if (ai > bi) return -1.0;
        amin = max(amin, ai / d); // Current minimum speed needed
        bmax = min(bmax, bi / d); // Decrementing for feasible upper bound
        if (amin > bmax) return -1.0;
    }
    return (amin + bmax) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        vector<pair<double, double>> A;
        cin >> N;
        A.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].first >> A[i].second;
        }
        cout << "Case #" << t << ": " << minSpeed(N, A) << endl;
    }
    return 0;
}
