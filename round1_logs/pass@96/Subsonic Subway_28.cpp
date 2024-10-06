
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
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int64_t T;
int64_t N;

const int64_t INF = 179999999999999;

int64_t max_arr[1000005]{-1};

int64_t find_ans(int64_t A[], int64_t B[]) {
  double res = 1000000000001;
  const double EPS = 1e-9;
  double L, R;
  L = 0, R = INF;
  while (R - L > EPS) {
    double M = (L + R) / 2;
    max_arr[0] = 0;
    for (int i = 1; i <= N; i++) {
      max_arr[i] = max(max_arr[i - 1], A[i - 1]) + (i - 1) / M;
      if (max_arr[i] >= B[i - 1]) {
        L = M;
        break;
      }
    }
    for (int i = N; i >= 1; i--) {
      max_arr[i] = min(max_arr[i], max_arr[i + 1] + (N - i) / M);
      if (max_arr[i] <= A[i - 1]) {
        R = M;
        break;
      }
    }
    if (L < R) res = L;
  }
  res = min(L, R);
  return round(res * 10000000) / 10000000;
}

int main() {
  cin >> T;
  while (T--) {
    cin >> N;
    int64_t A[1000005], B[1000005];
    for (int i = 0; i < N; i++) {
      cin >> A[i] >> B[i];
    }
    int64_t ans = find_ans(A, B);
    if (ans > INF - 1000000) ans = -1;
    cout << "Case #" << (T + 1) << ": " << ans << '\n';
  }
}
