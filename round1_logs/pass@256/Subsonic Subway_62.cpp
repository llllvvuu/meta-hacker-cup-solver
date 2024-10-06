
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
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const double EPS = 1e-9;

struct Vel {
  double l;
  double r;
  bool operator<(const Vel& other) const {
    return l < other.r;
  }
};

double solve() {
  int N;
  cin >> N;
  vector<Vel> vels;
  for (int i = 1; i <= N; i++) {
    int A, B;
    cin >> A >> B;
    vels.emplace_back((double)i / B, (double)i / A);
  }
  sort(vels.begin(), vels.end());
  double lastMax = -1e9;
  for (auto vel : vels) {
    if (vel.l > lastMax + EPS) return -1;
    lastMax = max(lastMax, vel.r);
  }
  return lastMax;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << fixed << setprecision(7) << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
