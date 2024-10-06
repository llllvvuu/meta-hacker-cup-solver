
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

const int64_t MOD = 998244353;
typedef array<int64_t, 2> Node; // (depth, count)
typedef unordered_map<string, Node> Trie;
typedef pair<Trie::iterator, bool /* was new element inserted */> MapResult;

Trie trie;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
      string S;
      cin >> S;
      int len = S.length();
      for (int i = 0; i < len; i++) {
        if (S[i] != '?') {
          string prefix = S.substr(0, i+1);
          MapResult result = trie.emplace(prefix, {i+1, 1});
          if (!result.second)
            result.first->second.second++; // Add to the count
        }
      }
    }

    int64_t numNodes = 0;
    vector<int64_t> pow26(len + 1);
    pow26[0] = 1;
    for (int i = 1; i <= len; i++)
      pow26[i] = (pow26[i-1] * 26) % MOD;

    // Starting from the deepest we start computing the number of nodes.
    for (auto &p: trie)
      for (int i = 0; i < p.second[0]; i++)
        numNodes = (numNodes + (p.second[1] * pow26[p.second[0] - i - 1]) % MOD) % MOD;
    cout << "Case #" << t << ": " << numNodes << endl;

    // Clear the trie and restart for next test case
    trie.clear();
  }
  return 0;
}
