
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
#include <vector>
#include <numeric>
using namespace std;
using LL = int64_t;
const int M = 998244353;

int main() {
  int T;
  cin >> T;
  
  for (int t = 1; t <= T; t++) {
    LL W, G, L;
    cin >> W >> G >> L;
    vector<LL> memo(W + L + 1, -1);

    function<LL(LL, LL)> f = [&](LL w, LL l) {
      if (w < G - l) return l;
      if (w <= G) return 0;
      
      LL& cache = memo[w];
      if (cache != -1) return cache;

      LL p = 1 - pow(1 - (2LL) / (l + 1LL), G - w + 1LL);
      LL val = 2LL + f(w - 1LL, l - (p == 1) * (l == 1)) + (p - 1) * f(w - 2LL, l - 1LL);
      cache = (val % M);
      return cache;
    };

    cout << "Case #" << t << ": " << f(W, L) << endl;
  }
  return 0;
}
