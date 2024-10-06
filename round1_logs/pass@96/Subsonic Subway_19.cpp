
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
#include <algorithm> 

using namespace std;

int main() {
  int T; 
  cin >> T;
  for (int casenum = 1; casenum <= T; casenum++) {
    long long N;
    cin >> N;
    vector<long long> A(N), B(N);

    for (int i = 0; i < N; i++)
      cin >> A[i] >> B[i];

    double speed = 1e18;
    double time_after_start = 0.0;

    for (int i = N-1; i >= 0; i--) {
      if (time_after_start > B[i]) {
        cout << "Case #" << casenum << ": -1\n";
        speed = 0; break;
      }
      speed = min(speed, (double)1/(B[i] - time_after_start));
      time_after_start += speed;
    }
    if (speed != 0) cout << "Case #" << casenum << ":" << speed << endl;
  }
  return 0;
}
