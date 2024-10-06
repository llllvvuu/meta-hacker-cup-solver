
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

const double CANON = -1.0;

double solve() {
    int N;
    cin >> N;
    vector<pair<double, double>> ranges;
    ranges.reserve(N);
    for (int i = 1; i <= N; i++) {
        int A_i, B_i;
        cin >> A_i >> B_i;
        ranges.emplace_back((double)i / B_i, (double)i / A_i);
    }
    sort(ranges.begin(), ranges.end());
    for (int i = 1; i < N; i++) {
        if (ranges[i].first < ranges[i - 1].second) {
            return CANON;
        }
    }
    double ans = ranges[N - 1].first;
    for (int i = 0; i < N - 1; i++) {
        ans = min(ans, ranges[i].second);
    }
    return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
