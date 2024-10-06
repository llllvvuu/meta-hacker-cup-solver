
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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

const int MAXT = 1e5;
const int MAXS = 110;
const int MAXN = 30;
const int MAXM = 1 << MAXN;
const int MAXA = 'Z' - 'A' + 1;
const vector<int> p = vector<int>(MAXS, 1);
vector<int> mask[MAXN], len[MAXN];
int node[MAXM], cnt[MAXM], dp[MAXN][MAXM];
string s[MAXT * MAXN];

int countTrieNodes(vector<string>& patterns) {
    int N = patterns.size();

    // Pre-allocate masks for each wildcard
    for (int i = 0; i < N; i++) {
        len[i].resize(patterns[i].size());
        mask[i].resize(1 << N, 0);
    }

    // Prefix Calculation for each wildcard
    for (int i = 0; i < N; i++) {
        int m = 1;
        for (int j = 0; j < patterns[i].size(); j++) {
            len[i][j] = m;
            m <<= 1;
        }
    }
  
    //Compute Starting Mask
    for (int i = 0; i < N; i++) {
        int m = 0;
        for (int j = 0; j < patterns[i].size(); j++) {
            if (patterns[i][j] == '?') {
                mask[i][m]++;
            } else {
                mask[i][m] = 1;
            }
            m = len[i][j];
        }
    }

    //DP Array Initialization
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) dp[i][0] = 1;

    //Recursive DP and DP Array Construction
    for (int m = 1; m < MAXM; m++) {
       for (int i = 0; i < N; i++) {
          if (mask[i][m]) dp[i][m] = cnt[m]; 
           else {
             for (int j = m; j; j -= j & -j) {
                 dp[i][m] += cnt[j];
                 dp[i][m] %= MOD;
             }
           }
           cnt[m] += dp[i][m];
           cnt[m] %= MOD;
       }
    }
       
    return cnt[MAXM - 1];
}

int main() {
  int TC;
  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) cin >> s[n];
   
    int id = (tc - 1) * N;
    for (int i = id; i < id + N; i++) {
      s[i] = "?" + s[i];
    }
   
    cout << "Case #" << tc << ": " << countTrieNodes({s[id], s[id + 1], ... , s[id + N - 1]}) << endl;
  }
  return 0;
}
