
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
using namespace std;

const int mod = 998244353;

struct Trie {
  Trie* children[26];
  Trie() {
    fill(children, children + 26, nullptr);
  }
  long long count = 0;
};

void add(Trie* root, string& s, int pos) {
  if (pos == s.length()) return;
  if (root->children[s[pos] - 'A'] == nullptr) {
    root->children[s[pos] - 'A'] = new Trie();
  }
  auto node = root->children[s[pos] - 'A'];
  node->count += 1;
  node->count %= mod;
  add(node, s, pos + 1);
}

int solution(vector<string>& patterns) {
  Trie* root = new Trie();
  for (int i = 0; i < patterns.size(); ++i) {
    string s = patterns[i];
    for (int j = 0; j < (1 << s.length()); j++) {
      string t;
      for (int k = 0; k < s.length(); ++k) {
        if (s[k] == '?' || (j & (1 << k)))
          t += s[k];
        else
          t += 'B'; // placeholder
      }
      add(root, t, 0);
    }
  }
  long long count = 0;
  function<Trie*, Trie*> dfs = [&](Trie*& node) -> Trie* {
    for (auto& child : node->children) {
      if (child != nullptr) child = dfs(child);
    }
    count += node->count;
    count %= mod;
    return node;
  };
  dfs(root);
  return count;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int N;
    cin >> N;
    vector<string> patterns(N);
    for (int j = 0; j < N; j++) {
      cin >> patterns[j];
    }
    cout << "Case #" << i << ": " << solution(patterns) << endl;
  }
  return 0;
}
