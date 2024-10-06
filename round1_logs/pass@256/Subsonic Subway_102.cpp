
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

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> L(N+1, 0), E(N+1, 1000000);
    bool is_feasible = true;
    for (int i = 1, a, b; i <= N; i++) {
      cin >> a >> b;
      L[i] = max(0, i - L[i - 1]);
      E[i] = min(1000000, i + E[i - 1]);
      if (L[i] > E[i - 1]) is_feasible = false;
    }
    double Lmax = max_element(L.begin(), L.end())[0];
    double Emin = *min_element(E.begin(), E.end());

    double min_speed;
    if (!is_feasible) min_speed = -1;
    else min_speed = Lmax > Emin ? -1 : N / max(Lmax, 0.0000000001);

    cout << "Case #" << t << ": " << min_speed << endl;
  }
  return 0;
}
