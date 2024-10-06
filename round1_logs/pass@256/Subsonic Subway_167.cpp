
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
#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> station_times(1001000);

double get_min_velocity(const int max_station) {
  // Store the intervals
  for (int station = 0; station <= max_station; station++) {
    station_times[station] = {1e9 + 7, -1e9 - 1};
    long long a, b;
    cin >> a >> b;
    station_times[station] = {min(station_times[station].first, a + 1e-6), max(station_times[station].second, b - 1e-6)};
  }
  
  double lo = 0, hi = 1e6 + 10, mid;
  while (hi - lo > 1e-6) {
    mid = lo + (hi - lo) / 2;
    double rep_time = 1 / mid;
    
    for (int i = 0; i < max_station; i++) {
      int start = max(1, i + 1);
      int end = min(max_station, max_station - i + 1);
      bool ok = false;
      for (int j = start; j <= end; j++) {
        if (mid >= 1.0 / ((rep_time + (j - 1) * (1.0 / mid) - 1e-5) - (1.0 / mid))) {
          ok = true;
          break;
        }
      }
      if (!ok) break;
      if (i == max_station - 1 && ok) return mid;
    }

    if (ok) lo = mid;
    else hi = mid;
  }

  return hi;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector<string> output;
  int t;
  cin >> t;
  for (int casenum = 1; casenum <= t; casenum++) {
    output.push_back("Case #" + to_string(casenum) + ": ");
    int n;
    cin >> n;
    output.back() += (to_string(get_min_velocity(n)));
  }
  for (const string& case_ans : output) cout << case_ans << '\n';
}
