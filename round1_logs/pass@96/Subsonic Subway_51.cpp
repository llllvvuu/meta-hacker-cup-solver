
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

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        int N;
        cin >> N;
        vector<pair<double, double>> intervals(N);
        for (int i = 1; i <= N; i++) {
            long long A, B;
            cin >> A >> B;
            intervals[i-1] = {static_cast<double>(i) / B, static_cast<double>(i) / A};
        }
        double L_max = -1e100, R_min = 1e100;
        for (const auto& [l, r] : intervals) {
            L_max = max(L_max, l);
            R_min = min(R_min, r);
        }
        cout << "Case #" << cas << ": ";
        printf("%.6f", L_max <= R_min ? L_max : -1);
        cout << endl;
    }
    return 0;
}
