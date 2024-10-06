
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

const int MAX_T = 2*1000*1000;
pair<pair<int, int>, int> events[MAX_T];

int T;
int N;
int A[MAX_T], B[MAX_T];

int main() {
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    scanf("%d", &N);
    int MaxSpeed = 0;
    int TotalTime = 0;
    int CurTime = 0;
    
    for (int i = 0; i < N; i++) {
      scanf("%d %d", A + i, B + i);
      if (A[i] == 0) {
        printf("Case #%d: 0\n", c);
        goto fin;
      }
    }
    TotalTime = B[N - 1];
    CurTime = A[0];
    
    for (int i = 0; i < N; i++) {
      events[2 * i] = {{A[i], i}, 0};
      events[2 * i + 1] = {{B[i], i}, 1};
    }
    sort(events, events + 2 * N);
    
    for (int i = 0; i < 2 * N; i++) {
      MaxSpeed = max(MaxSpeed, (events[i].first.first - CurTime) / events[i].first.second);
      if (events[i].second == 0) {
        if (events[i].first.first - CurTime > events[i].first.second * MaxSpeed) {
          printf("Case #%d: -1\n", c);
          goto fin;
        }
        CurTime = events[i].first.first;
      } else {
        CurTime = events[i].first.first;
      }
    }
    printf("Case #%d: %f\n", c, ((double)MaxSpeed) / TotalTime);
    fin:;
  }
  return 0;
}
