
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
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

vector<pair<double,double>> stations;
int N;

double min_speed(double A, double B) {
  if (B < A) return -1; // Unfeasible
  return A;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    stations.resize(N);
    for (int i = 0; i < N; i++) {
      double A, B;
      cin >> A >> B;
      stations[i] = {A/(i+1), B/(i+1)};
    }
    sort(stations.begin(), stations.end());
    
    double max_valid_interval = -1;
    for (int i = 0; i < N; i++) {
      if (max_valid_interval < 0) { // first interval
        max_valid_interval = min_speed(stations[i].first, stations[i].second);
      } else {
        if (max_valid_interval > stations[i].second) { // no overlap
          max_valid_interval = -1;
          break;
        } else {
          max_valid_interval = min_speed(max_valid_interval, stations[i].second);
        }
      }
    }
    cout << "Case #" << t + 1 << ": ";
    (max_valid_interval < 0 ? -1 : max_valid_interval);
  }
}
