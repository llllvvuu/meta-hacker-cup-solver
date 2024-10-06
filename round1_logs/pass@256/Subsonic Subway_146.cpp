
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

const double EPS = 1e-9;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<double> L(N + 1), R(N + 1);
    for (int i = 1; i <= N; i++) {
      int A, B;
      cin >> A >> B;
      L[i] = 1.0 / B;
      R[i] = 1.0 / A;
    }

    double maxL = 0.0, minR = 1e9;
    double minSpeed = minR;

    for (int i = 1; i <= N; i++) {
      maxL = max(maxL, L[i]);
      minR = min(minR, R[i]);
      if (maxL > minR + EPS) {
        cout << "Case #" << t << ": -1\n";
        break;
      }
      if (i == N) {
        cout << "Case #" << t << ": " << 1 / minR << "\n";
      }
    }
  }
  return 0;
}
