
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
using namespace std;

long double solve(int N, vector<pair<int, int>>& start) {
  if (N == 1) {
    return start[0].first / 1.0;
  } 

  vector<long double> upper(N + 1, 0);
  upper[1] = 1e18;

  for (int i = 0; i < N; i++) {
    int lower = start[i].first;
    int upper_bound_i = start[i].second;
    long double possible_speed = start[i].first / (double) (i + 1);
    if (upper_bound_i <= lower)
      return -1;
    if (possible_speed > upper[i]) {
      return -1;
    } else {
      upper[i + 1] = min(upper[i], (double) (upper_bound_i) / (i + 1)), upper_bound_i);
    }
  }
  return upper[N];
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    vector<pair<int, int>> start;
    cin >> N;
    start.resize(N);
    for (pair<int, int>& p : start) {
      cin >> p.first >> p.second;
    }
    cout << "Case #" << t << ": " << solve(N, start) << endl;
  }
  return 0;
}
