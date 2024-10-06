
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

const double INF = (double)1e9 + 7;

double solve() {
    int N;
    cin >> N;
    vector<pair<double, double>> ranges;
    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A >> B;
        ranges.push_back({1.0 / B, 1.0 / A});
    }
    sort(ranges.begin(), ranges.end());

    double L = INF, H = -INF;
    for (auto [lb, ub] : ranges) {
        L = max(lb, H);
        H = min(ub, L);
        if (H < L) return -1;
    }
    return 1.0 / H;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: %.9f\n", t, solve());
    }
    return 0;
}
