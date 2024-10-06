
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
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
const double eps = 1e-6;

int main() {
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; t++) {
    std::cout << "Case #" << t << ": ";
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> intervals(N);
    for (int i = 0; i < N; i++)
      std::cin >> intervals[i].first >> intervals[i].second;
    // Binary search over speeds v:
    double l = 0, r = *std::max_element(intervals.begin(), intervals.end()) / 1.0;
    double m;
    while (r - l > 1e-9) {
      m = (l + r) / 2.0;
      bool ok = true;
      for (auto &[A, B] : intervals) {
        if (m * B < A || m * A > B) {
          ok = false;
          break;
        }
      }
      if (ok)
        r = m;
      else
        l = m;
    }
    std::cout << (l < 1e10 ? l : -1) << std::endl;
  }
  return 0;
}
