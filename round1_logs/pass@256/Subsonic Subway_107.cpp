
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
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double find_min_speed(vector<pair<int, double>>& points) {
    vector<pair<double, int>> evaluate;
    for (const auto& p : points) {
        evaluate.push_back({p.first / (double)p.second, 1});
        evaluate.push_back({p.first / (double)p.first, -1});
    }
    sort(evaluate.begin(), evaluate.end());

    int active = 0;
    double min_speed = -1;
    for (const auto& p : evaluate) {
        if (p.second == 1) active++;
        else active--;
        if (active == 1 && min_speed == -1) min_speed = p.first;
    }
    return min_speed;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<pair<int, double>> points(N);
        for (int i = 0; i < N; i++) {
            double A, B;
            cin >> A >> B;
            points[i] = {i + 1, B};
        }
        cout << "Case #" << t << ": ";
        double ans = find_min_speed(points);
        if (ans == -1) cout << "-1\n";
        else cout << fixed << setprecision(6) << ans << "\n";
    }
    return 0;
}
