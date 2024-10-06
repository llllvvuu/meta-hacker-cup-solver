
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

typedef double db; // Use double for precision

int main(){
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<pair<db, db>> req(N);
    for (auto &p : req) cin >> p.first >> p.second;

    // Within 10^-6:
    const db tol = 1e-6;

    // To handle edge cases:
    db maxa = 0, minb = 1e9;
    for (auto &p : req) {
      maxa = max(maxa, p.first / p.second); // max needs to be minimized
      minb = min(minb, p.second / p.first); // minn needs to be maximized
    }

    db res = max(maxa, minb);
    if(res < 1e-5) res = 0;
    cout << "Case #" << t << ": " << fixed << setprecision(7) << res << endl;
  }
  return 0;
}
