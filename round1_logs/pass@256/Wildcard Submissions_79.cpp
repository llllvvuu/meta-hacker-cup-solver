
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
#include <map>
#include <string>
using namespace std;

const int mod = 998244353;

struct Node {
  map<char, Node*> m;
};

Node root;

void insert(string s) {
  Node* curr = &root;
  for (char c: s) {
    if (!curr->m[c]) {
      curr->m[c] = new Node();
    }
    curr = curr->m[c];
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    map<int, int> node_count;
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;

      // count for exact matches
      insert(s);

      // count for wildcards
      for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (*it == '?') {
          for (char c = 'A'; c <= 'Z'; ++c) {
            string s1 = s.substr(0, it - s.begin());
            s1 += c;
            s1 += s.substr(it - s.begin() + 1);
            insert(s1);
          }
        } else {
          string s2 = s;
          s2[it - s.begin()] = '?';
          insert(s2);
        }
      }
    }

    int ans = 0;
    for (auto& p: node_count) {
      ans = (ans + p.second) % mod;
    }

    cout << "Case #" << t << ": " << ans << "\n";
  }
  return 0;
}
