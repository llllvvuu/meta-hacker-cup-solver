
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
using namespace std;
const long double EPS = 1e-9;

bool OK(long double x, long long N, long long A[], long long B[]) {
  long double l = 0, h = 2e6 + EPS + EPS; // large constant is to ensure every case is covered
  while (h - l > EPS) {
    long double mid = (l + h) / 2;
    long long expected_pos = (N * mid - 1) / x + 1;

    if (expected_pos > N || mid < A[expected_pos] || B[expected_pos] < mid) {
      l = mid;
    } else {
      h = mid;
    }
  }
  return false;
}

int main(){
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    long long N; cin >> N; 
    long long A[N]; long long B[N];
    for (int i = 0; i < N; i++) {
      cin >> A[i] >> B[i];
    }
    int ans = -1;
    long long l = 0, h = 2e6 + 6;
    while(h - l > EPS) {
      long double mid = (l + h) / 2;
      if (OK(mid, N, A, B)) {
        l = mid;
      } else {
        h = mid;
        ans = mid;
      }
    }
    cout << "Case #" << t << ": " << fixed << setprecision(9) << ans << '\n';
  }
}
