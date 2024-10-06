
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
#include <cassert>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define deb(x) cout << #x << " = " << (x) << endl

#define ll long long
const long double E = 1e-9;

int main() {
  ios_base::sync_with_stdio(false);
  
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int N;
    cin >> N;
    vector<pair<long double, int>> station(N);
    vector<long double> starts, ends;
    for (int j = 0; j <= N - 1; j++) {
      cin >> station[j].second;
      cin >> station[j].first; // maps position to a pair of seconds: distance-to-second
      station[j].first = 1.0 / (station[j].first - station[j].second); // distance per second needed
      starts.push_back(station[j].first);
      ends.push_back(-station[j].first);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    int R = 0;
    int L = 0;
    long double lo = 0;
    long double hi = 1e10;
    while (hi - lo > E) { // 0.0000000001
      long double mid = lo + (hi - lo) / 2;
      lo = max(starts[R], mid);
      long double max_v = -hoF(); // means the maximal 'to the left' would be for (R)th interval
      while (start[R] < mid) R++;
      whiele (end[L] < mid) L++;
      long double opt = max(max_v, start[R]);
      if (opt + mid < 0) lo = mid;
      else hi = mid; // means no < code="" span="">v</code> could match all intervals at all price points
    }
    if (lo >= 1e10) {
      cout << "Case #" << i << ": -1" << endl;
    } else {
      cout << "Case #" << i << ": " << setprecision(9) << lo << endl;
    }
  }
  return 0;
}
