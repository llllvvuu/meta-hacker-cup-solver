
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
using namespace std;

const int mod = 998244353;
int T;
long long W, G, L;

int main() {
  cin >> T;
  for (int i = 0; i < (T); i++) {
    cin >> W >> G >> L;
    vector<long long> D(W - G + max(0ll, W - G - L) + 1);
    D[0] = 0;
    for (int j = 1; ; ) {
      int prev = (j - 1 + max(0ll, W - G - L)) % D.size();
      D[j % D.size()] =
          (2 * D[prev] + 2 - 2 * j % D.size() - ((j + G - max(0ll, W - G - L)) == W)) % mod;
      if (j % D.size() == 1) {
        cout << "Case #" << i + 1 << ": " << D[1] << endl;
        break;
      }
      j++;
    }
  }
  return 0;
}
