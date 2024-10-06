
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
#include <unordered_set>
using namespace std;

const int MOD = 998244353;

struct Node {
  unordered_set<int> next;
  char ch;
};

void dfs(unordered_map<char, Node>& parent,
         unordered_map<char, unordered_map<char, Node>>& node, 
         int count) {
  for (auto& it : parent) {
    for (char next = 'A'; next <= 'Z'; ++next) {
      if (it.second.next.find(next) == it.second.next.end()) {
        node[it.second.ch][next] = {it.second.next, next};
        count = (count + 1) % MOD;
      }
    }
    for (auto& j : it.second.next) {
      dfs(node[it.second.ch], node[j.second.ch], count);
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    unordered_map<char, Node> root = {{'\0', {unordered_set<int>(), '\0'}}};
    for (int i = 0; i < N; i++) {
      string S; 
      cin >> S;
      unordered_map<char, unordered_map<char, Node>> node = root;
      for (char c : S) {
        if (c == '?') {
          Node myNode = root;
          for (char nextChar = 'A'; nextChar <= 'Z'; nextChar++) {
            if (myNode.next.find(nextChar) == myNode.next.end()) {
              root[nextChar] = {unordered_set<int>(), nextChar};
              myNode.next.insert(nextChar);
            }
          }
        } else {
          if (root[c].next.empty()) {
            root[c] = {unordered_set<int>(), c};
          }
          root = root[c].next;
        }
      }
    }
    int count = 1; // root node
    dfs(root, node, count);
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
