
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

int T, N;
vector<string> S; // Storing each wildcard string
vector<int> cnt;  // Count of paths for each prefix depth

// Depth-first search to insert wildcard string
void dfs(int depth, int mask) {
  if (depth == S[0].size()) {
    cnt[depth] += 1;
    return;
  }
  int mask2 = mask;
  mask2 *= 26;
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    if (S[mask][depth] == '?' || S[mask][depth] == ch) {
      cnt[depth] += (cnt[depth + 1] + 1) % MOD;
      dfs(depth + 1, mask2 + ch - 'A');
    }
  }
}

void insert_into_trie() {
  cnt.resize(51, 0);
  for (int j = 0; j < S.size(); j++) {
    dfs(0, j);
  }
}

int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> N;
    S.resize(N);
    for (int j = 0; j < N; j++) {
      cin >> S[j];
    }
    insert_into_trie();
    int result = cnt[0] % MOD;
    cout << "Case #" << i << ": " << result << endl;
  }
  return 0;
}
