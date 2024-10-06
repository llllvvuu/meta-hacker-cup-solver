
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

const int MOD = 998244353;
const int MAXC = 26;
const int DLEN = MAXC + 1;

vector<int> dp(DLEN, 0);

void apply_mask(int* dp, int mask, bool prefix, int mul) {
    if (prefix) {
        for (int i = 0; i < DLEN; i++) {
            dp[i | mask] = (dp[i + mask] + dp[i]) * mul % MOD;
        }
    }
    else {
        for (int i = 0; i < DLEN; i++) {
            dp[i] = (dp[i] + dp[i | mask]) * mul % MOD;
        }
    }
}

int solve_case() {
    int N;
    cin >> N;
    dp[0] = 1;  // base case, trie root
    for (int q = 0; q < N; q++) {
        string s;
        cin >> s;
        const int L = s.size();
        
        for (int i = 0; i <= L; i++) {
            int m = 0;
            for (int j = L - i; j < L; j++) {
                if (s[j] != '?') {
                    m |= 1 << (s[j] - 'A');
                }
            }
            apply_mask(&dp[0], m, i < L, 1);
            apply_mask(&dp[0], m, i < L, 1);
        }
    }
    return dp[DLEN-1];
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve_case() << endl;
  }
  return 0;
}
