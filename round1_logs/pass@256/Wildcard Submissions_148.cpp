
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
#include <string>
using namespace std;

const int MOD = 998244353;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> freqs(101, 0); // Frequency of each prefix length from 0 to 100
    freqs[0] = 1; // Always one way to represent the empty string
    int maxLen = 0;
    for (int n = 0; n < N; n++) {
      string S;
      cin >> S;
      int current = 1;
      int qMarks = 0;
      for (auto s : S) {
        if (s == '?') {
          qMarks++;
        } else {
          freqs[current]++;
          current++;
        }
      }
      maxLen = max(maxLen, current);
      // multiply current frequencies by the number of ways to fill in the ?
      for (int i = qMarks; i >= 0; i--) {
        for (int j = current - 1; j >= 0; j--) {
          freqs[j + i] = (freqs[j + i] + (long long)freqs[j] * (__int128)pow(26, i) % MOD) % MOD;
        }
      }
    }
    int res = 0;
    for (int i = 1; i <= maxLen; i++) {
      res = (res + freqs[i]) % MOD;
    }
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
