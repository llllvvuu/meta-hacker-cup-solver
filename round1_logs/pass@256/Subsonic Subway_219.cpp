
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
#include <climits>
using namespace std;

const double INF = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int N;
    cin >> N;
    vector<pair<int, int>> stations(N);
    for (int i = 0; i < N; i++) {
      cin >> stations[i].first;
      cin >> stations[i].second;
    }
    vector<double> M(N + 1, INF);
    for (int i = 0; i < N; i++) {
      double min_k = (double)(i) / M[i];
      for (int j = N - 1; j > i; j--) {
        min_k = min(min_k, (double)(j) / max(M[j - 1] - stations[i].first, M[j] - stations[i].second));
      }
      M[i] = min(M[i], stations[i].first / min_k);
      M[i + 1] = max(M[i + 1], stations[i].second / min_k);
    }
    if (M[N] == INF) {
      cout << "Case #" << tc << ": -1" << endl;
    } else {
      cout << "Case #" << tc << ": " << fixed << setprecision(6) << (1.0 / M[N]) << endl;
    }
  }
  return 0;
}
