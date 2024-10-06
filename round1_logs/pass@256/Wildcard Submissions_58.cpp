
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
#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;

// Trie node class
struct TrieNode {
  TrieNode* children[26];  // 26 English uppercase characters
  TrieNode() { memset(children, 0, sizeof(children)); }
  TrieNode* get(char c) { return children[c - 'A']; }
  void put(char c) { children[c - 'A'] = new TrieNode(); }
};

// Trie tree structure
struct TrieTree {
  TrieNode* root;
  TrieTree() { root = new TrieNode(); }

  // Insert wildcard string into trie
  void insert(string pattern) {
    int n = pattern.size(), i, j, total = 1;
    TrieNode* node = root;
    for (i = 0; i < n; i++) {
      node = (pattern[i] == '?' ? node : node->get(pattern[i]));      
      total = (total + 1) % MOD;
    }
  }

  // Recursive DFS node counting
  int dfs(TrieNode* node) {
    int res = 1;  // empty string
    for (int i = 0; i < 26; i++)
      if (node->children[i])
        res = (res + dfs(node->children[i])) % MOD;
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T; 
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> patterns(N);
    for(auto& s: patterns)
      cin >> s;
    
    TrieTree the_trie;
    for(auto& p: patterns) {
      the_trie.insert(p);
    }
    
    cout << "Case #" << t << ": " << the_trie.dfs(the_trie.root)-1 << endl;
  }
  return 0;
}
