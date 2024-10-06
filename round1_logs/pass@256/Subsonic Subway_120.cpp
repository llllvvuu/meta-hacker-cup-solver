
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

#define TLE 1e-9

void solve() {
  long long N;
  cin >> N;
  vector<vector<int>> stations(N);
  vector<double> percents;
  percents.reserve(2 * N);

  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    stations[i] = {A, B};
    percents.push_back((double)i / (double)A);
    percents.push_back((double)i / (double)B);
  }
  sort(percents.begin(), percents.end());

  if (percents.size() == 2 && percents[0] > percents[1]) {
    cout << "-1\n";
    return;
  }

  long long lo = 0, hi = 2 * N - 1;
  while (lo < hi) {
    long long mid = (lo + hi + 1) / 2;
    int L = -1, R = N;
    vector<double> lo_bound, hi_bound;

    for (int i = 0; i < N; i++) {
      double lo_val = (double)stations[i][0] / percents[mid];
      double hi_val = (double)stations[i][1] / percents[mid];
      lo_bound.push_back(lo_val);
      hi_bound.push_back(hi_val);
    }

    double A = percents[mid], B = percents[mid + 1];

    if (lo + 1 >= hi) lo++;

    // check if speed S within [A, B] fits the current bounds
    for (int i = 0; i < N; i++) {
      if (lo_val > B || hi_val < A) {
        lo++;
      }
    }
    if (lo >= hi) {
        cout << "-1\n";
      return;
    }
    if (lo_val <= B && hi_val >= A) {
      lo++;
    } else {
      hi--;
    }
  }
  cout << fixed << setprecision(10) << percents[lo] << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
