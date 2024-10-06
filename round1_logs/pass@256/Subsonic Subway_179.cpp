
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
#include <bits/stdc++.h>
using namespace std;

double solve() {
  int N;
  cin >> N;
  vector<int> A(N), B(N), combinedB(N), combinedA(N);

  for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
  
  for (int i = 0; i < N; ++i) {
    B[i] = 1.0 / B[i];
    A[i] = 1.0 / A[i];
  }

  combinedB[0] = B[0];
  combinedA[1] = A[1];

  for (int i = 1; i < N; ++i) {
    combinedB[i] = max(combinedB[i-1], B[i]);
    combinedA[i] = min(combinedA[i-1], A[i]);
  }
  double high = B[0];
  double low = 0;

  // Check for intersection intervals, if no overlap, set the value to -1
  for (int i = 0; i < N; ++i) {
    if (A[i] > B[i-1]) {
      return -1;
    } else {
      low = max(low, A[i]);
      high = max(high, B[i]);
    }
  }
  return low;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << fixed << setprecision(6);  // Set precision for output
    auto v = solve();
    cout << "Case #" << t << ": ";
    if(v == -1) {
      cout << -1 << "\n";
    } else {
      cout << 1 / v << "\n";
    }
  }
  return 0;
}
