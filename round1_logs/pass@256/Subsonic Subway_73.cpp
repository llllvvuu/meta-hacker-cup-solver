
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
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> Range;

bool cmp(const Range &x, const Range &y) {
  if (x.first == y.first) return x.second > y.second;
  return x.first < y.first;
}

double solve() {
  int N;
  cin >> N;
  vector<Range> ranges(N);
  for (int i = 0; i < N; i++) {
    cin >> ranges[i].first >> ranges[i].second;
    ranges[i].first = i + 1 - ranges[i].second;
    ranges[i].second = i + 1 - ranges[i].first;
  }
  sort(ranges.begin(), ranges.end(), cmp);

  int start = N + 1, end = -1;
  for (int i = 0; i < N; i++) {
    Range &curr = ranges[i];
    if (start <= curr.second)
      start = min(start, curr.first);
    else
      return -1;
    end = max(end, curr.second);
  }

  return (double)N / (end - start);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
