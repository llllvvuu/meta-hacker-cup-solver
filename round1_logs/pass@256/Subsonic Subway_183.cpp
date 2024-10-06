
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
#include <cstdio>
#include <vector>
using namespace std;

struct event_t { int t, delta; };
long long Vmax = 0;

vector<event_t> evs;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int N;
    scanf("%d", &N);
    evs.resize(2 * N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
      int A, B;
      scanf("%d %d", &A, &B);
      evs[2*i] = {A, 1};
      evs[2*i+1] = {B, -1};
    }
    sort(evs.begin(), evs.end());
    for (int i = 0; i < (int)evs.size(); i++) {
      sum += evs[i].delta;
      Vmax = max(Vmax, 1ll * (i + 1) * sum / evs[i].t);
    }
    long long answers = Vmax > 0 ? sum == 0 ? -1 : (double)Vmax : (double) 1e9;
    printf("Case #%d: %.10f\n", t, Vmax > 0 ? sum == 0 ? -1 : (double)Vmax : (double) 1e9);
  }
}
