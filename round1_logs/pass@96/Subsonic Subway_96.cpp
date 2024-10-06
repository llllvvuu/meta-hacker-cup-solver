
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
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
int N;
const int PRECISION = 10;
double A[MAXN], B[MAXN];

double speedCHK(double sp) {
    double meTime = 1e10;
    for (int i = 1, j = 2; j <= N; ++i, ++j) {
        double eeTime = i + B[j-1] / sp;
        meTime = min(meTime, eeTime);
        double ntTime = j + A[j] / sp;
        if (meTime > ntTime) return -1; // False path
        meTime = max(meTime + 1, ntTime); // New best path
    }
    return 1; // All stations successfully reached 
}

int main() {
  int T; cin >> T; 
  for (int i = 1; i <= T; ++i) {
    cin >> N;
    for (int j = 1; j <= N; ++j) cin >> A[j] >> B[j];
    double l = 0, r = 1000000;
    for (int j = 0; j < 1e7 / PRECISION; ++j) {
        double m = (l + r) / 2;
        if (speedCHK(m) == -1) {
            l = m;
        } else {
            r = m;
        }
    }
    double eps = pow(10, -6);
    printf("Case #%d: %.7f\n", i, 1 + eps + (l + r) / 2);
  }
  return 0;
}
