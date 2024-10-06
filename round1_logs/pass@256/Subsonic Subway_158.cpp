
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

struct Delivery {
  int dist;
  int start;
  int end;
};

bool compareStart(const Delivery &d1, const Delivery &d2) {
  return d1.start < d2.start;
}

int findMinSpeed(const vector<Delivery>& deliveries) {
  vector<Delivery> filtered;
  for (auto& d : deliveries) {
    if (d.end > 0)
      filtered.push_back(d);
  }
  sort(filtered.begin(), filtered.end(), compareStart);
  double totalDist = 0;
  double totalTime = 0;
  for (int i = 0; i < filtered.size(); ++i) {
    double end = filtered[i].start + (double)filtered[i].dist / totalTime;
    if (end > filtered[i].end) return -1;
    totalDist += filtered[i].dist;
    totalTime = max(totalTime, (double)filtered[i].end);
  }
  if (totalTime == 0) return -1;
  return totalDist / totalTime;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    int N;
    cin >> N;
    vector<Delivery> deliveries(N);
    for (int j = 0; j < N; j++) {
      cin >> deliveries[j].start >> deliveries[j].end;
      deliveries[j].dist = j + 1;
    }
    double minSpeed = findMinSpeed(deliveries);
    printf("%.6f\n", minSpeed);
  }
  return 0;
}
