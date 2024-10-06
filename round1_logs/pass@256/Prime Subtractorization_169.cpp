
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
#include <cstring>
bool SEIVA[10000009];
int p[1000001], sz, N;
bool mark[1000009];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    sz = N * 11 / 10; // sufficiently large limit to count to.
    memset(SEIVA, true, sizeof(SEIVA));
    memset(p, 0, sizeof(p));
    memset(mark, false, sizeof(mark));
    int interval = (N + 1) / 2, cnt = -1;
    for (int i = 2; i <= N; i++) {
      if (SEIVA[i]) {
        p[++cnt] = i;
        if (i * 2 <= interval) {
          SEIVA[i * 2] = false; // Even numbers are not prime
          if (cnt >= 1) {
            int num = p[cnt] + p[cnt - 1];
            if (num <= interval) {
              if (mark[num]) mark[num] = false;
              else mark[num] = true;
            }
          }
        }
        for (int j = cnt; j > 0 && p[j] * i <= N; j--) {
          SEIVA[p[j] * i] = false;
          if (p[j] * i >= interval) break;
          if (cnt >= 2) {
            int num = p[j] + p[cnt - 1];
            if (num <= i * p[j]) mark[num] = false;
          }
        }
      }
    }
    int ans = N / 2 - 2 > 0;
    
    for (int i = 2; i < interval; i++) {
      if (mark[i]) ans--;
      else if (cnt >= 1) {
        int num = p[0] + i;
        if (num <= N) mark[num] = true;
        if (cnt >= 2) {
          int num = p[1] + i;
          if (num <= N) mark[num] = true;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
