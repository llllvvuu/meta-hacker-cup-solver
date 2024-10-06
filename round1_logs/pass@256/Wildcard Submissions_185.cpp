
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

const int P = 998244353;

struct Node {
  int children[30] = {};
};

int power[101][30]; // given array B, power[i][j] = B^{i}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    // Initialize variables required
    vector<Node> trie(1, Node());
    
    // For each wildcard string
    for (int i = 0; i < N; i++) {
      string S;
      cin >> S;
      Node* cur = &trie[0]; // root
      for (char c: S) {
        if (c == '?') {
          int sum = 0;
          for (int i = 0; i < 26; i++) { // sum over all possible children
            if (c == '?' || c == 'A' + i) {
              int to = (c == '?' && cur->children[i] == 0);
              sum += (!to) + power[trie.size()][25];
              cur->children[i] = to;
              if (to) trie.push_back(Node());
            } else {
              sum += cur->children[i];
            }
          }
          // Apply answer modulo P
          cout << sum % P;
          return;
        }
        if (cur->children[c - 'A'] == 0) { // not yet seen
          cur->children[c - 'A'] = trie.size();
          trie.push_back(Node());
        }
        cur = &trie[cur->children[c - 'A']];
      }
    }
  }
  // Output answer
  cout << "Case #" << t << ": " << trie.size() % P << endl;
  return 0;
  return 0;
}
