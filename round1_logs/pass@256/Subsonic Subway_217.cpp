
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

struct Station {
    int i, Ai, Bi;
};

bool sortByBi(const Station& a, const Station& b) {
    return a.Bi < b.Bi;
}

int solve(vector<Station>& stations) {
    const int N = stations.size();
    if (N == 1) return stations[0].i / (double)stations[0].Bi;
    
    sort(stations.begin(), stations.end(), sortByBi);

    double min_required_speed = 0;
    double current_speed = 2e9;
    for (int i = 0; i < N; i++) {
        double required_speed = (stations[i].i / (double)stations[i].Bi);
        if (required_speed > current_speed) return -1; // Infeasible
    
        current_speed = required_speed;
        min_required_speed = max(min_required_speed, required_speed);
    }
    return min_required_speed;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Station> stations(N);
        for (int i = 0; i < N; i++) {
            cin >> stations[i].Ai >> stations[i].Bi;
            stations[i].i = i + 1;
        }
        cout << "Case #" << t << ": " << setprecision(6) << solve(stations) << endl;
    }
    return 0;
}
