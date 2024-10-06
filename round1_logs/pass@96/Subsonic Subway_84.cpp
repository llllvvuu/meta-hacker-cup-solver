
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
#include <algorithm> // for max and min
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000010;
int N;
vector<int> A[MAXN], B[MAXN];

double hasenlop(double speed) {
    double time_to_be_at_i = 0;
    for (int i = 1; i <= N; i++) {
        double arrival_min = max((double)i / speed, (double)A[i][0]);
        double arrival_max = min((double)(i + 1) / speed, (double)B[i][0]);
        if (arrival_min > arrival_max) {
            return false;
        }
        time_to_be_at_i = arrival_max;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i][0] >> B[i][0];
        }
        double eps = 1e-9;
        double lo = eps, hi = 1e9;
        for (int i = 0; i < 200; i++) {
            double mid = (lo + hi) / 2;
            if (hasenlop(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        printf("Case #%d: ", t + 1);
        if (lo < 1e-3) {
            cout << 0 << endl;
            continue;
        }
        printf("%.9f\n", lo);
    }
    return 0;
}
