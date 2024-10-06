
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

struct Station {
    int dist;
    int early, late;
};

bool operator<(const Station& s1, const Station& s2) {
    // Favor later stations, but order by earliest delivery within station
    return (s1.dist != s2.dist) ? s1.dist > s2.dist : s1.early < s2.early;
}

double solve(int N, const vector<Station>& stations) {
    double min_dt{0}, max_dt{2*N};
    sort(stations.begin(), stations.end());
    for (const Station& st : stations) {
        const double dt1 = st.dist - st.late;
        const double dt2 = st.dist - st.early;
        if ((dt1 > max_dt) || (min_dt > dt2)) return -1;
        min_dt = max(min_dt, dt1);
        max_dt = min(max_dt, dt2);
    }
    return 1 / (max_dt - min_dt);
}

int main() {
  int T;
  cin >> T;
  vector<Station> stations;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    stations.resize(N);
    for (int i = 0; i < N; i++) {
        Station& st = stations[i];
        cin >> st.early >> st.late;
        st.dist = i + 1;
    }
    cout << "Case #" << t << ": " << solve(N, stations) << endl;
  }
  return 0;
}
