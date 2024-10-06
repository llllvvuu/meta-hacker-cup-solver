
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
using namespace std;

struct Station {
    long long A;
    long long B;
    int idx;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Station> stations(N);
        for (auto& st : stations) {
            cin >> st.A >> st.B;
            st.idx = (int)(st.B);
        }

        // Sort by B (closing times)
        sort(stations.begin(), stations.end(), [](const Station& a, const Station& b) {
            return a.B < b.B;
        });

        long long l = -1;
        long long ub = stations[0].B;
        long long dist = 0;
        long double result = -1;
        for (int i = N - 1; i >= 0; i--) {
            // Find overlapping window, keeping UB of last overlap as possible max speed
            if (stations[i].A <= ub) {
                ub = min(ub, (long long) stations[i].A);
                ub = max(ub, (long long) stations[i].B);
                dist = stations[i].idx;
                continue;
            }
            // Safety check for case failure
            ub = min(ub, (long long) stations[i].A);
            ub = max(ub, (long long) stations[i].B);

            result = (long double) dist / (ub - l);
            break;
        }

        cout << fixed << setprecision(8) << "Case #" << t << ": " << result << "\n";
    }
    return 0;
}
