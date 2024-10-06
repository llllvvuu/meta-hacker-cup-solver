
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
#include <cmath>
using namespace std;

pair<long double, long double> stations[1000001];

long double findMinSpeed(long N, vector< pair<long long, pair<long long, long long>> >& data) {
  vector<pair<long double, long double>> intervals;
  for (long i = 0; i < N; i++) {
    intervals.push_back({data[i].second.first / static_cast<long double>(data[i].first),
                       data[i].second.second / static_cast<long double>(data[i].first)});
  }
  sort(intervals.begin(), intervals.end());

  long double minSpeed = intervals[0].second;
  long double maxSpeed = intervals[0].first;
  for (long i = 1; i < N; i++) {
    if (maxSpeed > intervals[i].second || minSpeed < intervals[i].first) {
      return -1;
    } else {
      maxSpeed = min(maxSpeed, intervals[i].first);
      minSpeed = max(minSpeed, intervals[i].second);
    }
  }
  return minSpeed;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<long long, pair<long long, long long>>> data(N);
    for (int i = 0; i < N; i++) {
      cin >> data[i].second.first >> data[i].second.second;
      data[i].first = i + 1;
    }

    double minSpeed = findMinSpeed(N, data);
    printf("Case #%d: %.12f\n", t, minSpeed);
  }
  return 0;
}
