
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

const int MAXN = 1000000 + 5;
const double EPS = 1E-6;
double a[MAXN], b[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> a[i] >> b[i];
    }
    // Perform a binary search on speed with precision
    double l = 0, r = N + 1;
    while (r - l > EPS) {
      double m = (l + r) / 2, u, v;
      for (int i = 1; i <= N; i++) {
        u = a[i] - i / m;
        v = max(b[i] - i / m, u);

        if (v < -EPS) { goto impossible; } // Delivery impossible at this m
      }
      r = m;
      continue; impossible: l = m;
    }
    cout << "Case #" << t << ": "; 
    cout << fixed << setprecision(6) << r << '\n';
  }
  return 0;
}
