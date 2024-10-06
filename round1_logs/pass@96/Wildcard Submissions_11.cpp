
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
using namespace std;

const int MOD = 998244353;

long long computeTrieNodes(const string &wildcard) {
  long long res = 1;
  long long multiplier = 26;

  for (char c : wildcard) {
    if (c != '?') {
      res = (res * multiplier + 1) % MOD;
      multiplier = (multiplier * 26) % MOD;
    } else {
      res = (res * multiplier) % MOD;
    }
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    long long totalNodes = 1; // Root node

    for (int i = 0; i < N; i++) {
      string wildcard;
      cin >> wildcard;
      long long nodes = computeTrieNodes(wildcard);
      // The total nodes in the trie is the sum of unique combinations modulo MOD
      totalNodes = (totalNodes + nodes - 1) % MOD; // Subtracting 1 to exclude the root node being counted twice
    }

    cout << "Case #" << t << ": " << totalNodes << endl;
  }
  return 0;
}
