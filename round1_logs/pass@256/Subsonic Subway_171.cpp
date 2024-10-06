
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
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

bool feasible(ll v, const vector<ll>& A, const vector<ll>& B) {
  constexpr double EPS = 1e-8;
  double delta = 1 + EPS;

  for (ll i = 0; i < A.size(); ++i) {
    if ((A[i] > delta * i / v) || (B[i] < delta * i / v)) return false;
  }
  return true;
}

double solve(const vector<ll>& A, const vector<ll>& B) {
  ll min_by_A = 1e10;
  for (ll i = 0; i < A.size(); ++i) min_by_A = min(min_by_A, A[i]);
  // ll max_by_B = 1e10;
  double min_by_B = 1e18;
  for (ll i = 0; i < B.size(); ++i) min_by_B = min(min_by_B, i / double(B[i]));

  double left = 1e-10;
  double right = min(min_by_B, 1.0 * min_by_A);
  while (right - left > 1e-6) {
    double mid = (left + right) / 2;
    if (feasible(double(1) / mid, A, B)) right = mid;
    else left = mid;
  }
  return left;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (ll i = 0; i < N; ++i) cin >> A[i] >> B[i];

    cout << "Case #"
         << t
         << ": "
         << fixed << setprecision(6)
         << solve(A, B)
         << endl;
  }
}
