
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

const double INF = 2e9;

double A[2000010], B[2000010];

// Checks if a given speed allows all deliveries
bool isFeasible(double v) {
  double C = A[0];
  for (int i = 1; i <= N; i++) {
    double x = i / v;  // Time to reach station i at speed v
    C = max(C, A[i]);  // Latest time to deliver
    if (x < C && x > B[i])
      return false;  // If Sonic can't deliver within window
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);  

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    vector<double> endpoints;
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> A[i] >> B[i];
      endpoints.emplace_back(A[i]);
      endpoints.emplace_back(B[i]);
    }
    sort(endpoints.begin(), endpoints.end());
    const double lo = 0, hi = INF;
    while (hi - lo > 1e-6) {
      double mid = (lo + hi) / 2;
      if (isFeasible(mid))
        hi = mid;
      else
        lo = mid;
    }

    cout << "Case #" << t << ": ";
    if (lo > INF)
      cout << -1 << '\n';
    else
      cout << fixed << setprecision(6) << lo << '\n';
  }
  return 0;
}
