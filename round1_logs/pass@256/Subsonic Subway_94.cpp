
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

double solve(int N) {
  double max_lower_bound = 0.0, min_upper_bound = 2e9;
  for (int i = 1; i <= N; i++) {
    double a, b;
    cin >> a >> b;
    max_lower_bound = max(max_lower_bound, i / a); 
    min_upper_bound = min(min_upper_bound, i / b); 
    if (max_lower_bound > min_upper_bound) 
      return -1; // impossible to find a constant speed
  }
  return max_lower_bound;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << fixed << setprecision(6) << solve(N) << endl;
  }
  return 0;
}
