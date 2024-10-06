
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
#include <unordered_set>
#include <vector>
using namespace std;

const int MOD = 998244353;

vector<string> inputs;
unordered_set<string> trackedNodes;
int n;

// Recursive insert 
long long insertHelper(long long index, string pattern, long long substarAux) {
  /**
  Recursively calculates the number of nodes caused by a certain pattern.
  */
  // If string is empty, return substarAux unchanged
  if (index >= pattern.length()) {
    return substarAux;
  }
  if (trackedNodes.find(pattern) != trackedNodes.end()) {
    // pattern already considered
    return substarAux * 1LL;
  }
  // If the current character is '?', replicate on substarAux
  long long o = pattern[index] == '?' ? substarAux * 26 : substarAux;
  trackedNodes.insert(pattern); // Costs enumeration
  return insertHelper(index + 1, pattern, o);
}

// Processing each test case
long long insertCase() {
  // Insert all wildcard strings
  long long result = 1;
  for (auto & pattern : inputs) {
    result = (result + insertHelper(0, pattern, 1)) % MOD;
  }
  // Reset variables for next test case
  trackedNodes.clear();
  inputs.clear();
  return result;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    inputs.resize(n);
    for (auto & pattern : inputs) {
      cin >> pattern;
    }
    cout << "Case #" << t << ": " << insertCase() << endl;
  }
  return 0;
}
