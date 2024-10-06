
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
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000000;
int memo[MAX_N + 1];

void preprocess() {
  memo[0] = 0;
  memo[1] = 0;
  memo[2] = 1;
  memo[3] = 2;
  memo[4] = 2;
  memo[5] = 2;
  memo[6] = 3;
  memo[7] = 4;
  memo[8] = 5;
  memo[9] = 6;
  // Fill from known counts
  for (int i = 10; i <= MAX_N; i++) {
    memo[i] = memo[i - 1];
    int j = 5;
    while (i >= j + j) {
      memo[i] = memo[i] + 1;
      j = j + 2;
    }
  }
}

int solve(int N) {
  assert(N <= MAX_N);
  return memo[N];
}

int main() {
  preprocess();
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  }
  return 0;
}
