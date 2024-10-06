
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
#include <cstdio>
#include <vector>
using namespace std;

int N;
double lo[1000001], hi[1000001], L = -1, R = 1e6;

double eval(double speed) {
  auto [x, y] = minmax(lo[0], hi[N-1]);
  return min(x / speed, speed * y);
}

int main() {
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    scanf("%d", &N);
    auto get = [](double x, int i) { return x / i; };
    for(int i = 1; i <= N; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      lo[i] = get(a, i); 
      hi[i] = get(b, i);
    }
    // Process cumulative bounds.
    for(int i = 1; i <= N; i++) {
      lo[i] = max(lo[i-1], lo[i]);
      hi[i] = min(hi[i-1], hi[i]);
    }
    if(lo[N] > R || hi[N] < L) { // No overlap found in the entire range.
      puts("-1");
      continue;
    }
    R = lo[N];                   // Extend lower valid segment.
    L = hi[N];                   // And extend upper valid segment.
    // Binary search for intersection using the min of two cumulative functions.
    for(int i = 0; i < 200; i++) {
      double speed = (L + R) / 2;
      double res = eval(speed); // Evaluating if 'speed' is good.
      if(L + 1e-9 <= R) {
        printf("%.6f\n", res); 
        break;
      } else if(res >= speed) {
        L = speed;
      } else if(res <= speed) {            
        R = speed;
      }
    }
  }
  return 0;
}
