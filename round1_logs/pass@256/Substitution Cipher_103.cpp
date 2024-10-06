
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
#include <algorithm>
#include <cmath>
using namespace std;

const int MOD = 998244353;

void dfs(string &s, vector<long long> &cnts, int pos) {
  if (pos >= s.size()) {
    // Finish - accumulation and update max count if reached end of string
  }
  if (s[pos] == '?') {
    // Backtracking - for each possible digit, recurse and keep max count
    for (int i = 0; i <= 9; i++) {
      s[pos] = '0' + i;
      dfs(s, cnts, pos + 1);
      s[pos] = '?';
    }
  } else if (cnts[pos + 1] < (s[pos] == '0' || stoi(s.substr(pos, 2)) > 26 ? 0 : cnts[pos])) {
    // DP update if current solution is promising based on digit properties
    cnts[pos + 1] = cnts[pos];
    dfs(s, cnts, pos + 1);
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string E;
    int K;
    cin >> E >> K;
    
    vector<long long> cnts(E.size() + 1, 0);
    cnts[0] = 1;
    dfs(E, cnts, 0);
    
    // Deduct candidates with Kth occurrence in string s
    vector<string> strs;
    
    string s = E;
    dfs(s, cnts, 0);  // Get all candidates
    for (auto &i : strs) if (is_valid(i)) s = min(s, i);  // O(N)
    
    cout << "Case #" << t << ": ";
    cout << s << " " << (cnts[E.size()] - 1 + MOD) % MOD << '\n';
  }
  return 0;
}
