
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
const int MOD = 998244353;
int N;
char S[105];
vector<char> pattern[105];

struct node {
  node* next[26];
  bool exists[26];
  int count;
  bool visited;
  
  node(): count(0), visited(false) {
    memset(next, 0, sizeof(next));
    memset(exists, false, sizeof(exists));
  }
};

node* root;

void dfs(node* current, int depth) {
  current->count++;
  if (depth >= N || !(pattern[depth][0] == '?')) {
    return;  // Done with this particular combination
  }
  for (int i = 0; i < 26; ++i) {
    if (!current->exists[i]) {  // Mark to note as exist, prevent redundant processing
      current->exists[i] = true;
      current->next[i] = new node();
    }
    if (!current->next[i]->visited) {
      current->next[i]->visited = true;
      dfs(current->next[i], depth + 1);
      current->next[i]->visited = false;
    }
  }
  current->visited = true;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    root = new node();
    for (int i = 0; i < N; ++i) {
      cin >> S;
      pattern[i].clear();
      for (int j = 0; S[j]; ++j) {
        pattern[i].push_back(S[j]);
      }
    }
    dfs(root, 0);
    cout << "Case #" << t << ": " << root->count << endl;
  }
}
