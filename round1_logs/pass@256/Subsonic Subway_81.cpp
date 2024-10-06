
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

struct Delivery {
  int station;
  int arrival;
} D[1000001];

bool sortByWindow(Delivery& a, Delivery& b) {
  if (a.arrival == b.arrival) return a.station < b.station;
  return a.arrival < b.arrival;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    for (auto i = 0; i < N; i++) {
      cin >> D[i].arrival >> D[i].station;
      D[i].station = max(0, D[i].station - D[i].arrival);
    }
    sort(D, D + N, sortByWindow);
    bool ok = true;
    for (auto i = 0; i < N; i++) D[i].station = i;
    int last = -N;
    for (auto i = 0; i < N; i++) {
      auto end = D[i].station - D[i].arrival;
      if (last > D[i].station) {
        ok = false;
        break;
      }
      last = max(last, D[i].station - D[i].arrival);
    }
    if (ok) {
      cout << "Case #" << t << ": " << N / (last + N) << endl;
    } else {
      cout << "Case #" << t << ": -1" << endl;
    }
  }
}
