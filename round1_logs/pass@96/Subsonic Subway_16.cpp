
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

void case_solve() {
  int N;
  cin >> N;
  vector<pair<long long, long long>> windows(N);
  for (int i = 0; i < N; i++) {
    cin >> windows[i].first >> windows[i].second;
  }
  long double l = 0, r = 1e9;
  for (int i = 0; i < 60; i++) {
    long double speed = (l + r) / 2;
    long long top = 0, reqStart = windows[0].second;
    bool valid = true;
    for (int j = 0; j < N; j++) {
      long long nextEnd = reqStart + (long long)(speed * windows[j].first - (top - reqStart));
      top = max(top, nextEnd);
      nextEnd = reqStart + (long long)(speed * windows[j].second - (top - reqStart));
      if (j == N - 1 && nextEnd >= windows[j].second || nextEnd < windows[j].first) {
        valid = false;
        break;
      }
      reqStart = nextEnd;
    }
    if (valid) r = speed;
    else l = speed;
  }
  cout << fixed << setprecision(9) << (l + r) / 2 << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    case_solve();
  }
}
