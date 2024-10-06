
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
#include <string>
#include <vector>
#include <bitset>
using namespace std;

struct Node {
  node* child[26] = {};
};

void insert(string& s, node* root) {
  for (char c : s)
    if (!root->child[c - 'A']) root->child[c - 'A'] = new Node(), root = child;
    else root = root->child[c - 'A'];
}

int N, MOD = 998244353;
dp[52][64] = {};

void dfs(string& cur, int i = 0, int cnt = 26, node* root = &trie, int pos_bit = 0) {
  if (i == N) return;

  dp[cur[i] == '?' ? pos_bit : 1 << (cur[i] - 'A') | pos_bit | cnt] += dp[pos_bit] * (cur[i] == '?' ? 25 : 1);

  if (root->child[cur[i] - 'A'])      // if it exist
    dfs(cur, i + 1, cnt, root->child[cur[i] - 'A'], pos_bit);
  else if (cur[i] != '?')             // if it doesn't and cur[i] is a letter
    root->child[cur[i] - 'A'] = new Node();

  if (cur[i] == '?') dfs(cur, i + 1, cnt - 1, root, pos_bit);     // if it's a '?'
}

int solve() {
  cin >> N;
  node trie;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    insert(s, &trie);
  }
  for (int i = 0; i < N; i++) dfs(s[i]);
  return (int)dp[63];
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    dp[0][0] = 1;
    cout << "Case #" << t << ": " << solve() << '\n';
    dp[0] = {};
  }
  return 0;
}
