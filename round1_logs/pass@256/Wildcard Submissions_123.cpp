
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
#include <array>
#include <iostream>
#include <vector>

using namespace std;

long long ans[28] = {}, M = 998244353;
array<int, 26> chars = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                        'U', 'V', 'W', 'X', 'Y', 'Z'};
int T, N, ix, qr = 1;

int main() {
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    long long cur = 0, prev = 0;
    vector<array<int, 110>> inserts(N);

    for (int i = 0; i < N; i++) {
      cin >> inserts[i];
      for (int &char_pos : inserts[i]) {
        if (char_pos == 0)
          continue;
        for (int j = 0; j < char_pos; j++) {
          int ch = inserts[i][j] - 'A' + (inserts[i][j] != '?');
          cur |= 1LL << 27 - (ch + ix * 26);
        }
        ix += inserts[i][char_pos] != '?';
      }
    }

    for (int i = max(26 * (N - 1), 0); i < 28 * N; i++) {
      if (!(prev & (1LL << i))) {
        long long &from = ans[i];
        for (int j = i + 1; j < i + 27; j++)
          from += (ans[j] - (prev >> (26 - j + i)) + M) % M, from %= M;
        cur = (cur - prev + M) % M, cur %= M;
        prev = cur;
      }
    }

    cout << "Case #" << t << ": " << (cur - prev + M) % M << '\n';
  }
  return 0;
}
