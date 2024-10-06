
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
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double solve(vector<int>& a_start, vector<int>& a_end) {
    const int N = a_start.size();
    vector<pair<double, int>> mult(N << 1);
    for (size_t i = 0; i < N; i++) {
        mult[i] = {a_start[i] / double(i + 1), 1};
        mult[i + N] = {a_end[i] / double(i + 1), 2};
    }
    sort(mult.begin(), mult.end());
    int status = 3;
    for (size_t i = 0; i < N; i++) {
        status &= mult[i].second;
        if (status == 1) return mult[i].first;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int R;
        cin >> R;
        vector<int> a_start(R), a_end(R);
        for (int r = 0; r < R; r++) {
            cin >> a_start[r] >> a_end[r];
        }
        double ans = solve(a_start, a_end);
        cout << setprecision(6) << fixed << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
