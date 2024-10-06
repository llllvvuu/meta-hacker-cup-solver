
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

typedef pair<int,int> pii;
const int INF = 1e9+5, N = 1e6 + 5;

struct Comparator {
  bool operator()(pii &a, pii &b) {
    return a.second != b.second ? a.second < b.second : a.first > b.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector<pii> stations(N);
    for (int i = 0; i < N; i++) {
      cin >> stations[i].first >> stations[i].second;
    }
    sort(stations.begin(), stations.end(), Comparator());
    double maxSpeed = 1e6;
    double minSpeed = 0;
    double time = 0, position = 0;
    for (int i = 0; i < N; i++) {
      int left = max(0, stations[i].first - position);
      int right = stations[i].second * (position + 1) > time + 1 ? stations[i].second * (position + 1) : time + 1;
      double newTime = max(left, right);
      time = newTime;
      position++;
      maxSpeed = min(maxSpeed, (double)position / time);
    }
    cout << "Case #" << T + 1 << ": ";
    if (maxSpeed > 1000000) cout << "-1" << endl;
    else cout << fixed << setprecision(6) << maxSpeed << endl;
  }
  return 0;
}
