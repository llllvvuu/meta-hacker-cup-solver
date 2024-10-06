
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

int T, N;
vector<pair<long long, long long>> schedules;

bool checkSpeed(long double v) {
  long double earliest = 0, latest = 0;
  bool fail = false;
  for (size_t i = 0; i < N; i++) {
    long long startDay = schedules[i].first, endDay = schedules[i].second;
    long long nextStartDay = i + 1 < N ? schedules[i + 1].first : 1e9;
    
    // If we are not ahead of the start window of this station
    // Adjust the latest arrival time considering the required in-and-out times.
    // Also check if the next station's opening time is before the latest arrival
    // time of the current segment.
    if (latest < startDay) {
      latest = max(max(earliest, startDay), (latest + 1 + v - (long long)v) / v);
    }
    
    if (latest > endDay && (i + 1 == N || latest > min(endDay, nextStartDay))) {
      fail = true;
      break;
    }
    
    if (i + 1 == N) continue;
    earliest = (latest + v + (long long)v - 1) / v + v;
    if (earliest > min(endDay, nextStartDay)) fail = true;
  }
  return !fail;
}

int main() {  
  cin >> T;
  for (int caseNo = 1; caseNo <= T; caseNo++) {
    cin >> N;
    schedules.clear();
    schedules.resize(N);
    for (int i = 0; i < N; i++)
      cin >> schedules[i].first >> schedules[i].second;
    
    long double low = 0, high = 1e9;
    for (int i = 0; i < 45; i++) {
      long double speed = (high + low) / 2;
      if (checkSpeed(speed)) high = speed;
      else low = speed;
    }
    
    if (high < 1e8)
      printf("Case #%d: %.9Lf\n", caseNo, high);
    else
      printf("Case #%d: %.9Lf\n", caseNo, -1.0);
  }
  return 0;
}
