
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

double l = 0, r = 1e6;
bool check(double speed, int N, vector<double> A, vector<double> B) {
  for (int i = 0; i < N; i++) {
    double ti = (i + 1) / speed;
    if (ti < A[i] || ti > B[i]) return false;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<double> A(N), B(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i] >> B[i];
      l = max(l, A[i] / (i + 1));
      r = min(r, B[i] / (i + 1));
    }
    double m;
    while (r - l > 1e-6) {
      m = (l + r) / 2;
      if (check(m, N, A, B)) l = m;
      else r = m;
    }
    m = (l + r) / 2;
    if (!check(m, N, A, B)) m = -1;

    cout << "Case #" << t << ": " << m << endl;
  }
  return 0;
}
