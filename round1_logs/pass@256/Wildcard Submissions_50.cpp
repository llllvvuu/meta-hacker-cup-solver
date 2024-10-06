
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

using namespace std;
const int MOD = 998244353;

class TrieNode {
 public:
  TrieNode* children[26];  // Each character in the child nodes
  bool is_end;  // Flag indicating if a word ends here

  TrieNode() : is_end(false) {
    for (int i = 0; i < 26; i++) children[i] = NULL;
  }
};

class Trie {
 public:
  TrieNode* root;
  Trie() { root = new TrieNode(); }

  void insert(const string& str) {
    TrieNode* node = root;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '?') {
        for (int j = 0; j < 26; j++) {
          if (!node->children[j]) node->children[j] = new TrieNode();
          node = node->children[j];
        }
      } else {
        int c = str[i] - 'A';
        if (!node->children[c]) node->children[c] = new TrieNode();
        node = node->children[c];
      }
    }
  }

  int countNodes() {
    return dfs(root);
  }

 private:
  int dfs(TrieNode* node) {
    int res = 1;
    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        res = (res + dfs(node->children[i])) % MOD;
      }
    }
    return res;
  }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    Trie trie;
    for (int i = 0; i < N; i++) {
      string str;
      cin >> str;
      trie.insert(str);
    }
    cout << "Case #" << t << ": " << trie.countNodes() << endl;
  }
  return 0;
}
