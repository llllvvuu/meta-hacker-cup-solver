
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
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  auto max_double = [](double a, double b) { return max(a, b); };

  int T;
  cin >> T;
  
  for (int t = 0; t < T; ++t) {
    int N;
    cin >> N;
    vector<double> windows(N);
    vector<double> limits;
    double min_val = 1.0e18;
    for (int i = 0; i < N; ++i) {
      int a, b;
      cin >> a >> b;
      windows[i] = b - a;
      min_val = min(min_val, (double)i / b);
      min_val = max(min_val, (double)(i + 1) / (a + 1));
      limits.push_back(i / windows[i]);
    }

    double result = min(min_val, *max_element(limits.begin(), limits.end()));
    cout << "Case #" << t + 1 << ": ";
    cout << setprecision(13) << fixed << result << '\n';
  }
  return 0;
}
