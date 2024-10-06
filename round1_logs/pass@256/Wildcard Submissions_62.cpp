
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
#include <map>
using namespace std;

const int MOD = 998244353;

typedef vector<int> vi;

void insert(const string& s, map<int, map<char, int>>& trie) {
  for (auto c : s) {
    if (c == '?') {
      return; // wildcard paths are not specific
    }
    if (trie[0].count(c) == 0) {
      // new character to reach
      trie[0][c] = ++trie[0]['~'];
      trie[trie[0][c]] = map<char, int>(); // new nodes for future chars
    }                
    trie = trie[trie[0][c]];
  }
}

vi traverse_string(const string& s, map<int, map<char, int>>& trie) {
  int pruned = 0;
  vi kd = vi(101, 1); // represents number of valid ways this many steps have been taken
  for (auto c : s) {
    if (c == '?' || c == '~' || !trie[0].count(c)) { // new character in a wildcard or new node
      if (c == '?') { // create new nodes for all characters
        for (c = 'A'; c <= 'Z'; c++) {
          int id = trie[0][c];
          if (!trie[0][c]) { // initialize if first time
            trie[0][c] = ++trie[0]['~'];
            trie[trie[0][c]] = map<char, int>();
          }
          auto next = traverse_string(s, trie[trie[0][c]]);
          pruned += next[0] * (kd.back() - pruned);
          pruned %= MOD;
          for (int i = 0; i < next.size(); i++) {
            kd[i+1] += next[i];
            kd[i+1] %= MOD;
          }
        }
      }
      return kd;
    } else {
      int id = trie[0][c];
      pruned += kd.back() * (!flag && !trie[id][c]);
      pruned %= MOD;
      kd[1] = (kd[1] - pruned + MOD) % MOD;
      kd.assign(101, 0);
      trie = trie[id];
    }
  }
  return kd;
}

int main() {
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    map<int, map<char, int>> trie = {}; // root node
    int N;
    cin >> N;
    int total = 1; // root node always counts
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      auto kd = traverse_string(s, trie);
      for (int i = 0; i < kd.size(); i++) {
        total += (kd[i+1] - kd[i] + MOD) % MOD;
        total %= MOD;
      } // update total nodes count
    }
    cout << "Case #" << case_num << ": " << total << endl;
  }
  return 0;
}
