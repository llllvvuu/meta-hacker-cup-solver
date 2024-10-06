
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

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<pair<double, int>> speeds;
    for (int i = 0; i < N; i++) {
      cin >> A[i] >> B[i];
      speeds.push_back({(double)A[i] / (double)i, i});
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (A[0] && B.back() < N) {
      cout << "Case #" << t << ": -1\n";
      continue;
    }
    double min_g = (double)N / (double)B.back();
    cout << "Case #" << t << ": " << fixed << setprecision(10)
         << min({double(N) / (double)A.back(), min_g, 1}) << '\n';
  }
  return 0;
}
