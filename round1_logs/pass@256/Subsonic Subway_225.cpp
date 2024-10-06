
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

const double EPS = 1e-9;

bool possible(const vector<pair<long long, long long>>& a, double v) {
  for (long long i = 0; i < a.size(); ++i) {
    long long t = (long long)(i / v);
    long long l = max(1LL, a[i].first - t);
    long long r = a[i].second - t;
    if (l > r) {
      return false;
    }
  }
  return true;
}

double binarySearch(const vector<pair<long long, long long>>& a) {
  double l = 0.0, r = 1e9+5;
  while (r - l >= EPS) {
    double mid = (l + r) / 2;
    if (possible(a, mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return r;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<long long, long long>> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    double result = binarySearch(a);
    cout << "Case #" << t << ": ";
    if (result > 1e9)
      cout << -1 << endl;
    else
      printf("%.6f\n", result);
  }
  return 0;
}
