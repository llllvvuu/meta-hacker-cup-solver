
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
#include <set>
#include <vector>

using namespace std;

const int MOD = 998244353;
struct TrieNode {
  int index;
  set<char> characters;
};

vector<TrieNode*> trie(1);

void insert(const string &s, int &nodeCount) {
  auto currentNode = &trie[0];
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '?') {
      currentNode->characters.insert(s[i]);
    } else {
      bool isNewNode = !currentNode->characters.count(s[i]);
      if (isNewNode) {
        currentNode->characters.insert(s[i]);
        auto newNode = new TrieNode{currentNode->index + 1, {}};
        trie.push_back(newNode);
        nodeCount++;
        if (currentNode->characters.size() > 1) {
          for (char c : currentNode->characters) {
            if (c != s[i]) {
              auto notFoundNode = new TrieNode{newNode->index, {c}};
              trie.push_back(notFoundNode);
              nodeCount++;
            }
          }
        }
      }
      currentNode = *find_if(trie.begin() + 1, trie.end(), 
        [&](TrieNode* tn) { return tn->characters == currentNode->characters; });
      if (currentNode->index != newNode->index) {
        currentNode->index = newNode->index;
      }
      if (isNewNode) {
        currentNode->characters.insert(s[i]);
      } 
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    int nodeCount = 1; // root node
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      insert(s, nodeCount);
      nodeCount %= MOD;
    }
    cout << nodeCount << endl;
  }
  return 0;
}
