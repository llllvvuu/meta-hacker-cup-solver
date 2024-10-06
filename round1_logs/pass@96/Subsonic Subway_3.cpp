
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

const long double eps = 1e-6;
long long T, N, A[1000010], B[1000010];
pair<long double, long double> intervals[1000010];

int main() {
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    vector<pair<long long, long double>> times;
    for (int i = 0; i < N; i++) {
      cin >> A[i] >> B[i];
      intervals[i] = {1.0 * A[i] / i + eps, 1.0 * B[i] / (i + 1) - eps};
    }
    long double lo = 1e9;
    long double hi = -1e10;
    for (auto& p : intervals) {
      lo = min(lo, p.first);
      hi = max(hi, p.second);
    }
    if (lo > hi) cout << "Case #" << t << ": -1\n";
    else cout << "Case #" << t << ": " << setprecision(7) << (lo + hi) * 0.5
              << "\n";
  }
  return 0;
}
