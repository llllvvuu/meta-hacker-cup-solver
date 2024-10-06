
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
#include <cstring>
using namespace std;

const int MOD = 998244353;

// Trie node
struct Node {
  Node *children[27]; // 26 letters + 1 for wildcard
  int count = 0;

  void addChild(char c) {
    if (c == '?') c = 26;
    int i = c - 'A';
    if (children[i] == nullptr) children[i] = new Node();
  }
};

void dfs(Node *root, int &nodes) {
  for (int i = 0; i < 27; i++) {
    if (root->children[i] != nullptr) {
      nodes += root->children[i]->count;
      dfs(root->children[i], nodes);
    }
  }
}

void processString(Node* root, const string &s, int index = 0) {
  if (index == s.size()) return;
  Node *current = root;
  int nodes = 1;
  for (int i = index; i < s.size(); i++) {
    char c = i == s.size() - 1 ? s[i] : (s[i] == '?' ? 26 : s[i] - 'A');
    if (current->children[c] == nullptr) {
      current->addChild(s[i]);
      current = current->children[c];
      nodes++;
    } else {
      current = current->children[c];
    }
  }
  root->count = (root->count + nodes) % MOD;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> wstrings(N);
    for (int i = 0; i < N; i++) cin >> wstrings[i];

    Node *root = new Node();
    for (auto &s: wstrings) processString(root, s);

    int nodes = 0;
    dfs(root, nodes);
    cout << "Case #" << t << ": " << (nodes + MOD) % MOD << endl;
  }
  return 0;
}
