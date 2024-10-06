
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

struct Trie {
  vector<vector<int>> children;
  Trie() : children(1, vector<int>(26, 0)) {}

  void add(const string &pattern) {
    int currentNode = 0;
    for (char c : pattern) {
      if (c == '?') {
        for (int i = 0; i < 26; ++i) {
          int nextNode = children[currentNode][i];
          if (nextNode == 0) {
            nextNode = children.size();
            children.push_back(vector<int>(26, 0)); // 26 letters
          }
          children[currentNode][i] = nextNode;
        }
        break;
      }
      int nextNode = children[currentNode][c - 'A'];
      if (nextNode == 0) {
        nextNode = children.size();
        children.push_back(vector<int>(26, 0));
      }
      children[currentNode][c - 'A'] = nextNode;
      currentNode = nextNode;
    }
  }

  int countNodes() {
    int tot = 0;
    for (int i = 0; i < children.size(); ++i) {
      for (int j = 0; j < 26; ++j) {
        tot += children[i][j] != 0;
      }
    }
    return tot;
  }
};

int main() {
  int T; cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    int N; cin >> N;
    Trie trie;
    vector<string> patterns(N);
    for (int i = 0; i < N; ++i) {
      cin >> patterns[i];
      trie.add(patterns[i]);
    }
    cout << "Case #" << test_case << ": " << (trie.countNodes() + MOD - 1) % MOD << "\n";
  }
  return 0;
}
