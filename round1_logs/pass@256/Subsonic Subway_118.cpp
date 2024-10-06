
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

double EPS = 1e-6;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<double, int>> events;
    for (int i = 1; i <= N; i++) {
      int Ai, Bi;
      cin >> Ai >> Bi;
      events.emplace_back(Ai / (double)i, -i); // arriving late
      events.emplace_back(Bi / (double)i, i);  // arriving in time
    }
    sort(events.begin(), events.end());
    double upper = -1.0; // first not met
    for (auto [time, index] : events) {
      if (index < 0) { // arriving late
        if (index > upper) {
          // contradiction, no valid speed can exist
          cout << "Case #" << t << ": -1\n";
          break;
        }
        upper = index;
      } else { // arriving in time
        bool full_coverage = true;
        for (int i = index; i - upper == 1; i++) {
          if (upper != i || i == N) {
            full_coverage = false;
            break;
          }
        }
        if (full_coverage) { // found a valid speed range
          cout << "Case #" << t << ": " << (upper * time + EPS) << "\n";
          break;
        }
        upper = index;
      }
    }
    if (events.back().second > 0 && full_coverage) { // check final interval
      cout << "Case #" << t << ": " << (upper * events.back().first + EPS) << "\n";
    }
  }
  return 0;
}
