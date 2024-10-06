
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
#include <algorithm>
using namespace std;

double solve(vector<pair<int, int>>& intervals) {
  vector<pair<int, int>> criticalPoints = { { 0, 0 } };
  for (int i = 0; i < intervals.size(); i++) {
    int& leftCube = criticalPoints.back().second;
    auto [currentWindowStart, currentWindowEnd] = intervals[i];
  
    int openIntervalStart = max(leftCube, currentWindowStart);
    int openIntervalEnd = currentWindowEnd;

    int closeIntervalStart = currentWindowStart;
    int closeIntervalEnd = min(leftCube, currentWindowEnd);
    
    if (closeIntervalStart > closeIntervalEnd) return -1;
    
    criticalPoints.push_back({ openIntervalStart, openIntervalEnd });
    leftCube = closeIntervalEnd;
  }
  return 1.0 / (criticalPoints.back().second); 
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int, int>> intervals(N);
    for (auto& [A, B] : intervals) cin >> A >> B;
    cout << "Case #" << t << ": " << fixed << setprecision(10) << solve(intervals) << endl;
  }
  return 0;
}
