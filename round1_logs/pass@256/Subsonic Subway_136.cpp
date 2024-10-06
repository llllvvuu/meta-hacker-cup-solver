
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

const int INF = 1e9;
double min_speed;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    vector<pair<double, double>> windows(N);
    for (int i = 0; i < N; i++) {
      cin >> windows[i].second >> windows[i].first;
    }
    sort(windows.begin(), windows.end());
    double lo = 0, hi = INF;
    while (hi - lo > 1e-8) {
      min_speed = (lo + hi) / 2;
      double arrival = 0;
      bool works = true;
      for (int i = 0; i < N; i++) {
        double arrival_time = i / min_speed;
        double lower = windows[i].first;
        double upper = windows[i].second;
        if (arrival_time < lower) {
          works = false;
          break;
        }
        arrival = upper;
      }
      if (works) {
        hi = min_speed;
      } else {
        lo = min_speed;
      }
    }
    cout << "Case #" << t + 1 << ": " << hi << endl;
  }
}
