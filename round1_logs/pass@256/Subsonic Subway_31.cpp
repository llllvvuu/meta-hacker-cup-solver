
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
#include <cmath>
#include <iostream>
using namespace std;

const double EPS = 1e-6;
const int MAXN = 1000001;

double T[2][MAXN], MINN[MAXN], MAXX[MAXN];

bool check(const double & v) {
  for (int j = 1; j <= MAXN; j++) 
    if (T[0][j] > v * j) return false;
  for (int j = 1; j <= MAXN; j++) 
    if (T[1][j] < v * j) return false;
  return true;
}

double solve(const int &N, const double A[], const double B[]) {
  for(int i = 0; i < N; i++)
    T[0][i + 1] = A[i], T[1][i + 1] = B[i];
  for(int j = 1; j <= N; j++)
    MINN[j] = max(MINN[j - 1], T[0][j] / j);
    MAXX[j] = min(MAXX[j - 1], T[1][j] / j);
  double minn = 0, maxx = MAXX[N];
  
  while(maxx - minn > EPS) {
    double mid = (minn + maxx) / 2;
    if (check(mid))
      maxx = mid;
    else
      minn = mid;
  }
  
  return check(minn) ? minn : -1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T, N;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> N;
    double A[N], B[N];
    for (int j = 0; j < N; j++) cin >> A[j] >> B[j];
    cout << "Case #" << i << ": " << solve(N, A, B) << "\n";
  }
  return 0;
}
