
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
#include <bitset>
#include <iostream>
using namespace std;

const int MOD = 998244353;
const int CHARSET = 26;
const int MAX_LEN = 100;
const int CHUNK_SIZE = 7; // sqrt(CHARSET) or so to minimize bitshifts
int Z[MAX_LEN + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    for (int i = 0; i <= MAX_LEN; i++) {
      Z[i] = 0;
    }
    for (int _ = 1; _ <= N; _++) {
      string s;
      cin >> s;
      int len = s.length();
      for (int p = 0; p <= len; p++) {
        // clean leftovers from previous string case
        for (int i = 0; i < CHARSET; i++) {
          Z[p] &= ~(1LL << i);
        }
        if (p == len) {
          // Reached the end of the current string
          break;
        }
        if (s[p] == '?') {
          for (int i = 0; i < CHARSET; i++) {
            Z[p + 1] |= Z[p] | (1LL << i);
          }
        } else {
          Z[p + 1] = Z[p] | (1LL << (s[p] - 'A'));
        }
      }
    }
    int64_t totalNodes = 1;
    for (int p = 1; p <= len; p++) {
      totalNodes = (totalNodes + __builtin_popcountll(Z[p])) % MOD;
    }
    cout << "Case #" << t << ": " << totalNodes << "\n";
  }
  return 0;
}
