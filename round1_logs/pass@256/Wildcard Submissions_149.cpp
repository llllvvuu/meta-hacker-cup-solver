
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
const int64_t kMod = 998244353;

struct Node {
  std::vector<Node*> children;
  explicit Node(int depth) : children(27), depth(depth) {}
  int depth;
  inline bool isTerminal() const { return depth == 0; }

  void add(int ch) {
    if (children[ch] == nullptr) {
      children[ch] = new Node(depth - 1);
    }
  }
};

int64_t dfsCount(Node* root) {
  int64_t result = 0;
  if (root->depth == 0 || root->children[0] != nullptr) {
    result++;
  }
  for (int childIdx = 1; childIdx < 27; childIdx++) {
    auto curChild = root->children[childIdx];
    if (curChild != nullptr) {
      result += dfsCount(curChild);
      result %= kMod;
    }
  }
  return result;
}

int main() {
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    std::cin >> N;
    Node* trieRoot = new Node(100);

    for (int i = 0; i < N; i++) {
      std::string S;
      std::cin >> S;
      Node* curNode = trieRoot;
      for (char ch : S) {
        if (ch == '?') {
          for (int j = 0; j < 26; ++j) {
            curNode->add(j);
          }
        } else {
          curNode->add(ch - 'A');
        }
        curNode = curNode->children[ch == '?' ? 0 : (ch - 'A') + 1];
      }
    }
    std::cout << "Case #" << t << ": " << dfsCount(trieRoot) << '\n';
  }
  return 0;
}
