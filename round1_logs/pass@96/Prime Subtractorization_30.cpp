
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

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long N;
    cin >> N;
    cout << "Case #" << t << ": ";
    if (N < 4) {
      cout << 0 << endl;
    } else {
      cout << N / 2 - 1 << endl;
    }
  }
  return 0;
}
