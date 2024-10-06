
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
#include <cstring>
#include <iostream>
using namespace std;

struct station {
  int A;
  int B;
  int dist;
};

bool check(const station* arr, int N, double speed) {
  int prev = -1;
  for (int i = 0; i < N; i++) {
    const station& s = arr[i];
    if (prev != -1 && (double)s.dist / speed - (double)prev > (double)s.A) {
      // Sonic arrives too early
      return false;
    }
    prev = max(prev, (int)(speed * s.dist + 0.5)); // Using ceil under the hood.
    if (prev > s.B) return false;
    prev = s.B;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    station *stns = new station[N];
    for (int i = 0; i < N; i++) {
      int A, B;
      cin >> A >> B;
      stns[i].A = A;
      stns[i].B = B;
      stns[i].dist = i + 1;
    }
    sort(stns, stns + N, [](const station& a, const station& b) {
      return a.A < b.A;
    });

    double low = 0, high = 1000001;
    while (high - low > 1e-6) {
      double mid = (low + high) / 2;
      if (check(stns, N, mid)) {
        high = mid;
      } else {
        low = mid;
      }
    }

    if (check(stns, N, low)) {
      printf("Case #%d: %.6f\n", t, low);
    } else {
      printf("Case #%d: -1\n", t);
    }

    delete[] stns;
  }
  return 0;
}
