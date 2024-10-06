
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
#include <map>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const int mod = 998244353;

int n;

map<string, int> m;

void dfs(string s, int idx) {
  if (m[s] == 0) { // not seen yet
    m[s]++;
    if (idx < n) dfs(s+s[idx], idx+1);
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    m.clear();
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      dfs(s, 0);
    }
    ll numNodes = 0;
    for (auto [k, v] : m) {
      numNodes += v;
    }
    cout << "Case #" << t << ": " << (numNodes - 1 + mod) % mod << endl;
  }
  return 0;
}
