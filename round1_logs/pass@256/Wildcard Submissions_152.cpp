
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
#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int MOD = 998244353;
const int ALPHABET_SIZE = 26;

struct Node {
  bool isLeaf;
  vector<int> children;
};

vector<Node> trie = {Node{true, vector<int>(ALPHABET_SIZE, -1)}};

void solve() {
  int N;
  cin >> N;
  vector<string> wildcards(N);
  for (int i = 0; i < N; i++) {
    cin >> wildcards[i];
  }

  auto dfs = [&](string& s, int pos, int* dp, int& result) -> void {
    if (pos == s.size()) {
      result = (result + dp[0]) % MOD; // End of string
      return;
    }

    if (s[pos] == '?') {
      for (int c = 0; c < ALPHABET_SIZE; ++c) {
        dfs(s, pos + 1, dp + ALPHABET_SIZE, (dp[c] + dp[ALPHABET_SIZE]) % MOD);
      }
    } else {
      dfs(s, pos + 1, dp + (s[pos] - 'A'), dp[pos]);
    }
  };

  int start_dp[ALPHABET_SIZE];
  int result = 1;
  for (int i = 0; i < N; i++) {
    fill(start_dp, start_dp + ALPHABET_SIZE, 1);
    dfs(wildcards[i], 0, start_dp, result);
  }
  cout << "Case #" << i + 1 << ": " << result << endl;
}

int main() {
  int T, i = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
