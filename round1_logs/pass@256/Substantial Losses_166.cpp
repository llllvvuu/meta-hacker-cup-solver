
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
using namespace std;

const int mod = 998244353;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long W, G, L;
    cin >> W >> G >> L;

    long long delta = W - G;
    long long answer = 0;

    if (G + L < W) {
      cout << "Case #" << t << ": " << -1 << "\n";
    } else if (L == 0) {
      answer = (delta + 1) / 2;
    } else {
      // Ending condition (Case when L is non-zero)
      answer = delta * (delta + 1) / 2 / (L + 1);
      long long den = 1;
      for (int i = 0; i <= L; i++)
        den = den * (L + 1 - i) % mod * (L + 2 - i) % mod * (den + 1) % mod;
      den = mod + 1 - (den + 1) / 2;
      answer = answer * den % mod;
    }

    cout << "Case #" << t << ": " << answer << "\n";
  }
}
